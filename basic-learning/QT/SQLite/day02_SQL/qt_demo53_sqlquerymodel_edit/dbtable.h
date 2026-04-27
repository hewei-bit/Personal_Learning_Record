#ifndef DBTABLE_H
#define DBTABLE_H
#include <QString>

class DbTale
{
public:
    DbTale(QString nameTable,QString name,QString password)
    {
        this->nameTable = nameTable;
        this->name = name;
        this->password = password;
    }
    QString getName()const
    {
        return name;
    }
    QString getPassword()const
    {
        return password;
    }
    QString getTableName()const
    {
        return nameTable;
    }
private:
    QString nameTable;
    QString name;
    QString password;
};
#endif // DBTABLE_H
