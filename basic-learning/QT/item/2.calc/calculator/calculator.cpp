
#include <QtWidgets>

#include <cmath>


#include "calculator.h"
#include "ui_calculator.h"
#include <QtDebug>

Calculator::Calculator(QWidget *parent)
    : QWidget(parent),
      ui(new Ui::CalculatorForm)
{
    ui->setupUi(this);

    sumSoFar = 0.0;
    factorSoFar = 0.0;
    waitingForOperand = true;

    this->setFixedSize(this->width(),this->height());
    this->setWindowTitle("Calculator");

    ui->display->setReadOnly(true);
    ui->display->setAlignment(Qt::AlignRight);
    ui->display->setMaxLength(15);

    QFont font = ui->display->font();
    font.setPointSize(font.pointSize() + 8);
    ui->display->setFont(font);



     ui->divisionButton->setText("\303\267");
     ui->timesButton->setText("\303\227");

     //数字按钮：0 1 2 3 4 5 6 7 8 9
     connect(ui->pushButton_0,&QPushButton::clicked,this,&Calculator::digitClicked);
     connect(ui->pushButton_1,&QPushButton::clicked,this,&Calculator::digitClicked);
     connect(ui->pushButton_2,&QPushButton::clicked,this,&Calculator::digitClicked);
     connect(ui->pushButton_3,&QPushButton::clicked,this,&Calculator::digitClicked);
     connect(ui->pushButton_4,&QPushButton::clicked,this,&Calculator::digitClicked);
     connect(ui->pushButton_5,&QPushButton::clicked,this,&Calculator::digitClicked);
     connect(ui->pushButton_6,&QPushButton::clicked,this,&Calculator::digitClicked);
     connect(ui->pushButton_7,&QPushButton::clicked,this,&Calculator::digitClicked);
     connect(ui->pushButton_9,&QPushButton::clicked,this,&Calculator::digitClicked);
     connect(ui->pushButton_8,&QPushButton::clicked,this,&Calculator::digitClicked);
     //+ - * /

     connect(ui->divisionButton,&QPushButton::clicked,this,&Calculator::multiplicativeOperatorClicked);

     connect(ui->timesButton,&QPushButton::clicked,this,&Calculator::multiplicativeOperatorClicked);

     connect(ui->plusButton,&QPushButton::clicked,this,&Calculator::additiveOperatorClicked);
     connect(ui->minusButton,&QPushButton::clicked,this,&Calculator::additiveOperatorClicked);
     //Backspace Clear

     connect(ui->backspaceButton,&QPushButton::clicked,this,&Calculator::backspaceClicked);

     connect(ui->clearAllButton,&QPushButton::clicked,this,&Calculator::clearAll);
     //=

     connect(ui->equalButton,&QPushButton::clicked,this,&Calculator::equalClicked);
     //.

     connect(ui->pointButton,&QPushButton::clicked,this,&Calculator::pointClicked);




}

void Calculator::digitClicked()
{

    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    int digitValue = clickedButton->text().toInt();
    if (ui->display->text() == "0" && digitValue == 0.0)
        return;

    if (waitingForOperand) {
        ui->display->clear();
        waitingForOperand = false;
    }
    ui->display->setText(ui->display->text() + QString::number(digitValue));

}



void Calculator::additiveOperatorClicked()
{

    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = ui->display->text().toDouble();


    if (!pendingMultiplicativeOperator.isEmpty()) {

        if (!calculate(operand, pendingMultiplicativeOperator)) {
            abortOperation();
            return;
        }
        ui->display->setText(QString::number(factorSoFar));
        operand = factorSoFar;
        factorSoFar = 0.0;
        pendingMultiplicativeOperator.clear();
    }


    if (!pendingAdditiveOperator.isEmpty()) {

        if (!calculate(operand, pendingAdditiveOperator)) {
            abortOperation();
            return;
        }
        ui->display->setText(QString::number(sumSoFar));
    } else {
        sumSoFar = operand;
    }


    pendingAdditiveOperator = clickedOperator;

    waitingForOperand = true;

}

void Calculator::multiplicativeOperatorClicked()
{

    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString clickedOperator = clickedButton->text();
    double operand = ui->display->text().toDouble();

    if (!pendingMultiplicativeOperator.isEmpty()) {
        if (!calculate(operand, pendingMultiplicativeOperator)) {
            abortOperation();
            return;
        }
        ui->display->setText(QString::number(factorSoFar));
    } else {
        factorSoFar = operand;
    }

    pendingMultiplicativeOperator = clickedOperator;
    waitingForOperand = true;

}

void Calculator::equalClicked()
{

    double operand = ui->display->text().toDouble();

    if (!pendingMultiplicativeOperator.isEmpty()) {
        if (!calculate(operand, pendingMultiplicativeOperator)) {
            abortOperation();
            return;
        }
        operand = factorSoFar;
        factorSoFar = 0.0;
        pendingMultiplicativeOperator.clear();
    }
    if (!pendingAdditiveOperator.isEmpty()) {
        if (!calculate(operand, pendingAdditiveOperator)) {
            abortOperation();
            return;
        }
        pendingAdditiveOperator.clear();
    } else {
        sumSoFar = operand;
    }

    ui->display->setText(QString::number(sumSoFar));
    sumSoFar = 0.0;
    waitingForOperand = true;

}
void Calculator::pointClicked()
{

    if (waitingForOperand)
        ui->display->setText("0");
    if (!ui->display->text().contains('.'))
        ui->display->setText(ui->display->text() + tr("."));
    waitingForOperand = false;

}

void Calculator::backspaceClicked()
{
    //qDebug() << "backspaceClicked";
    if (waitingForOperand)
        return;
    //qDebug() << "-----";
    QString text = ui->display->text();
    text.chop(1);
    if (text.isEmpty()) {
        text = "0";
        waitingForOperand = true;
    }
    ui->display->setText(text);

}

void Calculator::clearAll()
{
    sumSoFar = 0.0;
    factorSoFar = 0.0;
    pendingAdditiveOperator.clear();
    pendingMultiplicativeOperator.clear();
    ui->display->setText("0");
    waitingForOperand = true;
}

void Calculator::abortOperation()
{
    clearAll();
    ui->display->setText(tr("####"));
}

bool Calculator::calculate(double rightOperand, const QString &pendingOperator)
{

    if (pendingOperator == tr("+")) {
        sumSoFar += rightOperand;
    } else if (pendingOperator == tr("-")) {
        sumSoFar -= rightOperand;
    } else if (pendingOperator == tr("\303\227")) {
        factorSoFar *= rightOperand;
    } else if (pendingOperator == tr("\303\267")) {
        if (rightOperand == 0.0)
            return false;
        factorSoFar /= rightOperand;
    }

    return true;
}

