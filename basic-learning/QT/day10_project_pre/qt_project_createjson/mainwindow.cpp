#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "staff.h"
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
//#include <QFile>
#include <QMessageBox>
#include <QtDebug>
#include <QList>
//思路：将获取的数据通过数据模型来接受，在程序中，通过容器来动态存储（用来跟数据静态存储进行同步）
void MainWindow::createJsonData()
{
    QList<Staff*> staffList;
    //[1] 创建数据
    Staff* s1 = new Staff;
    s1->setAge("20");
    s1->setName("zhang3");
    s1->setMoney("10000");

    Staff* s2 = new Staff;
    s2->setAge("20");
    s2->setName("zhang3");
    s2->setMoney("10000");

    Staff* s3 = new Staff;
    s3->setAge("20");
    s3->setName("zhang3");
    s3->setMoney("10000");

    staffList.insert(0,s1);
    staffList.insert(1,s2);
    staffList.insert(2,s3);

    for (int i=0;i<staffList.size();i++) {
       Staff* ss =  staffList.at(i);
       qDebug() << ss->age() << ss->name() << ss->money();
    }
    //[2] 确定数据封装的格式：json
    /*
    {
        "staff":[
            {
                "name":"zhang3",
                "age":"20",
                "money":"10000"
            },
            {
                "name":"li4",
                "age":"21",
                "money":"11000"
            },
            {
                "name":"wang5",
                "age":"22",
                "money":"12000"
            }

        ]
    }
    在具体封装之前，要对数据的格式进行验证

    */
    //[3] 数据封装---从最里面往外进行打包
    //最里面为一个QJsonObject，创建一个对象
    QJsonObject obj1;
   obj1.insert("name",s1->name());
   obj1.insert("age",s1->age());
   obj1.insert("money",s1->money());

   QJsonObject obj2;
  obj2.insert("name",s2->name());
  obj2.insert("age",s2->age());
  obj2.insert("money",s2->money());

  QJsonObject obj3;
 obj3.insert("name",s3->name());
 obj3.insert("age",s3->age());
 obj3.insert("money",s3->money());

 QJsonArray array;
 array.insert(0,obj1);
 array.insert(1,obj2);
 array.insert(2,obj3);

 QJsonObject staffobj;
 staffobj.insert("staff",array);

 QJsonDocument doc;
 doc.setObject(staffobj);

 QByteArray data = doc.toJson(QJsonDocument::Compact);

 //最张将数据写入到一个JSON文件中
 QFile file;
 file.setFileName("./staff.json");

 bool ok = file.open(QIODevice::WriteOnly);
 if(ok)
 {
      file.write(data);
 }else {
    QMessageBox::information(this,"打开文件","打开文件失败，请重试");
 }
 file.close();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //初始 化界面
    setAttribute(Qt::WA_DeleteOnClose,true);

    //初始自定义的对话框
    dialog = new Dialog(this);

     isChange=false; // 表格中的内容初始化未改变
#if 1

    ui->staffTableWidget->setRowCount(0);
    ui->staffTableWidget->setColumnCount(2);

    QStringList list;
    list << "员工账号" << "员工密码";
    ui->staffTableWidget->setHorizontalHeaderLabels(list);
    ui->staffTableWidget->setColumnWidth(0,ui->staffTableWidget->width()/2-50);
    ui->staffTableWidget->setColumnWidth(1,ui->staffTableWidget->width()/2-50);
    ui->staffTableWidget->setEditTriggers(QAbstractItemView::DoubleClicked);

     connect(dialog,&Dialog::finish,this,&MainWindow::getNewMember);
#endif

    //读取员工信息
    accountFile.setFileName("./account.json");
    bool ok = accountFile.open(QIODevice::ReadOnly);
    if(ok)
    {
        QByteArray array =  accountFile.readAll();

        QJsonDocument doc = QJsonDocument::fromJson(array);
        QJsonObject object = doc.object();

        QJsonArray jsonarray = object.value("staff").toArray();
        for (int i=0;i<jsonarray.size();i++) {
            QJsonObject ss =  jsonarray.at(i).toObject();
            QString name = ss.value("name").toString();
            QString password =  ss.value("password").toString();
            qDebug() << name;
            qDebug() << password;
            //使用operator[]操作符来写入赋值到容器中
            account[name]=password; //将读取出来的数据写入到容器中
            //并将文件数据更新到UI组件上
            ui->staffTableWidget->setRowCount(ui->staffTableWidget->rowCount()+1);
            ui->staffTableWidget->setItem(ui->staffTableWidget->rowCount()-1,0,new QTableWidgetItem(name));
            ui->staffTableWidget->setItem(ui->staffTableWidget->rowCount()-1,1,new QTableWidgetItem(password));
            accountFile.close();
      }
    }

   // createJsonData();
}

void MainWindow::getNewMember(QStringList list)
{
    ui->staffTableWidget->setRowCount(ui->staffTableWidget->rowCount()+1);
    ui->staffTableWidget->setItem(ui->staffTableWidget->rowCount()-1,0,new QTableWidgetItem(list[0]));
    ui->staffTableWidget->setItem(ui->staffTableWidget->rowCount()-1,1,new QTableWidgetItem(list[1]));
    account[list[0]]=list[1];

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_getBtn_clicked()
{
    QFile file;
    file.setFileName("./staff.json");

    bool ok = file.open(QIODevice::ReadOnly);
    if(ok)
    {
         QByteArray array = file.readAll();

         QJsonDocument doc = QJsonDocument::fromJson(array);
         QJsonObject object = doc.object();

         QJsonArray jsonarray = object.value("staff").toArray();
         for (int i=0;i<jsonarray.size();i++) {
            QJsonObject ss =  jsonarray.at(i).toObject();
            qDebug() << ss.value("name").toString();
            qDebug() << ss.value("age").toString();
            qDebug() << ss.value("money").toString();
         }
    }

    file.close();
}

void MainWindow::on_addStaffBtn_clicked()
{
    dialog->exec();
}

void MainWindow::on_delStaffBtn_clicked()
{
    //从容器中将数据删除
    if( ui->staffTableWidget->currentItem()->column() == 0)
    {
        account.remove(ui->staffTableWidget->currentItem()->text());
    }else
    {
        // ui->staffTableWidget->item(ui->setupUi(,0)->text();
        account.remove( ui->staffTableWidget->item(ui->staffTableWidget->currentRow(),0)->text());
    }
    //从表格中删除选定的行
    ui->staffTableWidget->removeRow(ui->staffTableWidget->currentRow());
}

void MainWindow::on_backBtn_clicked()
{
    this->close();
}

void MainWindow::on_saveBtn_clicked()
{
    accountFile.setFileName("./account.json");
    bool ok =  accountFile.open(QIODevice::WriteOnly);
    static int i = 0;
    QJsonArray array;
    if(ok)
    {

        //获取容器的迭代器，该accountIterator迭代器指向当前的容器
        QMap<QString,QString>::iterator accountIterator =   account.begin();

        //使用迭代器来遍历容器
        while (accountIterator != account.end())
        {

            qDebug() << accountIterator.key() << ": " << accountIterator.value() ;

            QJsonObject obj1;
            obj1.insert("name",accountIterator.key());
            obj1.insert("password",accountIterator.value());

            array.insert(i,obj1);

            ++accountIterator;
            ++i;
        }

        QJsonObject staffobj;
        staffobj.insert("staff",array);

        QJsonDocument doc;
        doc.setObject(staffobj);

        QByteArray data = doc.toJson();

        accountFile.write(data);

        accountFile.close();
        i = 0;

    }

}

void MainWindow::on_staffTableWidget_itemChanged(QTableWidgetItem *item)
{
    if(!isChange) return;
    int row = item->row();
    int column = item->column();
    qDebug() << "row: "<<row<<"colmun"<<column;
    qDebug() << "text:"<<item->text();
    if(item->column()==0)
    {
        //如果是改变了账号，就删除原来的键值对，新建一个键值对
        account.remove(begin);
        account[item->text()]=ui->staffTableWidget->item(item->row(),1)->text();
    }
    else
    {
        //如果是密码改变了，就改变对应键的值
        account[ui->staffTableWidget->item(item->row(),0)->text()]=item->text();
    }
    isChange=false;
}

void MainWindow::on_staffTableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
    begin = item->text();
    isChange=true;
}
