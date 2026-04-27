#include <iostream>

using namespace std;
class Brand{
public:
    Brand(){}
    Brand(string b)
    {
        this->bran = b;
        cout<<this->bran<<"brand set"<<endl;
    }
    ~Brand(){}
    string getBran() const;
    void setBran(const string &value);

private:
    string bran;
};
class Cpu :virtual public Brand
{
public:
    Cpu(){}
    Cpu(string b){
        this->setBran(b);
        cout<<"cpu brand set"<<endl;

    }
//     virtual ~Cpu(){}
};

class Gra:virtual public Brand
 {
public:
    Gra(){}
    Gra(string b){
        this->setBran(b);
        cout<<"Gra brand set"<<endl;
        }
//       virtual ~Gra(){}
};

class Mer:virtual public  Brand
{
public:
    Mer(){}
    Mer(string b){
        this->setBran(b);
        cout<<"Mer brand set"<<endl;
    }
//    virtual ~Mer(){}
};

class Computer:public Cpu,public Gra,public Mer
{
public:
    Computer(){}
    Computer(string c,string g,string m):a1(c),b1(g),c1(m)
    {


    }

    void show()
    {
        cout<<a1.getBran()<<endl;
        cout <<b1.getBran()<<endl;
        cout<<c1.getBran()<<endl;
    }
//    virtual ~Computer(){}
    Cpu a1;
    Gra b1;
    Mer c1;

};

int main()
{

    Computer a("intel","colourful","kingston");
    a.show();
    return 0;
}

string Brand::getBran() const
{
return bran;
}

void Brand::setBran(const string &value)
{
bran = value;
}
