#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

void search(struct node* root, int key) {
    if (root == NULL) {
        printf("NULL\n");
        return;
    }
    if (root->data == key) {
        printf("Found\n");
        return;
    } else if (key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}

struct node* deleteLeaf(struct node* root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->data)
        root->left = deleteLeaf(root->left, key);
    else if (key > root->data)
        root->right = deleteLeaf(root->right, key);
    else {
        if (root->left == NULL && root->right == NULL) {
            printf("Leaf node %d deleted successfully!\n", root->data);
            free(root);
            return NULL;
        } else {
            printf("Cannot delete %d as it is not a leaf node!\n", root->data);
        }
    }
    return root;
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct node* root = NULL;
    int n, value, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements to insert:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Enter value to search: ");
    scanf("%d", &key);
    search(root, key);

    printf("Enter value of leaf node to delete: ");
    scanf("%d", &key);
    root = deleteLeaf(root, key);

    printf("Inorder traversal after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}