#include <stdio.h>
#define max 5

char q[max];
int front = -1, rear = -1;

void insert() {
    char ch;
    if (rear == max - 1)
        printf("overflow\n");
    else {
        if (front == -1) front = 0;
        printf("enter data: ");
        scanf(" %c", &ch);
        q[++rear] = ch;
        printf("data inserted\n");
        printf("current queue: ");
        for (int i = front; i <= rear; i++)
            printf("%c ", q[i]);
        printf("\n");
    }
}

void del() {
    if (front == -1 || front > rear)
        printf("underflow\n");
    else {
        printf("deleted: %c\n", q[front++]);
        if (front > rear)
            front = rear = -1;
    }
}

void disp() {
    if (front == -1)
        printf("empty\n");
    else {
        printf("queue: ");
        for (int i = front; i <= rear; i++)
            printf("%c ", q[i]);
        printf("\n");
    }
}

int main() {
    int ch;
    while (1) {
        printf("\n1.insert 2.delete 3.display 4.exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1: insert(); break;
            case 2: del(); break;
            case 3: disp(); break;
            case 4: return 0;
            default: printf("wrong\n");
        }
    }
}