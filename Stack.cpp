#include <iostream>
#include <list>

using namespace std;


//Stack class definition.
template <class T>
class Stack
{
    list<T> data;

    public:
    void push(T newItem){data.push_front(newItem);}
    void pop(){return data.pop_front();}
    T top(){return *data.begin();}
    bool isEmpty() const {return data.size() == 0;}
    int size() {return data.size();}
    void clear(){data.clear();}
};


//Driver code
int main()
{
    string str;
    Stack<int> stk;
    stk.push(2);
    stk.push(5);
    stk.push(4);
    stk.push(9);
    stk.push(56);
    stk.pop();
    cout << "Size: " << stk.size() << endl;
}
