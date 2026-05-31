#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int size;
    int top;
    int *S;
};

void create(struct Stack *st) {
    printf("Enter Size: ");
    scanf("%d", &st->size);
    st->S = (int *)malloc(st->size * sizeof(int));
    st->top = -1;
}

int isEmpty(struct Stack st) {
    return st.top == -1;
}

int isFull(struct Stack st) {
    return st.top == st.size - 1;
}

void push(struct Stack *st, int x) {
    if (isFull(*st))
        printf("Stack Overflow\n");
    else {
        st->top++;
        st->S[st->top] = x;
    }
}

int pop(struct Stack *st) {
    int x = -1;
    if (isEmpty(*st))
        printf("Stack Underflow\n");
    else
        x = st->S[st->top--];
    return x;
}

int peek(struct Stack st, int index) {
    if (isEmpty(st))
        return -1;
    return st.S[st.top - index + 1];
}

int stackTop(struct Stack st) {
    if (isEmpty(st))
        return -1;
    return st.S[st.top];
}

void Display(struct Stack st) {
    int i;
    for (i = st.top; i >= 0; i--)
        printf("%d ", st.S[i]);
    printf("\n");
}

int main() {
    struct Stack st;
    create(&st);

    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);

    printf("%d\n", peek(st, 2));
    printf("%d\n", pop(&st));
    printf("%d\n", pop(&st));

    Display(st);

    return 0;
}
