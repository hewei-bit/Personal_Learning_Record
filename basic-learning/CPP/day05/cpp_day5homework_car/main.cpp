#include <iostream>
#include <unistd.h>
using namespace std;

class ccar
{
public:
    ccar(string color = "Red",string brand = "BWM",float distant = 0,float gas = 0)
        :m_color(color),m_brand(brand),m_distant(distant),m_gas(gas)
    {

    }

    void Run()
    {
        while (1) {
            while(1)
            {

                sleep(1);
                //system("cls");
                if(this->m_gas <=0)
                {
                    this->m_gas = 0;
                    cout << "Please add gas" << endl;
                    break;
                }

                cout << "Running ....." << "distant : " << this->m_distant << "gas :"
                     << this->m_gas << "\r";
                this->m_distant += 10;
                this->m_gas -= 5;

            }

            //加油
            addGas();
        }

    }
private:
    void addGas()
    {
        cout << "Please inpu Gas:" << endl;
        cin >> this->m_gas;
    }
private:
   const string m_color;
   const string m_brand;
    float m_distant;
    float m_gas;
};


int main()
{

    ccar car;
    car.Run();
    return 0;
}
