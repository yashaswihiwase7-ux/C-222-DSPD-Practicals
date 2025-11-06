#include <stdio.h>

int main() {
 int n;
printf("Enter the number of elements: ");
 scanf("%d", &n);
int arr[n];
 printf("Enter %d numbers:\n", n);
 for (int i = 0; i < n; i++) {
 scanf("%d", &arr[i]);
    }
   int sum_odd = 0, sum_even = 0;
    for (int i = 0; i < n; i++) {
        if ((i + 1) % 2 == 1) {
            sum_odd += arr[i];
        } else {
            sum_even += arr[i];
        }
    }
printf("Sum of numbers at odd positions: %d\n", sum_odd);
printf("Sum of numbers at even positions: %d\n", sum_even);
  return 0;
}

