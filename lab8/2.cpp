#include <iostream>
using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Queue
{
private:
    int front;
    int rear;
    int size;
    Node **Q;
public:
    Queue()
    {
        front = rear = -1;
        size = 10;
        Q = new Node*[size];
    }
    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new Node*[this->size];
    }
    ~Queue()
    {
        delete []Q;
    }
    void enqueue(Node *x);
    Node* dequeue();
    int isEmpty()
    {
        return front == rear;
    }
};

void Queue::enqueue(Node *x)
{
    if (rear == size - 1)
        cout << "Queue is Full\n";
    else
    {
        rear++;
        Q[rear] = x;
    }
}

Node* Queue::dequeue()
{
    Node* x = NULL;
    if (front == rear)
        cout << "Queue is Empty\n";
    else
    {
        front++;
        x = Q[front];
    }
    return x;
}

class Tree
{
public:
    Node *root;
    Tree()
    {
        root = NULL;
    }
    void CreateTree();
    void Preorder(Node *p);
    void Inorder(Node *p);
    void Postorder(Node *p);
    void Levelorder(Node *p);
    int Height(Node *root);
};

void Tree::CreateTree()
{
    Node *p, *t;
    int x;
    Queue q(100);
    cout << "Enter root value: ";
    if (!(cin >> x)) return;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);
    
    while (!q.isEmpty())
    {
        p = q.dequeue();
        cout << "Enter left child of " << p->data << ": ";
        if (!(cin >> x)) return;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        cout << "Enter right child of " << p->data << ": ";
        if (!(cin >> x)) return;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::Preorder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

void Tree::Postorder(Node *p)
{
    if (p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << " ";
    }
}

void Tree::Levelorder(Node *p)
{
    Queue q(100);
    cout << p->data << " ";
    q.enqueue(p);
    while (!q.isEmpty())
    {
        p = q.dequeue();
        if (p->lchild)
        {
            cout << p->lchild->data << " ";
            q.enqueue(p->lchild);
        }
        if (p->rchild)
        {
            cout << p->rchild->data << " ";
            q.enqueue(p->rchild);
        }
    }
}

int Tree::Height(Node *root)
{
    int x = 0, y = 0;
    if (root == NULL)
        return 0;
    x = Height(root->lchild);
    y = Height(root->rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}

int main()
{
    Tree t;
    t.CreateTree();
    
    cout << "\nPreorder: ";
    t.Preorder(t.root);
    cout << "\n";
    
    cout << "Inorder: ";
    t.Inorder(t.root);
    cout << "\n";
    
    cout << "Postorder: ";
    t.Postorder(t.root);
    cout << "\n";
    
    cout << "Levelorder: ";
    t.Levelorder(t.root);
    cout << "\n";
    
    cout << "Height: " << t.Height(t.root) << "\n";
    
    return 0;
}
