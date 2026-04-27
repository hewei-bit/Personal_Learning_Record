#ifndef FILE_INFORMATION_H
#define FILE_INFORMATION_H

#include <QMainWindow>
#include <QDir>
#include <QtDebug>
namespace Ui {
class file_information;
}

class file_information : public QMainWindow
{
    Q_OBJECT

public:
    explicit file_information(QWidget *parent = nullptr);
    void setDir(QString dirName);
    void setFile(QString fileName, qint64 fileSize);


    ~file_information();
signals:
    void send_file_info(QFileInfo fileinfo);
public slots:
    void show_file_info(QFileInfo fileinfo);
    void show_file_info_1(QFileInfo fileinfo);
private:
    Ui::file_information *ui;
};

#endif // FILE_INFORMATION_H
