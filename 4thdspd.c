#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *next;
};

struct node *start = NULL;

void add(int x) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->num = x;
    new->next = NULL;

    if (start == NULL) {
        start = new;
    } else {
        struct node *temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new;
    }
}

void show() {
    struct node *temp = start;
    int total = 0;

    printf("\nlist: ");
    while (temp != NULL) {
        printf("%d", temp->num);
        total++;
        if (temp->next != NULL) {
            printf(" => ");
        } else {
            printf(" => null");
        }
        temp = temp->next;
    }

    printf("\ntotal nodes: %d\n", total);
}

void clean() {
    struct node *temp = start;
    while (temp != NULL) {
        struct node *next = temp->next;
        free(temp);
        temp = next;
    }
    start = NULL;
}

int main() {
    int val;
    printf("type numbers (0 to stop):\n");

    while (1) {
        printf("number: ");
        if (scanf("%d", &val) != 1) {
            printf("wrong input. bye.\n");
            while (getchar() != '\n');
            clean();
            return 1;
        }

        if (val == 0) {
            break;
        }

        add(val);
    }

    show();
    clean();
    return 0;
}