#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;
//设计一个字符串类

class String
{
public:
    String(const char *str = nullptr);
    String(const String &other);
    ~String();
    String & operator = (const String &other);
    String operator + (const String &other);
    char *data() const;

private:
    char * m_data;
};

int main()
{
    cout << "Hello World!" << endl;
    String s1("asd");
    cout << "s1.data : "<< s1.data() << endl;

    String s2 = s1;
    cout << "s2.data : "<< s2.data() << endl;

    String s3 = ("dsa");
    cout << "s3.data : "<<s3.data() << endl;

    s1 = s3;
    cout << "s1 = s3 : ";
    cout << s1.data() << endl;
    s2 = s1+s3;
    cout << "s2 = s1 + s3 : ";
    cout << s2.data() << endl;
    return 0;
}

String::String(const char *str)
{
//    cout << "String(const char *str)"<<endl;
    if(str == nullptr)
    {
        this->m_data = new char[1];
        *m_data = '\0';
    }
    else {
        size_t length = strlen(str);
        this->m_data = new char[length+1];
        strcpy(this->m_data,str);
    }
}

String::String(const String &other)
{
    cout << "String(const String &other)  "<<endl;
    if(other.m_data == nullptr)
    {
        this->m_data = nullptr;
    }
    size_t length = strlen(other.m_data);
    this->m_data = new char[length+1];
    strcpy(this->m_data,other.m_data);
}

String::~String()
{
    if(m_data)
    {
        delete[] m_data;
        m_data = nullptr;
    }
}

String &String::operator =(const String &other)
{
    if(this != &other)
    {
        delete [] m_data;
        if(other.m_data == nullptr)
        {
            this->m_data = nullptr;
        }
        else {
            size_t length = strlen(other.m_data);
            this->m_data = new char[length+1];
            strcpy(this->m_data,other.m_data);
        }
    }
    return *this;

}

String String::operator +(const String &other)
{
    String newString;
    if(other.m_data == nullptr)
    {
        newString = *this;
    }
    else if(this->m_data == nullptr)
    {
        newString = other;
    }
    else
    {
        newString.m_data = new char[strlen(this->m_data)+strlen(other.m_data)+1];
        strcpy(newString.m_data,this->m_data);
        strcat(newString.m_data,other.m_data);
    }
    return newString;
}

char *String::data() const
{
return m_data;
}










