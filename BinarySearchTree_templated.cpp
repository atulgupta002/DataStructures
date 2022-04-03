#include <iostream>
#include <queue>

using namespace std;


//BST node class definition.
template <class T>
class BSTNode
{
    T data;
    BSTNode<T>* parent; 
    BSTNode<T>* left; 
    BSTNode<T>* right;

    public:
    BSTNode():parent(nullptr),left(nullptr),right(nullptr){}
    BSTNode(T newData, BSTNode<T>* newLeft = nullptr, BSTNode<T>* newRight = nullptr, BSTNode<T>* newParent = nullptr):
        data(newData),left(newLeft),right(newRight),parent(newParent){}

    T getData() {return this->data;}
    void setData(T newData) {this->data = newData;}

    BSTNode<T>* getParent() {return this->parent;}
    void setParent(BSTNode<T>* newParent) {this->parent = newParent;}

    BSTNode<T>* getLeft() {return this->left;}
    void setLeft(BSTNode<T>* newLeft) {this->left = newLeft;}

    BSTNode<T>* getRight() {return this->right;}
    void setRight(BSTNode<T>* newRight) {this->right = newRight;}

    template<class U>friend class BST;
};


//BST class definition.
template <class T>
class BST
{
    BSTNode<T>* root;

    public:
    BST():root(nullptr){}

    BST(T newData){
        root->data = newData;
        root->left = nullptr;
        root->right = nullptr;
        root->parent = nullptr;
    }

    BSTNode<T>* getRoot() {return this->root;}
    void setRoot(BSTNode<T>* node) {this->root = node;}

    void insert(T newData);

    void traverseInOrder(BSTNode<T>* node);
    void traversePreOrder(BSTNode<T>* node);
    void traversePostOrder(BSTNode<T>* node);
    void traverseLevelOrder(int level = 1);

    int height(BSTNode<T>* node);
    void remove(BSTNode<T>* node);
};


//Function to insert new data into the BST.
template <class T>
void BST<T>::insert(T newData)
{
    if(root == nullptr)
    {
        root = new BSTNode<T>(newData);
        return;
    }
    BSTNode<T>* temp = root;
    BSTNode<T>* prev = nullptr;
    while(temp != nullptr)
    {
        prev = temp;
        if(newData <= temp->data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    BSTNode<T>* node = new BSTNode<T>(newData);
    node->data = newData;
    if(prev->data > newData)
    {
        prev->left = node;
    }
    else
    {
        prev->right = node;
    }
}

//In order traversal of the BST.
template <class T>
void BST<T>::traverseInOrder(BSTNode<T>* node)
{
    if(node != nullptr)
    {
        traverseInOrder(node->left);
        std::cout << node->data << " ";
        traverseInOrder(node->right);
    }
}

//Pre order traversal of the BST.
template <class T>
void BST<T>::traversePreOrder(BSTNode<T>* node)
{
    if(node != nullptr)
    {
        std::cout << node->data << " ";
        traversePreOrder(node->left);
        traversePreOrder(node->right);
    }
}

//Post order traversal of the BST.
template <class T>
void BST<T>::traversePostOrder(BSTNode<T>* node)
{
    if(node != nullptr)
    {
        traversePostOrder(node->left);
        traversePostOrder(node->right);
        std::cout << node->data << " ";
    }
}

//Queue based level order traversal of the BST.
template <class T>
void BST<T>::traverseLevelOrder(int level)
{
    if (root == nullptr)
    {
        return;
    }
    
    if(level <= 0){level = 1;}

    queue<BSTNode<T>*> q;
    q.push(root);
    
    int levelCounter = 1;

    while(!q.empty())
    {
        BSTNode<T>* temp = q.front();
        q.pop();
        if(levelCounter++ >= level)
        {
            cout << temp->data << " ";
        }
        if(temp->left != nullptr)
        {
            q.push(temp->left);        
        }
        if(temp->right != nullptr)
        {
            q.push(temp->right);
        }
    }
}

//Function to calculate the height of a particular node.
template <class T>
int BST<T>::height(BSTNode<T>* node)
{
    if(root == nullptr)
    {
        return 0;
    }
    
    int leftHeight = 0, rightHeight = 0;
    
    if(node->left != nullptr)
    {
        leftHeight = height(node->left);
    }
    if(node->right != nullptr)
    {
        rightHeight = height(node->right);
    }
    return (leftHeight >= rightHeight) ? leftHeight+1 : rightHeight+1;
}


//Function to remove a node from the BST.
template <class T>
void BST<T>::remove(BSTNode<T>* node)
{
    //3 cases: no child, 1 child, 2 children.

    //Case 1: no child
    if(node->left != nullptr && node->right != nullptr)
    {
        if(node->parent == nullptr)
        {
            root = nullptr;
        }
        if (node->parent->left = node)
        {
            node->parent->left = nullptr;
        }
        else
        {
            node->parent->right = nullptr;
        }
        delete node;
    }

    //Case 2: 1 child
    if(node->left != nullptr && node->right == nullptr)
    {
        BSTNode<T>* toDelete = node->left;
        node->data = toDelete->data;
        node->left = toDelete->left;
        if(node->left != nullptr)
        {
            node->left->parent = node;
        }
        node->right = toDelete->right;
        if(node->right != nullptr)
        {
            node->right->parent = node;
        }
        delete toDelete;
    }
    else if (node->left == nullptr && node->right != nullptr)
    {
        BSTNode<T>* toDelete = node->right;
        node->data = toDelete->data;
        node->left = toDelete->left;
        if(node->left != nullptr)
        {
            node->left->parent = node;
        }
        node->right = toDelete->right;
        if(node->right != nullptr)
        {
            node->right->parent = node;
        }
        delete toDelete;
    }

    //Case 3: 2 children
    else
    {
        BSTNode<T>* minOfRight = node->right;
        while(minOfRight->left != nullptr)
        {
            minOfRight = minOfRight->left;
        }
        node->data = minOfRight->data;
        remove(minOfRight); 
    }
}


//Driver code.
int main()
{
    BST<int> bt;
    bt.insert(50);
    bt.insert(30);
    bt.insert(70);
    bt.insert(23);
    bt.insert(87);
    cout << "In order: ";
    bt.traverseInOrder(bt.getRoot());
    cout << endl;

    cout << "Pre order: ";
    bt.traversePreOrder(bt.getRoot());
    cout << endl;

    cout << "Post order: ";
    bt.traversePostOrder(bt.getRoot());
    cout << endl;

    cout << "Level order: ";
    bt.traverseLevelOrder();
    cout << endl;

    cout << "Height: " << bt.height(bt.getRoot()) << endl;

    BSTNode<int>* temp = bt.getRoot();
    while(temp->getData() != 70)
    {
        if(temp->getData() > 70)
        {
            temp = temp->getLeft();
        }
        else
        {
            temp = temp->getRight();
        }
    }
    bt.remove(temp);
    cout << "In order: ";
    bt.traverseInOrder(bt.getRoot());
}
