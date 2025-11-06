#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int element) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", element);
        return;
    }
    stack[++top] = element;
    printf("%d pushed onto stack.\n", element);
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow! Cannot pop element.\n");
        return -1;
    }
    int popped = stack[top--];
    printf("%d popped from stack.\n", popped);
    return popped;
}

void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

bool isPalindrome(int arr[], int n) {
    int i = 0, j = n - 1;
    while (i < j) {
        if (arr[i] != arr[j])
            return false;
        i++;
        j--;
    }
    return true;
}

void checkPalindrome() {
    if (top == -1) {
        printf("Stack is empty. Cannot check palindrome.\n");
        return;
    }
    int n = top + 1;
    int temp[MAX];
    for (int i = 0; i < n; i++) {
        temp[i] = stack[i];
    }
    if (isPalindrome(temp, n))
        printf("Stack elements form a palindrome.\n");
    else
        printf("Stack elements do not form a palindrome.\n");
}

void menu() {
    int choice, element;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Push an Element onto Stack\n");
        printf("2. Pop an Element from Stack\n");
        printf("3. Check if Stack elements form a Palindrome\n");
        printf("4. Display Stack status\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); // clear invalid input
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                if (scanf("%d", &element) != 1) {
                    while (getchar() != '\n');
                    printf("Invalid input. Please enter an integer.\n");
                    continue;
                }
                push(element);
                break;
            case 2:
                pop();
                break;
            case 3:
                checkPalindrome();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                return;
            default:
                printf("Invalid choice. Please select from menu.\n");
        }
    }
}
int main() {
    menu();
    return 0;
}

