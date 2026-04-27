#include "technician.h"
#include "salemanger.h"
#include "saleman.h"
#include "manager.h"

int main()
{
#if 1

        Technician t;
        t.init();
        t.promote();
        t.calcSalary();
        t.showInfo();

       //Empleyee e; // error 抽象类不能实例化
        Empleyee* p; //ok 声明该类型的指针，并没有实例化对象
        Empleyee &rt = t; //ok 声明该类型跟已有类型的关系，并不没有实例化对象
        rt.showInfo();
#endif
#if 0
    //创建公司的员工：技术人员，经理，销售人员，销售经理
    Empleyee *e[ ] = {new Technician,new SaleMan,
                      new SaleManager,new Manager
                     };
    for (int i=0;i<4;i++) {
        e[i]->init();
        e[i]->promote();
        e[i]->calcSalary();
        e[i]->showInfo();
    }
#endif


    return 0;
}
