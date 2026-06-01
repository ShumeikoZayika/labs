#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};

void createQueue(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));
}

void enqueue(struct Queue *q, struct Node *x)
{
    if ((q->rear + 1) % q->size == q->front)
        printf("Queue is Full\n");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

struct Node *dequeue(struct Queue *q)
{
    struct Node *x = NULL;
    if (q->front == q->rear)
        printf("Queue is Empty\n");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

int isEmptyQueue(struct Queue q)
{
    return q.front == q.rear;
}

struct Stack
{
    int size;
    int top;
    struct Node **S;
};

void Stackcreate(struct Stack *st, int size)
{
    st->size = size;
    st->top = -1;
    st->S = (struct Node **)malloc(st->size * sizeof(struct Node *));
}

void push(struct Stack *st, struct Node *x)
{
    if (st->top == st->size - 1)
        printf("Stack overflow\n");
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

struct Node *pop(struct Stack *st)
{
    struct Node *x = NULL;
    if (st->top == -1)
        printf("Stack Underflow\n");
    else
    {
        x = st->S[st->top];
        st->top--;
    }
    return x;
}

int isEmptyStack(struct Stack st)
{
    return st.top == -1;
}

struct Node *root = NULL;

void Treecreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    createQueue(&q, 100);
    
    printf("Enter root value ");
    if (scanf("%d", &x) != 1) return;
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);
    
    while (!isEmptyQueue(q))
    {
        p = dequeue(&q);
        printf("Enter left child of %d ", p->data);
        if (scanf("%d", &x) != 1) return;
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("Enter right child of %d ", p->data);
        if (scanf("%d", &x) != 1) return;
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void IPreorder(struct Node *p)
{
    struct Stack stk;
    Stackcreate(&stk, 100);
    while (p != NULL || !isEmptyStack(stk))
    {
        if (p != NULL)
        {
            printf("%d ", p->data);
            push(&stk, p);
            p = p->lchild;
        }
        else
        {
            p = pop(&stk);
            p = p->rchild;
        }
    }
}

void IInorder(struct Node *p)
{
    struct Stack stk;
    Stackcreate(&stk, 100);
    while (p != NULL || !isEmptyStack(stk))
    {
        if (p != NULL)
        {
            push(&stk, p);
            p = p->lchild;
        }
        else
        {
            p = pop(&stk);
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
}

void IPostorder(struct Node *p)
{
    struct Stack stk;
    Stackcreate(&stk, 100);
    long int temp;
    while (p != NULL || !isEmptyStack(stk))
    {
        if (p != NULL)
        {
            push(&stk, p);
            p = p->lchild;
        }
        else
        {
            temp = (long int)pop(&stk);
            if (temp > 0)
            {
                push(&stk, (struct Node *)(-temp));
                p = ((struct Node *)temp)->rchild;
            }
            else
            {
                printf("%d ", ((struct Node *)(-temp))->data);
                p = NULL;
            }
        }
    }
}

void LevelOrder(struct Node *p)
{
    struct Queue q;
    createQueue(&q, 100);
    printf("%d ", p->data);
    enqueue(&q, p);
    while (!isEmptyQueue(q))
    {
        p = dequeue(&q);
        if (p->lchild)
        {
            printf("%d ", p->lchild->data);
            enqueue(&q, p->lchild);
        }
        if (p->rchild)
        {
            printf("%d ", p->rchild->data);
            enqueue(&q, p->rchild);
        }
    }
}

int count(struct Node *p)
{
    if (p)
        return count(p->lchild) + count(p->rchild) + 1;
    return 0;
}

int height(struct Node *p)
{
    int x = 0, y = 0;
    if (p == 0)
        return 0;
    x = height(p->lchild);
    y = height(p->rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}

int main()
{
    Treecreate();
    printf("\nIterative Traversals:\n");
    
    printf("Iterative Preorder: ");
    IPreorder(root);
    printf("\n");
    
    printf("Iterative Inorder: ");
    IInorder(root);
    printf("\n");
    
    printf("Iterative Postorder: ");
    IPostorder(root);
    printf("\n");
    
    printf("Levelorder: ");
    LevelOrder(root);
    printf("\n");
    
    printf("Height: %d\n", height(root));
    printf("Count: %d\n", count(root));
    
    return 0;
}
