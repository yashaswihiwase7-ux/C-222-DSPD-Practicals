#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node* head = NULL;
    struct node* newnode;
    struct node* temp;
    int ele;
    int count = 0;
    printf("enter ele to enter");
    while (1) {
        scanf("%d", &ele);
        if (ele == 0) {
            break;
        }
        newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("memory allocation failed");
            break;
        }

        newnode->data = ele;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        count++;
    }

    printf("ele:");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf(" NULL ");

    printf(" TOTAL NO OF NODES %d\n", count);
    return 0;
}