#include <iostream>
#include <list>

using namespace std;

template <class T>
class Queue
{
    list<T> data;

    public:
    void enqueue(T newItem) {data.push_back(newItem);}
    void dequeue(){return data.pop_front();}
    T top() {return *data.begin();}
    bool isEmpty() {return data.size() == 0;}
    int size() { return data.size();}
    void clear() {data.clear();}
};