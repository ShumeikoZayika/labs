#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node *next;
} *top = NULL;

/* ── Stack primitives ─────────────────────────────────────── */

void push(int x) {
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("Stack is full\n");
    else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop() {
    struct Node *t;
    int x = -1;
    if (top == NULL)
        printf("Stack is Empty\n");
    else {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

void Display() {
    struct Node *p;
    p = top;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

/* ── isBalanced: check balanced parentheses ───────────────── */

int isBalanced(char *exp) {
    int i;
    for (i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(')
            push(exp[i]);
        else if (exp[i] == ')') {
            if (top == NULL)
                return 0;
            pop();
        }
    }
    if (top == NULL)
        return 1;
    else
        return 0;
}

/* ── Infix to Postfix conversion ──────────────────────────── */

int pre(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

int isOperand(char x) {
    if (x >= 'a' && x <= 'z') return 1;
    if (x >= 'A' && x <= 'Z') return 1;
    if (x >= '0' && x <= '9') return 1;
    return 0;
}

char *InToPost(char *infix) {
    int i = 0, j = 0;
    char *postfix;
    int len = strlen(infix);
    postfix = (char *)malloc((len + 1) * sizeof(char));
    push('#');

    while (infix[i] != '\0') {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else {
            if (pre(infix[i]) > pre(top->data))
                push(infix[i++]);
            else
                postfix[j++] = pop();
        }
    }
    while (top->data != '#')
        postfix[j++] = pop();
    pop();          /* remove '#' */
    postfix[j] = '\0';
    return postfix;
}

/* ── Postfix Evaluation ───────────────────────────────────── */

int Eval(char *postfix) {
    int i = 0;
    int x1, x2, r;

    for (i = 0; postfix[i] != '\0'; i++) {
        if (isOperand(postfix[i]))
            push(postfix[i] - '0');
        else {
            x2 = pop();
            x1 = pop();
            switch (postfix[i]) {
                case '+': r = x1 + x2; break;
                case '-': r = x1 - x2; break;
                case '*': r = x1 * x2; break;
                case '/': r = x1 / x2; break;
            }
            push(r);
        }
    }
    return top->data;
}

/* ── main ─────────────────────────────────────────────────── */

int main() {
    char *postfix = "234*+82/-";

    printf("Result is %d\n", Eval(postfix));   /* expects 10 */

    return 0;
}
