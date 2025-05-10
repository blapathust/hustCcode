#include <stdio.h>
#include <stdlib.h>

typedef struct plate {

    int val;

    struct plate* next;
}plate;

plate* top;
plate* bottom;

void push(int value) {

    if (top == NULL) return;

    plate* newPlate = (plate*) malloc(sizeof(plate));

    newPlate->val = value;

    top->next = newPlate;

    top = newPlate;
}

void pop() {

    if (bottom == NULL) return;

    plate* removed = bottom;

    bottom = bottom->next;

    if (bottom == NULL) top = NULL;

    free(removed);
}

int main() {

    return 0;
}
