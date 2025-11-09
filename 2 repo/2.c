#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int ele) {
    if (top == MAX - 1) {
        printf("overflow\n");
        return;
    }
    stack[++top] = ele;
    printf("[%d]\n", ele);
}

void pop() {
    if (top == -1) {
        printf("underflow\n");
        return;
    }
    printf("deleted %d\n", stack[top--]);
}

void display() {
    if (top == -1) {
        printf("empty\n");
        return;
    }
    printf("[");
    for (int i = 0; i <= top; i++) {
        printf("%d", stack[i]);
        if (i != top) printf(", ");
    }
    printf("]\n");
}

int isPalindrome() {
    int i = 0, j = top;
    while (i < j) {
        if (stack[i] != stack[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}

int main() {
    int ch, ele;
    while (1) {
        printf("enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("enter: ");
                scanf("%d", &ele);
                push(ele);
                break;
            case 2:
                pop();
                break;
            case 3:
                if (isPalindrome())
                    printf("palindrome\n");
                else
                    printf("not palindrome\n");
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("invalid\n");
        }
    }
}

