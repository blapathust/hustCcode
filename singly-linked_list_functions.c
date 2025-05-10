#include <stdio.h>
#include <stdlib.h>

typedef struct node {

    int val;

    struct node* next;
} node;

node* head;

node* searchVal(node* curr, int value) {

    if (curr == NULL) return NULL;

    if (curr->val == value) return curr;

    return searchVal(curr->next, value);
}

node* searchPtr(node* curr, node* target) {

    if (curr->next == NULL) return NULL;

    if (curr->next == target) return curr;

    return searchPtr(curr->next, target);
}

void addNode(int u, int v) {

    node* target;

    if ((target = searchVal(head, u)) != NULL) {

        node* temp = target->next;

        target->next = (node*) malloc(sizeof(node));

        target->next->val = v;
        target->next->next = temp;
    }
}

void removeNode(int u) {

    node* target = searchVal(head, u);

    if (target != NULL) {

        if (target == head) {

            head = target->next;

            free(target);
        }
        else {

            node* prev = searchPtr(head, target);

            prev->next = target->next;

            free(target);
        }
    }
}

node* reverse(node* curr, node* currHead) {

    if (curr->next == NULL) {

        head = curr;

        currHead->next = NULL;

        return curr;
    }

    node* newPrev = reverse(curr->next, currHead);

    newPrev->next = curr;

    return curr;
}

int main() {

    return 0;
}
