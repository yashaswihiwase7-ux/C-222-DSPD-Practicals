#include <stdio.h>
#define size 7

int arr[size];

void init() {
    for (int i = 0; i < size; i++)
        arr[i] = -1;
}

int h(int k) {
    return k % size;
}

void insert(int k) {
    int i = h(k);
    int s = i;
    while (arr[i] != -1) {
        i = (i + 1) % size;
        if (i == s) {
            printf("full! %d\n", k);
            return;
        }
    }
    arr[i] = k;
    printf("added %d at %d\n", k, i);
}

void show() {
    printf("\nslot : val\n");
    for (int i = 0; i < size; i++) {
        if (arr[i] == -1)
            printf("%2d : empty\n", i);
        else
            printf("%2d : %d\n", i, arr[i]);
    }
}

int main() {
    int n, k;
    init();
    printf("how many keys: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("key %d: ", i + 1);
        scanf("%d", &k);
        insert(k);
    }

    show();
    return 0;
}