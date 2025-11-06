#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int size;
} SearchList;

typedef int Comparable;

int* binarySearch(SearchList *list, Comparable *value) {
    if (list == NULL || value == NULL || list->array == NULL || list->size == 0) {
        return NULL;
    }

    int start = 0;
    int end = list->size;

    while (start < end) {
        int mid = start + (end - start) / 2;
        printf("Midpoint value: %d\n", list->array[mid]);
        if (list->array[mid] == *value) {
            return &list->array[mid];
        } else if (*value > list->array[mid]) {
            start = mid + 1;
            printf("Adjust start to index: %d\n", start);
        } else {
            end = mid;
            printf("Adjust end to index: %d\n", end);
        }
    }

    return NULL;
}

int main() {
    int n;
    printf("Enter number of elements in the list: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    Comparable target;
    printf("Enter value to search: ");
    scanf("%d", &target);

    SearchList list = {arr, n};
    int *result = binarySearch(&list, &target);

    if (result != NULL) {
        printf("Found value: %d\n", *result);
    } else {
        printf("Value not found\n");
    }

    free(arr);
    return 0;
}