#include <iostream>

using namespace std;

//Doubly linked list node class definition.
template <class T>
class DoublyLinkedListNode
{
    T data;
    DoublyLinkedListNode<T>* prev;
    DoublyLinkedListNode<T>* next;

    public:
    DoublyLinkedListNode():prev(nullptr),next(nullptr){}
    DoublyLinkedListNode(T newData):data(newData),prev(nullptr),next(nullptr){}
    template <typename U>friend class DoublyLinkedList;
};

//Doubly linked list class definition.
template <class T>
class DoublyLinkedList
{
    DoublyLinkedListNode<T>* head;
    DoublyLinkedListNode<T>* tail;

    public:
    DoublyLinkedList():head(nullptr),tail(nullptr){}
    void push_back(T newData);
    void push_after(T newData, DoublyLinkedListNode<T>* node);
    void print();
    void printReverse();
    int size();
    void remove(T newData);
    void pop();
    DoublyLinkedListNode<T>* find(T data);
};


//Function to insert a new node at the end of the linked list.
template <class T>
void DoublyLinkedList<T>::push_back(T newData)
{
    if(head == nullptr)
    {
        head = new DoublyLinkedListNode<T>(newData);
        tail = head;
        return;
    }
    DoublyLinkedListNode<T>* temp = head;
    DoublyLinkedListNode<T>* prev = nullptr;
    while(temp != nullptr)
    {
        prev = temp;
        temp = temp->next;
    }
    DoublyLinkedListNode<T>* node = new DoublyLinkedListNode<T>(newData);
    node->prev = prev;
    prev->next = node;
    tail = node;
    return;
}

//Function to insert a new node after a specified node.
template <class T>
void DoublyLinkedList<T>::push_after(T newData, DoublyLinkedListNode<T>* node)
{
    if(head == nullptr || node->next == nullptr)
    {
        push_back(newData);
        return;
    }
    DoublyLinkedListNode<T>* newNode = new DoublyLinkedListNode<T>(newData);
    DoublyLinkedListNode<T>* temp = head;
    DoublyLinkedListNode<T>* prev = nullptr;

    while (temp != nullptr)
    {
        prev = temp;
        temp = temp->next;
    }
    newNode->next = prev->next;
    prev->next->prev = newNode;
    prev->next = newNode;
    newNode->prev = prev;
    return;
}

//Function to print the doubly linked list.
template <class T>
void DoublyLinkedList<T>::print()
{
    if(head == nullptr)
    {
        return;
    }
    DoublyLinkedListNode<T>* temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    return;
}

//Function to print the doubly linked list in reverse order.
template <class T>
void DoublyLinkedList<T>::printReverse()
{
    if(head == nullptr)
    {
        return;
    }
    DoublyLinkedListNode<T>* temp = tail;
    while(temp != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->prev;
    }
    return;
}

//Function to return the size of the doubly linked list.
template <class T>
int DoublyLinkedList<T>::size()
{
    if(head == nullptr)
    {
        return 0;
    }
    int size = 0;
    DoublyLinkedListNode<T>* temp = head;
    while(temp != nullptr)
    {
        size++;
        temp = temp->next;
    }
    return size;
}

//Function to remove a user-specified value from the list.
template <class T>
void DoublyLinkedList<T>::remove(T newData)
{
    if(head == nullptr || head == tail)
    {
        return;
    }
    if(head->data == newData)
    {
        head = head->next;
        head->prev = nullptr;
        return;
    }
    DoublyLinkedListNode<T>* temp = head;
    DoublyLinkedListNode<T>* prev = nullptr;
    DoublyLinkedListNode<T>* next = nullptr;
    while(temp != nullptr && temp->data != newData)
    {
        prev = temp;
        temp = temp->next;
        next = temp->next;
    }
    if(temp == nullptr)
    {
        return;
    }
    if(temp == tail)
    {
        pop();
        return;
    }
    if(prev != nullptr)
    {
        prev->next = temp->next;
    }
    next->prev = temp->prev;
    next->prev = prev;
    temp->next = nullptr;
    temp->prev = nullptr;
    delete temp;
}

//Function to remove the tail node from the list without returning the associated data.
template <class T>
void DoublyLinkedList<T>::pop()
{
    if(head == nullptr || head == tail)
    {
        return;
    }
    DoublyLinkedListNode<T>* temp = head;
    DoublyLinkedListNode<T>* prev = nullptr;
    while(temp != tail)
    {
        prev = temp;
        temp = temp->next;
    }
    tail = prev;
    prev->next = nullptr;
    delete temp;
    return;
}

//Function to find a particular value in the doubly linked list.
template <class T>
DoublyLinkedListNode<T>* DoublyLinkedList<T>::find(T data)
{
    if(head == nullptr)
    {
        return head;
    }
    DoublyLinkedListNode<T>* temp = head;
    while(temp != nullptr && temp->data != data)
    {
        temp = temp->next;
    }
    return temp;
}


//Driver code for doubly linked list.
int main()
{
    DoublyLinkedList<int> dll;
    dll.push_back(3);
    dll.push_back(5);
    dll.push_back(1);
    dll.push_back(23);
    dll.push_back(4);
    dll.push_back(8);

    dll.print();
    cout << endl;
    dll.printReverse();
    cout << endl;
    cout << "Size: " << dll.size() <<  endl;

    dll.pop();
    cout << "Size: " << dll.size() <<  endl;
    dll.remove(4);
    cout << "Size: " << dll.size() <<  endl;
    dll.print();
    cout << endl;
    dll.printReverse();
    cout << dll.find(23) << endl;
}