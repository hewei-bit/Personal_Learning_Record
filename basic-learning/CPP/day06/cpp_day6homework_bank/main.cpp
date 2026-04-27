#include <iostream>

using namespace std;

class Window
{

public:
    Window(string name)
    {
        this->name = name;
    }

    static int addPerson()
    {
       m_personCount++;
       return m_personCount;
    }

    void serverOne()
    {
        if(m_lastPersonIndex < m_personCount)
        {
            m_lastPersonIndex++;
            cout << this->name << " is servering" << m_lastPersonIndex << endl;
        }

        if(m_lastPersonIndex >= m_personCount)
        {
            m_openFlag = false;
        }

    }

    static bool openFlag()
    {
        return m_openFlag;
    }

private:
    string name; //窗口的名字
    static int m_personCount; //排队人数
    static int m_lastPersonIndex; //正在处理当前最后一个人
    static bool m_openFlag; //银行是否营业
};

int Window::m_personCount = 0;
int Window::m_lastPersonIndex = 0;
bool Window::m_openFlag = true;

int main()
{
   Window w1("A");
   Window w2("B");
   Window w3("C");

   cout << "please input total person number" << endl;
   int number;
   cin >> number;

   for (int i=0;i<number;i++) {
       Window::addPerson();
   }

   while (true == Window::openFlag()) {
       w1.serverOne();
       w2.serverOne();
       w3.serverOne();
   }

   cout << "server endl" << endl;
    return 0;
}


