#include <iostream>

using namespace std;
//按ctrl 移动鼠标，就会出现下划线
namespace spaceA
{
    int a;
    int b;

}
//使用命名空间
//方式一:使用整个命名空间中 name
//using namespace spaceA; //a b

//方式二：使用命名空间中某个变量（对象）--->推荐使用
//using 命名空间名字:: 变量或者对象
using spaceA::a;

//方式三：在使用变量或者对象的，手动加上它的出处
//spaceA::b

//如何使用全局作用域(默认命名空间)中的对象
// ::variable //使用默认命名空间中变量，除此之外，还可以是函数
int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    a = 10;
    spaceA::b = 20;
    cout << "a = " << a << "b = " << spaceA::b << endl;

    return 0;
}
