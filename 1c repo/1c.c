#include <stdio.h>

struct student {
    int roll;
    char name[50];
    float averageMarks;
    int age;
};

void swap(struct student *a, struct student *b) {
    struct student temp = *a;
    *a = *b;
    *b = temp;
}

void sortByAverageMarks(struct student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].averageMarks < arr[j + 1].averageMarks)
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct student s[n];

    for (int i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Roll Number: ");
        scanf("%d", &s[i].roll);
        printf("Average Marks: ");
        scanf("%f", &s[i].averageMarks);
        printf("Age: ");
        scanf("%d", &s[i].age);
    }

    sortByAverageMarks(s, n);

    printf("\nStudents sorted by average marks (descending order):\n");
    printf("Name\tRoll No.\tAverageMarks\tAge\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t\t%.2f\t\t%d\n", s[i].name, s[i].roll, s[i].averageMarks, s[i].age);
    }

    return 0;
}