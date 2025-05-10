#include <stdio.h>
#include <stdlib.h>

typedef struct plate {

    int val;

    struct plate* next;
}plate;

plate* top;

void push() {

    if (top == NULL) return;

    plate* newPlate = (plate*) malloc(sizeof(plate));

    newPlate->next = top;

    top = newPlate;
}

void pop() {

    if (top == NULL) return;

    plate* removed = top;

    top = top->next;

    free(removed);
}

int main() {

    return 0;
}
