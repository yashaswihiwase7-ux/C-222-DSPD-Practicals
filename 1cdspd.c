#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int roll;
    float avgMarks;
    int age;
} Student;

void bubbleSort(Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].avgMarks < arr[j + 1].avgMarks) {
                Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    Student students[n];

    for (int i = 0; i < n; i++) {
        printf("Enter name, roll, avgMarks and age for student %d:\n", i + 1);
        scanf("%s %d %f %d", students[i].name, &students[i].roll, &students[i].avgMarks, &students[i].age);
    }

    bubbleSort(students, n);

    printf("\nStudents sorted by average marks in descending order:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s, Roll: %d, Avg Marks: %.2f, Age: %d\n", students[i].name, students[i].roll, students[i].avgMarks, students[i].age);
    }

    return 0;
}
