#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
    int coeff;
    int exp;
    struct Node *next;
} *poly = NULL;

void create() {
    struct Node *t, *last = NULL;
    int num, i;
    printf("Enter number of terms: ");
    scanf("%d", &num);
    printf("Enter each term (coeff exp):\n");
    for (i = 0; i < num; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->next = NULL;
        scanf("%d %d", &t->coeff, &t->exp);
        if (poly == NULL)
            poly = last = t;
        else {
            last->next = t;
            last = t;
        }
    }
}

void Display(struct Node *p) {
    while (p) {
        printf("%dx^%d", p->coeff, p->exp);
        if (p->next) printf(" + ");
        p = p->next;
    }
    printf("\n");
}

long Eval(struct Node *p, int x) {
    long val = 0;
    while (p) {
        val += p->coeff * (long)pow(x, p->exp);
        p = p->next;
    }
    return val;
}

int main() {
    create();
    Display(poly);
    printf("Value at x=1: %ld\n", Eval(poly, 1));
    printf("Value at x=2: %ld\n", Eval(poly, 2));
    return 0;
}
