#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    /*初始化限制位*/
    typePer=0;
    pointPer=0;
    leftNum=0;
    perRight=0;

    ui->setupUi(this);

    calculator=new Calculator;


    btnGroup=new QButtonGroup(this);

    /*按运算符优先级绑定按钮*/
    btnGroup->addButton(ui->zeroBtn,0);
    btnGroup->addButton(ui->oneBtn,1);
    btnGroup->addButton(ui->twoBtn,2);
    btnGroup->addButton(ui->threeBtn,3);
    btnGroup->addButton(ui->fourBtn,4);
    btnGroup->addButton(ui->fiveBtn,5);
    btnGroup->addButton(ui->sixBtn,6);
    btnGroup->addButton(ui->sevenBtn,7);
    btnGroup->addButton(ui->eightBtn,8);
    btnGroup->addButton(ui->nineBtn,9);
    btnGroup->addButton(ui->pointerBtn,10);
    btnGroup->addButton(ui->AddBtn,20);
    btnGroup->addButton(ui->SubBtn,21);
    btnGroup->addButton(ui->MulBtn,30);
    btnGroup->addButton(ui->DivBtn,31);
    btnGroup->addButton(ui->LeftBtn,40);
    btnGroup->addButton(ui->RightBtn,41);
    btnGroup->addButton(ui->EquBtn,50);
    btnGroup->addButton(ui->DeleteBtn,51);
    btnGroup->addButton(ui->ClearBtn,52);

    connect(btnGroup,SIGNAL(buttonClicked(int)),this,SLOT(btnClicked(int)));
}



MainWindow::~MainWindow()
{
    if(calculator!=nullptr)
    {
        delete calculator;
        calculator=nullptr;
    }

    delete ui;
}

/*修改字体大小*/
void MainWindow::SetFont(int value)
{
    QFont font;
    font.setBold(75);
    font.setPointSize(value);
    ui->showLabel->setFont(font);
}

void MainWindow::operJudge(int id)
{
    if(id==41)      //当判断需入栈符号为')'时,开始一直弹栈，直到遇到'(',弹出'(',结束弹栈
    {
//    qDebug() << __LINE__ << "  id:" << id/10 ;
        if(calculator->oper->back()==40)    //遇到'('为一个递归结束条件
        {
            calculator->oper->pop_back();
            return;
        }
        calculator->RevPolish->push_back(calculator->returnOper(calculator->oper->back()));
        calculator->oper->pop_back();
        return operJudge(id);       //递归弹栈
    }
    if(calculator->oper->empty()||id==4||(id/10>calculator->oper->back()/10))
        //oper为空时，直接入栈||需入栈符号为'('时，直接入栈||需入栈符号的优先级大于栈顶符号时，直接入栈
    {
//    qDebug() << __LINE__ << id/10;
        calculator->oper->push_back(id);
        return;     //符号入栈后，直接结束递归
    }
    else    //oper不为空&&需入栈符号的优先级小于栈顶元素时，开始判断递归弹栈
    {
        if(calculator->oper->back()==40)    //当弹栈遇到'('时，需入栈符号直接入栈，且弹栈递归结束
        {
//    qDebug() << __LINE__ << id/10;
        calculator->oper->push_back(id);
            return;
        }
//    qDebug() << __LINE__ << id/10;
        calculator->RevPolish->push_back(calculator->returnOper(calculator->oper->back()));
        calculator->oper->pop_back();
        return operJudge(id);       //递归弹栈
    }
}

void MainWindow::beZeroAll()
{
    typePer=0;
    pointPer=0;
    leftNum=0;
    perRight=0;
}

string Calculator::returnOper(const int id)
{
    switch(id)
    {
    case 20:
        return "+";
    case 21:
        return "-";
    case 30:
        return "*";
    case 31:
        return "/";
    case 40:
        return "(";
    }
    return nullptr;     //使用该函数时，没有做是否为空判断，暂时没有发现问题
}


void MainWindow::btnClicked(const int id)
{
    /*判断输入*/
    if(id>=0&&id<=9)    //按钮为数字时
    {
        if(id==0&&calculator->getInputInfo().back()=='/')       //分母不能为0
            return;
        if(calculator->getInputInfo()=="0")     //当showLabel只有一个'0'时（即没有输入)
            calculator->setInputInfo(to_string(id));    //按钮的id直接替换showLabel的'0'
        else
            calculator->addInputInfo(to_string(id));    //其他情况直接在showLabel后追加
        calculator->temp+=to_string(id);        //输入为数值时，直接追加到temp后
        typePer=0;      //输入了数字后，运算符和'.'的输入限制解除
        rightPer=0;
    }
    else if(id==10)     //当按钮为'.'时
    {
        if(pointPer==1||typePer==1||rightPer==1)    //当上一次输入为'.'或者运算符或者'('时，不允许输入'.'
            return;
        calculator->addInputInfo(".");
        calculator->temp+=".";
        typePer=1;      //输入'.'后，运算符和'.'的输入限制位锁定
        pointPer=1;
    }
    else if(id==50)     //当按钮时'='时
    {
        if(typePer==1||leftNum!=0)  //按'='前的输入是'.'或运算符或者'('没有对应')'时，不能进行计算
            return;
        if(calculator->temp!="")
        {
            if(calculator->RevPolish->size()<=1&&calculator->oper->size()<1)    //当输入只有一个数时，不允许计算
                return;
            calculator->RevPolish->push_back(calculator->temp);
            //当'='输入合法且temp里存有数字时，数字压入逆波兰表达式栈中，清空temp
            calculator->temp="";
        }
        typePer=1;      //按下'='后，运算符和'.'的输入限制位锁定
        pointPer=1;
        calculator->addInputInfo("=");      //showLabel上显示'='
        unsigned int operSize=calculator->oper->size();
        for(unsigned int i=0;i<operSize;i++)    //把oper中剩余的运算符从oper中弹出，压入RevPolish中
        {
            int o=calculator->oper->back();
            calculator->RevPolish->push_back(calculator->returnOper(o));
            calculator->oper->pop_back();
        }
        for(vector<string>::iterator it=calculator->RevPolish->begin();
            it!=calculator->RevPolish->end();it++)      //逆波兰表达式构建完成，开始从头开始遍历表达式
        {
//            qDebug() << QString::fromStdString(*it);
            if(*it!="+"&&*it!="-"&&*it!="*"&&*it!="/")      //遍历表达式时，遇到数字，压入resStack中
            {
                calculator->resStack->push_back(stold(*it));
            }
            else        //遇到运算符时，弹出resStack中的最上面两个数字，进行与运算符对应的运算（第一个弹出的在运算符右边，第二个在左边）
            {
                long double res,x,y;
                if(*it=="+")
                {
                    x=calculator->resStack->back();
                    calculator->resStack->pop_back();
                    y=calculator->resStack->back();
                    calculator->resStack->pop_back();
                    res=x+y;
                    calculator->resStack->push_back(res);
                }
                else if(*it=="-")
                {
                    x=calculator->resStack->back();
                    calculator->resStack->pop_back();
                    y=calculator->resStack->back();
                    calculator->resStack->pop_back();
                    res=y-x;
                    calculator->resStack->push_back(res);
                }
                else if(*it=="*")
                {
                    x=calculator->resStack->back();
                    calculator->resStack->pop_back();
                    y=calculator->resStack->back();
                    calculator->resStack->pop_back();
                    res=x*y;
                    calculator->resStack->push_back(res);
                }
                else if(*it=="/")
                {
                    x=calculator->resStack->back();
                    calculator->resStack->pop_back();
                    if(fabs(x)<1e-12)       //'/'右边不能为0
                    {
                        ui->memLabel->setText("WRONG!");
                    }
                    y=calculator->resStack->back();
                    calculator->resStack->pop_back();
                    res=y/x;
                    calculator->resStack->push_back(res);
                }
            }
        }
        ui->memLabel->setText(QString::fromStdString(to_string(calculator->resStack->back())));
        //表达式遍历完后，resStack中剩下的最后一个数字即运算结果
    }
    else if(id==51)
    {
        int p=0;    //同步temp和InputInfo的删除
        if(calculator->getInputInfo()!="")      //当showLabel中有实际输入时，才被允许删除操作
        {
            string t=calculator->getInputInfo();
            //当删除掉的不为数字或者'.'且temp为空时，RevPolish需要弹出一个数字放入temp中，
            //以保证temp、RevPolish和showLabel的同步
            if((t[t.size()-1]<48||t[t.size()-1]>57)&&t[t.size()-1]!='.'
                    &&t[t.size()-1]!='('&&t[t.size()-2]!=')'&&calculator->temp=="")
            {
                calculator->temp=calculator->RevPolish->back();
                for(unsigned int i=0;i<calculator->temp.size();i++)
                {
                    if(calculator->temp[i]=='.')    //如果temp取到的数字里含有'.'，'.'的输入限制位锁定，以保证一个数中只有一个'.'
                        pointPer=1;
                }
                calculator->RevPolish->pop_back();
                p=1;
            }
            if(t[t.size()-1]==')')      //删除')'后，'('的计数需要加一,保证左右括号匹配
            {
                leftNum++;
            }
            if(t[t.size()-1]=='(')      //跟')' 的删除同理
            {
                leftNum--;
            }
            if(t[t.size()-1]=='.')      //当删除了'.'时，'.'的输入限制位归零,以保证一个数中可以有一个'.'
                pointPer=0;
            t.pop_back();
            if(calculator->temp!=""&&p!=1)      //同步temp和InputInfo的删除
                calculator->temp.pop_back();
            if(t[t.size()-1]<48||t[t.size()-1]>57)
                //删除元素后，showLabel的剩余元素的最后一个元素不为数字时，符号的输入限制位锁定
            {
                typePer=1;
               // pointPer=1;
            }
            else    //最后一个为数字时，符号和'.'的输入限制位归零
            {
                typePer=0;
                pointPer=0;
            }
            calculator->setInputInfo(t);
        }
        ui->showLabel->setText(QString::fromStdString(calculator->getInputInfo()));
        if(calculator->getInputInfo()=="")      //showLabel被删除完时，全局归零
        {
            calculator->beZeroAll();
            beZeroAll();
            calculator->setInputInfo("0");
        }
    }
    else if(id==40)
    {
        if(pointPer==1||(typePer==0&&calculator->getInputInfo()!=""))   //当上一个输入为数字或者'.'时，'('的输入不被允许
            return;
        if(calculator->temp!="")    //输入'('时，需要把temp中存放的数字压入RevPolish且把temp清空
        {
            calculator->RevPolish->push_back(calculator->temp);
            calculator->temp="";
        }
        typePer=1;      //输入'('后不能输入运算符
        calculator->addInputInfo("(");
        operJudge(id);
        leftNum++;      //输入'('后，'('的计数需加一，且')'输入限制位解锁
        perRight=1;
    }
    else if(id==52)     //按下清除按钮后，全局清零
    {
        calculator->beZeroAll();
        beZeroAll();
        calculator->setInputInfo("0");
        ui->memLabel->setText(QString::number(0));
    }
    else
    {
        if(typePer==1)      //运算符限制位锁定时，不允许输入运算符
            return;
        if((leftNum==0||perRight==1)&&id==41)   //之前没有输入过'('或者')'限制位为锁定时，')'不允许被输入
            return;
        if(calculator->temp!="")    //输入运算符或者')'时，temp存放的数字压入RevPolish中，temp清空
        {
            calculator->RevPolish->push_back(calculator->temp);
            calculator->temp="";
        }
        typePer=1;
        pointPer=0;
        switch(id)
        {
        case 20:
            calculator->addInputInfo("+");
            operJudge(id);
            break;
        case 21:
            calculator->addInputInfo("-");
            operJudge(id);
            break;
        case 30:
            calculator->addInputInfo("*");
            operJudge(id);
            break;
        case 31:
            calculator->addInputInfo("/");
            operJudge(id);
            break;
        case 41:
            calculator->addInputInfo(")");
            operJudge(id);
            leftNum--;  //'('计数减一
            typePer=0;  //运算符限制位置零
            rightPer=1;
            break;
        }
        perRight=0;
    }

    /*自动改变字体大小，48个输入封顶*/
    if(calculator->getInputInfo().size()<22)
        SetFont(22);
    if(calculator->getInputInfo().size()>=22)
        SetFont(18);
    if(calculator->getInputInfo().size()>=28)
        SetFont(14);
    if(calculator->getInputInfo().size()>=36)
        SetFont(10);
    if(calculator->getInputInfo().size()>=48)
        return;

    /*显示输入*/
    ui->showLabel->setText(QString::fromStdString(calculator->getInputInfo()));

    /*输入限制位测试*/
    qDebug() << "typePer:" << typePer << "  pointPer:"
    << pointPer << "  leftNum:" << leftNum << "  rightPer:" << rightPer;
    qDebug() << QString::fromStdString(calculator->temp);


}
