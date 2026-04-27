#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "file_information.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_open_dir_clicked()
{
    //清除上次显示
     ui->listWidget->clear();
    //选择路径
    QString path = QDir::toNativeSeparators(QFileDialog::getExistingDirectory(this,tr("save path"),QDir::currentPath(),QFileDialog::DontUseNativeDialog));
    qDebug() << path;

    //显示路径
    ui->show_dirpath->setText(path);

    //显示路径下文件
    QDir dir(path);
//    QStringList nameFilters;
//    nameFilters << "*" ;
//    QStringList files = dir.entryList(nameFilters, QDir::Files|QDir::Readable, QDir::Name);
//    qDebug()<< files;

    //设置过滤器
    dir.setFilter(QDir::Files|QDir::NoDotAndDotDot|QDir::AllDirs);
    dir.setSorting(QDir::Size|QDir::DirsFirst);
    //
    QFileInfoList fileslist = dir.entryInfoList();
    qDebug()<< fileslist;

    for (int i=0;i<fileslist.size();i++) {
        QFileInfo fileinfo(fileslist.at(i));
        qDebug() << fileslist.at(i).suffix()  ;

        //创建条目
        file_information* fim = new file_information;
        QListWidgetItem* item = new QListWidgetItem();
        //设置条目的大小，最好跟Form是一样大
        item->setSizeHint(QSize(573,34));
        if(fileinfo.isDir())
        {
            fim->setDir(fileinfo.fileName());
//            ui->listWidget->setIconSize(QSize(30,30));
//            item->setIcon(QIcon(":/favicon.ico"));
//            connect(fim,&file_information::send_file_info,fim,&file_information::show_file_info_1);
//            emit fim->show_file_info_1(fileinfo);
        }
        if(fileinfo.isFile())
        {

            fim->setFile(fileinfo.fileName(),fileinfo.size());

//            ui->listWidget->setIconSize(QSize(30,30));
//            item->setIcon(QIcon(":/favicon (1).ico"));
//            connect(fim,&file_information::send_file_info,fim,&file_information::show_file_info);
//            emit fim->send_file_info(fileinfo);
        }
        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item,fim);

    }
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{

}

void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{
    qDebug() << "void MainWindow::on_listWidget_doubleClicked()";
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{

}
