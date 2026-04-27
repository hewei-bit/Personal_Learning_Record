#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
    class CalculatorForm;
} // namespace Ui

class Calculator : public QWidget
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = 0);

private slots:
    void digitClicked();

    void additiveOperatorClicked();
    void multiplicativeOperatorClicked();
    void equalClicked();
    void pointClicked();

    void backspaceClicked();

    void clearAll();


private:


    void abortOperation();
    bool calculate(double rightOperand, const QString &pendingOperator);
    double sumSoFar;

    double factorSoFar;

    QString pendingAdditiveOperator;

    QString pendingMultiplicativeOperator;

    bool waitingForOperand;

    Ui::CalculatorForm* ui;
};


#endif
