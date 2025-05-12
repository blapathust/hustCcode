#include <stdio.h>
#include <stdlib.h>

typedef struct node {

    int val;

    struct node* leftmostChild;
    struct node* rightSibling;
    struct node* parent;
}node;

node* root;

node* dfs(node* curr, int value) {

    if (curr == NULL) return NULL;

    if (curr->val == value) return curr;

    node* target;

    if (curr->leftmostChild != NULL) {

        target = dfs(curr->leftmostChild, value);

        if (target != NULL) return target;
    }

    return dfs(curr->rightSibling, value);
}

node* create(int value) {

    node* created = (node*) malloc((sizeof(node)));

    created->val = value;
    created->parent = NULL;
    created->leftmostChild = NULL;
    created->rightSibling = NULL;
    
    return created;
}

node* add(int target, int value) {

    node* father = dfs(root, target);

    if (father == NULL) return NULL;

    node* created = create(value);

    created->parent = father;

    if (father->leftmostChild == NULL) father->leftmostChild = created;
    else {

        node* curr = father->leftmostChild;

        while(curr->rightSibling) curr = curr->rightSibling;

        curr->rightSibling = created;
    }

    return created;
}

int depth(int target, node* curr, int currDepth) {

    if (curr == NULL) curr = dfs(root, target);
    if (curr == NULL) return -1;

    if (curr == root) return currDepth;

    return depth(target, curr->parent, currDepth + 1);
}

int height(int target, node* curr, int currHeight) {

    if (curr == NULL) curr = dfs(root, target);
    if (curr == NULL) return -1;

    if (curr->leftmostChild == NULL) return currHeight;

    int maxHeight = currHeight;
    node* child = curr->leftmostChild;

    while(child != NULL) {

        int result = height(target, child, currHeight + 1);

        if (result > maxHeight) maxHeight = result;

        child = child->rightSibling;
    }

    return maxHeight;
}

void preOrder(node* curr) {

    if (curr == NULL) return;

    printf("%i ", curr->val);

    node* child;

    if ((child = curr->leftmostChild) != NULL) while (child != NULL) {

        preOrder(child);

        child = child->rightSibling;
    }
}

void postOrder(node* curr) {

    if (curr == NULL) return;

    node* child;

    if ((child = curr->leftmostChild) != NULL) while (child != NULL) {

        postOrder(child);

        child = child->rightSibling;
    }

    printf("%i ", curr->val);
}

void inOrder(node* curr) {

    if (curr == NULL) return;

    if (curr->leftmostChild == NULL) printf("%i\n", curr->val);

    else {

        node* child = curr->leftmostChild;

        inOrder(child);

        child = child->rightSibling;

        printf("%i\n", curr->val);

        while (child != NULL) {

            inOrder(child);

            child = child->rightSibling;
        }
    }
}

int main() {

    return 0;
}
