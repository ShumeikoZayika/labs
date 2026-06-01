#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL;

void Insert(int key)
{
    struct Node *t=root;
    struct Node *r=NULL, *p;
    
    if(root==NULL)
    {
        p=(struct Node *)malloc(sizeof(struct Node));
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return;
    }
    
    while(t!=NULL)
    {
        r=t;
        if(key<t->data)
            t=t->lchild;
        else if(key>t->data)
            t=t->rchild;
        else
            return;
    }
    
    p=(struct Node *)malloc(sizeof(struct Node));
    p->data=key;
    p->lchild=p->rchild=NULL;
    
    if(key<r->data)
        r->lchild=p;
    else
        r->rchild=p;
}

struct Node *RInsert(struct Node *p, int key)
{
    struct Node *t=NULL;
    
    if(p==NULL)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }
    
    if(key<p->data)
        p->lchild=RInsert(p->lchild, key);
    else if(key>p->data)
        p->rchild=RInsert(p->rchild, key);
        
    return p;
}

struct Node *Search(int key)
{
    struct Node *t=root;
    while(t!=NULL)
    {
        if(key==t->data)
            return t;
        else if(key<t->data)
            t=t->lchild;
        else
            t=t->rchild;
    }
    return NULL;
}

struct Node *RSearch(struct Node *p, int key)
{
    if(p==NULL)
        return NULL;
    if(key==p->data)
        return p;
    else if(key<p->data)
        return RSearch(p->lchild, key);
    else
        return RSearch(p->rchild, key);
}

void Inorder(struct Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

int main()
{
    Insert(30);
    Insert(10);
    Insert(40);
    Insert(20);
    
    root = RInsert(root, 50);
    
    printf("Inorder Traversal: ");
    Inorder(root);
    printf("\n");
    
    struct Node *temp = Search(20);
    if(temp != NULL)
        printf("Element %d is found (Iterative Search)\n", temp->data);
    else
        printf("Element not found\n");
        
    temp = RSearch(root, 40);
    if(temp != NULL)
        printf("Element %d is found (Recursive Search)\n", temp->data);
    else
        printf("Element not found\n");
        
    temp = Search(99);
    if(temp != NULL)
        printf("Element %d is found\n", temp->data);
    else
        printf("Element 99 is not found\n");
        
    return 0;
}
