#include <stdio.h>
#define MAX 5

char queue[MAX];
int front = -1, rear = -1;

// Function to insert an element
void insert() {
    char item;
    if (rear == MAX - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    printf("Enter character to insert: ");
    scanf(" %c", &item);
    if (front == -1) front = 0;
    rear++;
    queue[rear] = item;
    printf("Inserted '%c' into queue.\n", item);
}

// Function to delete an element
void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow!\n");
        return;
    }
    printf("Deleted '%c' from queue.\n", queue[front]);
    front++;
}

// Function to display the queue
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue contents: ");
    for (int i = front; i <= rear; i++) {
        printf("%c ", queue[i]);
    }
    printf("\n");
}

// Main function with menu
int main() {
    int choice;
    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}