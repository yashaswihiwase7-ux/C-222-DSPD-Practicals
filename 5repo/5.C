#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* createNode() {
    int v;
    printf("Val (-1 = no): ");
    scanf("%d", &v);

    if (v == -1)
        return NULL;

    struct node* t = (struct node*)malloc(sizeof(struct node));
    t->data = v;

    printf("L(%d): ", v);
    t->left = createNode();

    printf("R(%d): ", v);
    t->right = createNode();

    return t;
}

void inorder(struct node* r) {
    if (r != NULL) {
        inorder(r->left);
        printf("%d ", r->data);
        inorder(r->right);
    }
}

void preorder(struct node* r) {
    if (r != NULL) {
        printf("%d ", r->data);
        preorder(r->left);
        preorder(r->right);
    }
}

void postorder(struct node* r) {
    if (r != NULL) {
        postorder(r->left);
        postorder(r->right);
        printf("%d ", r->data);
    }
}

void search(struct node* r, int key) {
    if (r == NULL) {
        printf("No\n");
        return;
    }
    if (r->data == key) {
        printf("Yes\n");
        return;
    }
    if (key < r->data)
        search(r->left, key);
    else
        search(r->right, key);
}

int main() {
    int k;

    printf("Tree:\n");
    struct node* root = createNode();

    printf("\nIn: ");
    inorder(root);

    printf("\nPre: ");
    preorder(root);

    printf("\nPost: ");
    postorder(root);

    printf("\nFind: ");
    scanf("%d", &k);
    search(root, k);

    return 0;
}
