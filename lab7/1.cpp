#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q, int size) {
    q->size  = size;
    q->front = q->rear = 0;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

int isEmpty(struct Queue q) {
    return q.front == q.rear;
}

int isFull(struct Queue q) {
    return (q.rear + 1) % q.size == q.front;
}

void enqueue(struct Queue *q, int x) {
    if (isFull(*q))
        printf("Queue is Full\n");
    else {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q) {
    int x = -1;
    if (isEmpty(*q))
        printf("Queue is Empty\n");
    else {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

void Display(struct Queue q) {
    int i;
    if (isEmpty(q)) { printf("Queue is Empty\n"); return; }
    i = (q.front + 1) % q.size;
    do {
        printf("%d ", q.Q[i]);
        i = (i + 1) % q.size;
    } while (i != (q.rear + 1) % q.size);
    printf("\n");
}

int main() {
    struct Queue q;
    create(&q, 6);  /* size 6 = 5 usable slots (circular wastes 1) */

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);  /* Queue is Full */

    Display(q);
    printf("%d\n", dequeue(&q));
    Display(q);

    return 0;
}
