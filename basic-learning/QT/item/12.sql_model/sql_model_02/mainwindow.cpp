#include "mainwindow.h"
#include "ui_mainwindow.h"




bool runningTimer::opendatabase()
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("../sql_model_02/company.db");

    //[2] 打开数据库
    bool ok = database.open();
    if(!ok)
    {
        qDebug() << "open database failed"<< database.lastError();
    }
    return ok;
}

void runningTimer::insertdata()
{
    QSqlQuery query;
    //准备数据
    QStringList names;
    names << "五一一"<< "阿基"<<"阿露"<<"何蔚";
    QStringList addres;
    addres << "广东省广州市"<<"广东省佛山市"<< "广东省东莞市"<<"广东省江门市" ;
    //[2]提前准备好要的执行的sql，bool QSqlQuery::prepare(const QString &query)
    query.prepare("INSERT INTO stafflist(name,age,address,salary)"
                   " VALUES(?,?,?,?)");
    //[3] 使用bindValue来动态绑定占位符的值
    //void QSqlQuery::bindValue(const QString &placeholder,
    //const QVariant &val, QSql::ParamType paramType = QSql::In)
    foreach(QString name,names)
    {
        query.bindValue(0,name);
        query.bindValue(1,qrand()%65);
        query.bindValue(2,addres[qrand()%addres.length()]);
        query.bindValue(3,(qrand()%10000));
        //确认每天数据都依次写入数据库中
        if(!query.exec())
        {
            qDebug() << "insert failed";
        }

    }

    database.close();  //关闭操作库
}

void runningTimer::iscreateDatabaseTable()
{
    file.setFileName("../createTable.txt");
    if(file.open(QIODevice::ReadWrite))
    {
        QByteArray data = file.readAll();
        qDebug() <<data;
        isCreateTable = data.toUInt();
        qDebug()<<isCreateTable;
    }
    //是否要创建表
    if(!isCreateTable)
    {
        //创建表
         QString sqlTable = QString("CREATE TABLE COMPANY("
                                       "id INTEGER PRIMARY KEY AUTOINCREMENT  NOT NULL,"
                                       "name TEXT NOT NULL,"
                                       "age INT NOT NULL,"
                                       "address CHAR(50),"
                                       "salary REAL)");

         QSqlQuery query;

         if(!query.exec(sqlTable))
         {
             qDebug() << "create  table failed"<< database.lastError();
         }else {
             //写入一个值，代表表已创建好，以后不重要重新来创建
             file.write("1");

             file.close();

             qDebug() << "create  table scuess";
       }
    }
    else {
        qDebug() << "table exist";
    }
}

runningTimer::runningTimer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    opendatabase();

    iscreateDatabaseTable();

    //批量导入数据
    insertdata();

}

runningTimer::~runningTimer()
{
    delete ui;
}
