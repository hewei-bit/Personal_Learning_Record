#include <iostream>
#include <vector>
#include "stack.h"
using namespace std;


int main()
{
    cout << "Hello World!" << endl;
    Stack<int> st;

    st.push(13);
    st.push(56);
    st.push(78);

    cout << st.top() << " " << st.empty() << endl;
    st.pop();
    cout << st.top() << " " << st.empty() << endl;
    st.pop();
    cout << st.top() << " " << st.empty() << endl;
    st.pop();
    cout << st.top() << " " << st.empty() << endl;




    return 0;
}


