#include <stdio.h>

int main() {
    int n, i, key, low, high, mid;
    printf("Enter size of array:");
    scanf("%d", &n);

    int arr[n];
    printf("Enter Element of array:");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter search value:");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    printf("Searching between indexes[%d-%d]\n\n", low, high);

    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    while(low <= high) {
        mid = (low + high) / 2;

        if(arr[mid] == key) {
            printf("Midpoint value %d is match with target %d\n", arr[mid], key);
            printf("%d is found in array\n", key);
            return 0;
        } 
        else if(arr[mid] < key) {
            printf("Targeted value %d is greater than midpoint \n", arr[mid]);
            printf("Value %d search right side\n", arr[mid]);
            low = mid + 1;
            printf("Searching between indexes [%d-%d]\n", low, high);
        } 
        else {
            printf("Targeted value %d is smaller than midpoint \n", arr[mid]);
            printf("Value %d search left side\n", arr[mid]);
            high = mid - 1;
            printf("Searching between indexes [%d-%d]\n", low, high);
        }
    }

    printf("%d is not found in array\n", key);
    return 0;
}