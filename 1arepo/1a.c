#include <stdio.h>

int main() {
    int arr[100], sumeven = 0, sumodd = 0, i, n;
    printf("enter the size of array");
    scanf("%d", &n);
    printf("enter the element");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++) {
        if (i % 2 == 0) {
            sumeven += arr[i];
        }
        if (i % 2 != 0) {
            sumodd += arr[i];
        }
    }
    printf("sumeven: %d\n", sumeven);
    printf("sumodd: %d\n", sumodd);
    return 0;
}