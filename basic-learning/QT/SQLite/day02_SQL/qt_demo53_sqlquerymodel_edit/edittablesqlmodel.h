#ifndef EDITTABLESQLMODEL_H
#define EDITTABLESQLMODEL_H
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QtDebug>

class editTableSqlModel : public QSqlQueryModel
{
public:
    explicit editTableSqlModel(QObject *parent = nullptr);

    //重写父类的虚函数
   //The model is read-only by default. To make it read-write,
   //you must subclass it and reimplement setData() and flags()
    virtual bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole);
    //得到View上条目的标志 index为条目的索引
   virtual Qt::ItemFlags flags(const QModelIndex &index) const;
private:
    //更新数据
    void refresh();

    //根据需求定义内部的字段相关的接口
    bool setUserName(int userId,const QString &userName);
};
#endif // EDITTABLESQLMODEL_H
