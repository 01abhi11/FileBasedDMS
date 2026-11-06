#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "students.dat"

//Structure to store student records:
struct Student {
    int rollNo;
    char name[50];
    char branch[20];
    int semester;
    float marks[5];
    float totalMarks;
    float percentage;
    char grade;

};

//Function prototypes:
void addStudent();
void displayStudents();
void searchStudents();
void updateStudents();
void deleteStudents();
void calculateResults();
void databaseSummary();


int main() {
    int choice;

    do {
        printf("\n========================================\n");
        printf(" File-Based Student Database Management \n");
        printf("========================================\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Student\n");
        printf("4. Update Student Record\n");
        printf("5. Delete Student Record\n");
        printf("6. Calculate Academic Result\n");
        printf("7. Database Summary\n");
        printf("8. Exit\n");
        printf("----------------------------------------\n");
        printf("Enter your choice (1-8): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudents();
                break;
            case 4:
                updateStudents();
                break;
            case 5:
                deleteStudents();
                break;
            case 6:
                calculateResults();
                break;
            case 7:
                databaseSummary();
                break;
            case 8:
                printf("\nExiting program. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please select between 1 and 8.\n");
        }
    } while (choice != 8);

    return 0;
}

void addStudent() {
    printf("\n[Feature: Add Student - coming next]\n");
}

void displayStudents() {
    printf("\n[Feature: Display Students - coming soon]\n");
}

void searchStudents() {
    printf("\n[Feature: Search Student - coming soon]\n");
}

void updateStudents() {
    printf("\n[Feature: Update Student - coming soon]\n");
}

void deleteStudents() {
    printf("\n[Feature: Delete Student - coming soon]\n");
}

void calculateResults() {
    printf("\n[Feature: Calculate Results - coming soon]\n");
}

void databaseSummary() {
    printf("\n[Feature: Database Summary - coming soon]\n");
}
