#include "edittablesqlmodel.h"

editTableSqlModel::editTableSqlModel(QObject *parent)
{

}

bool editTableSqlModel::setData(const QModelIndex &index, const QVariant &value, int role)
{

    //根据表的列数，判断是否为有效列
    if(index.column() < 1 || index.column() > 2)
        return  false;

    //为了获取得到id
    QModelIndex prinmaryKeyIndex =
    QSqlQueryModel::index(index.row(),0);

    int id =
    data(prinmaryKeyIndex).toInt();

    //清除操作
    clear();
    qDebug() << "=====" << id << "=====" << index.column();

    bool ok;
    if(index.column() == 1)
    {
        //设置单元格上的内容
        ok = setUserName(id,value.toString());
    }
    refresh();

    return  ok;
}

Qt::ItemFlags editTableSqlModel::flags(const QModelIndex &index) const
{
    //获取当前条目的标志

   Qt::ItemFlags flags = QSqlQueryModel::flags(index);

   //根据自己表中的列数情况，设置对应列的标志
   if(index.column() == 1)
       flags |= Qt::ItemIsEditable; //给条目增加一个可编辑的标志

   return flags;
}

void editTableSqlModel::refresh()
{
      setQuery("select * from user");
      setHeaderData(1,Qt::Horizontal,QObject::tr("Name"));
}

bool editTableSqlModel::setUserName(int userId, const QString &userName)
{
    QSqlQuery query;
    query.prepare("update user set name = ? where id = ?");
    query.addBindValue(userName);
    query.addBindValue(userId);

    return  query.exec();
}
