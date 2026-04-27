#include "sreen_shot.h"
#include "ui_sreen_shot.h"



sreen_shot::sreen_shot(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sreen_shot)
{
    ui->setupUi(this);
}

sreen_shot::~sreen_shot()
{
    delete ui;
}

void sreen_shot::on_startbtn_clicked()
{
    if(ui->checkBox->isChecked())
    {
        qDebug() << "window hide";
        this->hide();
    }
    ui->startbtn->setDisabled(true);
    QTimer timer;
    timer.singleShot(ui->spinBox->value()*1000,this,&sreen_shot::shootScreen);

}

void sreen_shot::shootScreen()
{
    QScreen *sreen = QGuiApplication::primaryScreen();
    originalPixmap =  sreen->grabWindow(0);
    ui->sreenshot_label->setPixmap(originalPixmap.scaled(ui->sreenshot_label->size(),
                                               Qt::KeepAspectRatio,
                                               Qt::SmoothTransformation));
    ui->startbtn->setDisabled(false);
    if(ui->checkBox->isChecked())
    {
        qDebug() << "window show";
        this->show();
    }

}

void sreen_shot::on_save_btn_clicked()
{
    //初始化保存格式和路径
    const QString format = "png";
    QString initialPath = QStandardPaths::writableLocation(QStandardPaths::PicturesLocation);
    if (initialPath.isEmpty())
        initialPath = QDir::currentPath();
    initialPath += tr("/untitled.") + format;

    QFileDialog fileDialog(this, tr("Save As"), initialPath);
    fileDialog.setAcceptMode(QFileDialog::AcceptSave);
    fileDialog.setFileMode(QFileDialog::AnyFile);
    fileDialog.setDirectory(initialPath);

    QStringList mimeTypes;
    const QList<QByteArray> baMimeTypes = QImageWriter::supportedMimeTypes();
    for (const QByteArray &bf : baMimeTypes)
        mimeTypes.append(QLatin1String(bf));
    fileDialog.setMimeTypeFilters(mimeTypes);
    fileDialog.selectMimeTypeFilter("image/" + format);
    fileDialog.setDefaultSuffix(format);

    if (fileDialog.exec() != QDialog::Accepted)
        return;
    const QString fileName = fileDialog.selectedFiles().first();
    if (!originalPixmap.save(fileName)) {
        QMessageBox::warning(this, tr("Save Error"), tr("The image could not be saved to \"%1\".")
                             .arg(QDir::toNativeSeparators(fileName)));
    }
}

void sreen_shot::updateCheckBox()
{
    if (ui->spinBox->value() == 0) {
        ui->checkBox->setDisabled(true);
        ui->checkBox->setChecked(false);
    } else {
        ui->checkBox->setDisabled(false);
    }
}



void sreen_shot::on_exit_btn_clicked()
{
    this->close();
}

void sreen_shot::on_checkBox_stateChanged(int arg1)
{
 qDebug() << arg1;
}
