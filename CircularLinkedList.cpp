#include <iostream>

using namespace std;

template <class T>
class CircularLinkedListNode
{
    T data;
    CircularLinkedListNode<T>* next;

    public:
    CircularLinkedListNode():next(nullptr){}
    CircularLinkedListNode(T newData): data(newData),next(nullptr){}
    template <typename U>friend class CircularLinkedList;
};

template <class T>
class CircularLinkedList
{
    CircularLinkedListNode<T>* head;

    public:
    CircularLinkedList():head(nullptr){}
    void push_back(T newData);
    void push_after(T listValue, T newData);
    void print();
    int size();
    void remove(T value);
};

template <class T>
void CircularLinkedList<T>::push_back(T newData)
{
    if(head == nullptr)
    {
        head = new CircularLinkedListNode<T>(newData);
        head->next = head;
        return;
    }
    if(head->next == head)
    {
        CircularLinkedListNode<T>* node = new CircularLinkedListNode<T>(newData);
        head->next = node;
        node->next = head;
        return;
    }
    CircularLinkedListNode<T>* temp = head;
    while(temp->next != head)
    {
        temp = temp->next;
    }
    CircularLinkedListNode<T>* node = new CircularLinkedListNode<T>(newData);
    temp->next = node;
    node->next = head;
    return;
}

template <class T>
void CircularLinkedList<T>::push_after(T listValue, T newData)
{
    if(head == nullptr)
    {
        push_back(newData);
        return;
    }
    if(head->next == head && head->data == listValue)
    {
        push_back(newData);
        return;
    }
    if(head->next == head && head->data != listValue)
    {
        return;
    }
    if(head->data == listValue)
    {
        CircularLinkedListNode<T>* node = new CircularLinkedListNode<T>(newData);
        node->next = head->next;
        head->next = node;
        return;
    }
    CircularLinkedListNode<T>* temp = head->next;
    while(temp->next != head && temp->data != listValue)
    {
        temp = temp->next;
    }
    if(temp->next == head && temp->data == listValue)
    {
        push_back(newData);
        return;
    }
    if(temp->next == head && temp->data != listValue)
    {
        return;
    }
    CircularLinkedListNode<T>* node = new CircularLinkedListNode<T>(newData);
    node->next = temp->next;
    temp->next = node;
    return;
}

template <class T>
void CircularLinkedList<T>::print()
{
    if(head == nullptr)
    {
        return;
    }
    cout << head->data;
    if(head->next == head)
    {
        return;
    }
    cout << " ";
    CircularLinkedListNode<T>* temp = head->next;
    while(temp->next != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data;
}

template <class T>
int CircularLinkedList<T>::size()
{
    int size = 1;
    if(head == nullptr)
    {
        return 0;
    }
    if(head->next == head)
    {
        return size;
    }
    CircularLinkedListNode<T>* temp = head->next;
    while(temp->next != head)
    {
        size++;
        temp = temp->next;
    }
    return ++size;
}

template <class T>
void CircularLinkedList<T>::remove(T value)
{
    if(head == nullptr || head->next == head)
    {
        return;
    }
    CircularLinkedListNode<T>* temp = head->next;
    CircularLinkedListNode<T>* prev = nullptr;
    CircularLinkedListNode<T>* next = nullptr;
    while(temp->next != head && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
        next = temp->next;
    }
    if(head->data == value)
    {
        CircularLinkedListNode<T>* toDelete = head;
        head = head->next;
        temp->next = head;
        delete toDelete;
        return;
    }
    if(temp->next == head && temp->data != value)
    {
        return;
    }
    if(temp->next == head && temp->data == value)
    {
        prev->next = head;
        temp->next = nullptr;
        delete temp;
        return;
    }
    prev->next = next;
    delete temp;
    return;
}

int main()
{
    CircularLinkedList<int> cll;
    cll.push_back(23);
    cll.push_back(54);
    cll.push_back(87);
    cll.push_back(56);
    cll.push_after(23,45);
    cll.push_after(45,89);

    cll.print();
    cout << endl;
    cout << cll.size() << endl;
    cll.remove(56);
    cout << endl;
    cll.print();
    cout << endl;
    cout << cll.size() << endl;
}