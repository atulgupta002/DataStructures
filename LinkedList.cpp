#include <iostream>

using namespace std;

//Linked list node class definition.
template <class T>
class LinkedListNode
{
    T data;
    LinkedListNode<T>* next;

    public:
    LinkedListNode():next(nullptr){}
    LinkedListNode(T newData): data(newData),next(nullptr){}

    T getData(){return this->data;}
    void setData(T newData){this->data = newData;}

    LinkedListNode<T>* getNext(){return this->next;}
    void setNext(LinkedListNode<T>* newNext){this->next = newNext;}

    template <typename U>friend class LinkedList;
};


//Linked List class definition.
template <class T>
class LinkedList
{
    LinkedListNode<T>* head;

    public:
    LinkedList(){head = nullptr;}
    LinkedList(T newData){
        head = new LinkedListNode<T>();
        head->data = newData;
    }
    LinkedListNode<T>* getHead(){return this->head;}
    void setHead(LinkedListNode<T>* newHead){this->head = newHead;}

    int size();
    void push_back(T newData);
    void push_after(T newData, LinkedListNode<T>* node);
    void print();
    void remove(T data);
    void remove(LinkedListNode<T>* node);
    void reverse();
    bool isFound(T data);
    LinkedListNode<T>* find(T data);
};

//Function to insert to the end of the linked list.
template <class T>
void LinkedList<T>::push_back(T newData)
{
    if(head == nullptr)
    {
        head = new LinkedListNode<T>(newData);
        return;
    }
    LinkedListNode<T>* temp = head;
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    LinkedListNode<T>* node = new LinkedListNode<T>(newData);
    temp->next = node;
    return;
}

//Function to insert a new node after a specified node.
template <class T>
void LinkedList<T>::push_after(T newData, LinkedListNode<T>* node)
{
    if(head == nullptr || node->next == nullptr)
    {
        push_back(newData);
        return;
    }
    LinkedListNode<T>* newNode = new LinkedListNode<T>(newData);
    newNode->next = node->next->next;
    node->next = newNode;
    return;
}

//Function to return the size of the linked list.
template <class T>
int LinkedList<T>::size()
{
    int size = 0;
    LinkedListNode<T>* temp = head;
    while(temp != nullptr)
    {
        temp = temp->next;
        size++;
    }
    return size;
}

//Function to print the linked list.
template <class T>
void LinkedList<T>::print()
{
    LinkedListNode<T>* temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return;
}

//Function to remove a value from the linked list.
template <class T>
void LinkedList<T>::remove(T data)
{
    LinkedListNode<T>* temp = head;
    LinkedListNode<T>* prev = nullptr;
    while(temp != nullptr && temp->data != data)
    {
        prev = temp;
        temp = temp->next;
    }
    //data not found in the list.
    if(temp == nullptr)
    {
        return;
    }
    prev->next = temp->next;
    temp->next = nullptr;
    delete temp;
}

//Function to remove a particular node from the linked list.
template <class T>
void LinkedList<T>::remove(LinkedListNode<T>* node)
{
    if(head == nullptr)
    {
        return;
    }
    LinkedListNode<T>* temp = head;
    LinkedListNode<T>* prev = nullptr;
    while(temp != nullptr && temp != node)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp == nullptr)
    {
        return;
    }
    prev->next = node->next;
    node->next = nullptr;
    delete node;
}

//Function to reverse a linked list.
template <class T>
void LinkedList<T>::reverse()
{
    if (head == nullptr)
    {
        return;
    }

    LinkedListNode<T>* temp = head;
    LinkedListNode<T>* prev = nullptr;
    LinkedListNode<T>* next = nullptr;

    while (temp != nullptr)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    head = prev;
}

//Function to check if a value exists in the list.
template <class T>
bool LinkedList<T>::isFound(T data)
{
    if(head == nullptr)
    {
        return false;
    }
    LinkedListNode<T>* temp = head;
    while(temp != nullptr && temp->data != data)
    {
        temp = temp->next;
    }
    if(temp == nullptr)
    {
        return false;
    }
    return true;
}


//Function to find the position of a particular value in the linked list.
template <class T>
LinkedListNode<T>* LinkedList<T>::find(T data)
{
    if(head == nullptr)
    {
        return head;
    }
    LinkedListNode<T>* temp = head;
    while(temp != nullptr && temp->data != data)
    {
        temp = temp->next;
    }
    return temp;
}

//Driver code for Linked List class.
int main()
{
    LinkedList<int> list;
    list.push_back(34);
    list.push_back(67);
    list.push_back(12);
    list.push_back(78);

    cout << "Size: " << list.size() << endl;
    list.remove(12);
    cout << "Size after removing: " << list.size() << endl;

    cout << "Printing: ";
    list.print();
    cout << endl;
    list.reverse();
    cout << "Printing reverse: ";
    list.print();
    cout << endl;
    cout << "Is found : " << list.isFound(100) << endl;
    cout << "Find: " << list.find(67) << endl;
}
