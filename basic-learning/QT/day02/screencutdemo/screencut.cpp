#include "screencut.h"
#include "ui_screencut.h"

ScreenCut::ScreenCut(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScreenCut)
{

    ui->setupUi(this);
    shootScreen();

    setWindowTitle(tr("Screenshot"));
    resize(this->width(), this->height());
    ui->delaySpinBox->setSuffix(tr("s"));
    ui->delaySpinBox->setMaximum(60);

    //建立信号与槽
    connect(ui->newScreenshotButton, &QPushButton::clicked, this, &ScreenCut::newScreenshot);

    connect(ui->saveScreenshotButton, &QPushButton::clicked, this, &ScreenCut::saveScreenshot);


    ui->quitScreenshotButton->setShortcut(Qt::CTRL + Qt::Key_Q);
    connect(ui->quitScreenshotButton, &QPushButton::clicked, this, &QWidget::close);
}
void ScreenCut::newScreenshot()
{
    if (ui->hideThisWindowCheckBox->isChecked())
        hide();
    ui->newScreenshotButton->setDisabled(true);

    QTimer::singleShot(ui->delaySpinBox->value() * 1000, this, &ScreenCut::shootScreen);
}

void ScreenCut::saveScreenshot()
{
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
void ScreenCut::shootScreen()
{
    QScreen *screen = QGuiApplication::primaryScreen();
    if (const QWindow *window = windowHandle())
        screen = window->screen();
    if (!screen)
        return;

    if (ui->delaySpinBox->value() != 0)
        QApplication::beep();

    originalPixmap = screen->grabWindow(0);
    updateScreenshotLabel();

    ui->newScreenshotButton->setDisabled(false);
    if (ui->hideThisWindowCheckBox->isChecked())
        show();
}

void ScreenCut::updateCheckBox()
{
    if (ui->delaySpinBox->value() == 0) {

        ui->hideThisWindowCheckBox->setDisabled(true);
        ui->hideThisWindowCheckBox->setChecked(false);
    } else {
        ui->hideThisWindowCheckBox->setDisabled(false);
    }
}

void ScreenCut::updateScreenshotLabel()
{
    ui->screenshotLabel->setPixmap(originalPixmap.scaled(ui->screenshotLabel->size(),
                                                     Qt::KeepAspectRatio,
                                                     Qt::SmoothTransformation));
}
ScreenCut::~ScreenCut()
{
    delete ui;
}
