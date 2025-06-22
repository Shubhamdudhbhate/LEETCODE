#include <iostream>
#include <list>
#include <vector>
using namespace std;

class StackList
{
    list<int> st;

public:


    void push(int x)
    {
        st.push_back(x);
    }

    void pop()
    {
        if (!st.empty())
            st.pop_back();
    }

    int top()
    {
        return st.back();
    }

    bool empty()
    {
        return st.empty();
    }





    void push(int x)
    {
        st.push_back(x);
    }
    void pop()
    {
        if (!st.empty())
            st.pop_back();
    }

    int top()
    {
        return st.back();
    }

    bool empty()
    {
        return st.empty();
    }







    void push(int x)
    {
        st.push_back(x);
    }

    void pop()
    {
        if (!st.empty())
            st.pop_back();
    }

    int top()
    {
        return st.back();
    }

    bool empty()
    {
        return st.empty();
    }
};





int main()
{
    StackList s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top (list): " << s.top() << endl; // 30
    s.pop();
    cout << "Top after pop: " << s.top() << endl; // 20
    return 0;
}
