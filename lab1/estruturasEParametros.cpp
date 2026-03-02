#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Rectangle {
  int length;
  int breadth;
};

void *fun() {
  struct Rectangle *p;
  p = new Rectangle;

  p->length = 15;
  p->breadth = 7;
  return p;
}

int main() {
  struct Rectangle *ptr;
  ptr = fun();
  printf("Length %d\nBreadth %d\n", ptr->length, ptr->breadth);
  return 0;
}