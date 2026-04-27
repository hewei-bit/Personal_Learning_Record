#ifndef DATABASE_TABLE_H
#define DATABASE_TABLE_H
#include <QString>

class Database_table
{
public:
    Database_table(QString nameTable,QString name,QString password)
        :nameTable(nameTable),name(name),password(password)
    {

    }
    QString getName() const
    {
        return name;
    }
    QString getPassword() const
    {
        return password;
    }
    QString getTableName() const
    {
        return nameTable;
    }





private:
    QString nameTable;
    QString name;
    QString password;


};






























#endif // DATABASE_TABLE_H
