#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {

    int val;

    struct node* left;
    struct node* right;
}node;

node* root = NULL;

node* dfs(int target, node* curr) {

    if (curr == NULL) return NULL;

    if (curr->val == target) return curr;

    node* found = dfs(target, curr->left);

    if (found == NULL) return dfs(target, curr->right);

    return found;
}

node* create(int value) {

    node* created = (node*) malloc(sizeof(node));

    created->val = value;
    created->left = NULL;
    created->right = NULL;

    return created;
}

node* insert(int target, int value, bool isLeft) {

    if (dfs(value, root) != NULL) return NULL; //prevents duplicate node

    node* subject = dfs(target, root);

    if (subject == NULL) return NULL;

    if (isLeft && subject->left != NULL) return NULL; //only adds new node
    if (!isLeft && subject->right != NULL) return NULL; //if position is free

    node* created = create(value);

    if (isLeft) subject->left = created;
    else subject->right = created;

    return created;
}

void preOrder(node* curr) {

    if (curr == NULL) return;

    printf("%i ", curr->val);

    preOrder(curr->left);
    preOrder(curr->right);
}

void postOrder(node* curr) {

    if (curr == NULL) return;

    postOrder(curr->left);
    postOrder(curr->right);

    printf("%i ", curr->val);
}

void inOrder(node* curr) {

    if (curr == NULL) return;

    inOrder(curr->left);

    printf("%i ", curr->val);

    inOrder(curr->right);
}

int depthDFS(int target, node* curr, int depth) {

    if (curr == NULL) return -1;

    if (curr->val == target) return depth;

    int found = depthDFS(target, curr->left, depth + 1);

    if (found == -1) return depthDFS(target, curr->right, depth + 1);

    return found;
}

int heightDFS(node* curr, int height) {

    if (curr == NULL) return -1;

    if (curr->left == NULL && curr->right == NULL) return height;

    int maxHeight = height;

    int leftHeight = -1;
    int rightHeight = -1;

    if (curr->left != NULL) leftHeight = heightDFS(curr->left, height + 1);
    if (curr->right != NULL) rightHeight = heightDFS(curr->right, height + 1);

    if (leftHeight > maxHeight) maxHeight = leftHeight;
    if (rightHeight > maxHeight) maxHeight = rightHeight;

    return maxHeight;
}

bool isBalanced(node* curr) {

    if (curr == NULL) return true;

    if (curr->left == NULL && curr->right != NULL) return false;
    if (curr->left != NULL && curr->right == NULL) return false;

    bool leftSubTree = isBalanced(curr->left);
    bool rightSubTree = isBalanced(curr->right);

    if (!leftSubTree) return false;
    if (!rightSubTree) return false;

    int leftHeight = 0;

    if ((leftHeight = heightDFS(curr->left, 1)) == heightDFS(curr->right, 1)) return true;

    return false;
}

int main() {

    return 0;
}
