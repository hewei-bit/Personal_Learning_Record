#ifndef STAFF_H
#define STAFF_H
#include <QString>

//根据需求定义数据模型

class Staff{
public:
    Staff();
    ~Staff();
    void setAge(const QString& age);
    QString age()const;
    void setName(const QString& name);
    QString name()const;
    void setMoney(const QString& money);
    QString money()const;
private:
    QString  m_age;
    QString m_name;
    QString m_money;
};
#endif // STAFF_H
