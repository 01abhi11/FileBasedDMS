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

// Helper function to check if a roll number is already in the file[cite: 32]
int isDuplicateRollNo(int rollNo) {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        return 0; // File does not exist yet, so no duplicates possible
    }

    struct Student temp;
    while (fread(&temp, sizeof(struct Student), 1, fp) == 1) {
        if (temp.rollNo == rollNo) {
            fclose(fp);
            return 1; // Duplicate found
        }
    }

    fclose(fp);
    return 0;
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

void addStudent() {
    struct Student s;
    FILE *fp;

    printf("\n--- Add Student Record ---\n");
    printf("Enter Roll Number: ");
    if (scanf("%d", &s.rollNo) != 1) {
        printf("Invalid input for roll number!\n");
        while (getchar() != '\n'); // clear buffer
        return;
    }

    if (isDuplicateRollNo(s.rollNo)) {
        printf("Error: Student with Roll Number %d already exists!\n", s.rollNo);
        return;
    }

    printf("Enter Student Name: ");
    scanf(" %[^\n]s", s.name);

    printf("Enter Branch: ");
    scanf("%s", s.branch);

    printf("Enter Semester (1-8): ");
    scanf("%d", &s.semester);

    s.totalMarks = 0;
    for (int i = 0; i < 5; i++) {
        do {
            printf("Enter marks for Subject %d (0-100): ", i + 1);
            scanf("%f", &s.marks[i]);
            if (s.marks[i] < 0 || s.marks[i] > 100) {
                printf("Invalid marks! Please enter a value between 0 and 100.\n");
            }
        } while (s.marks[i] < 0 || s.marks[i] > 100);
        s.totalMarks += s.marks[i];
    }

    s.percentage = s.totalMarks / 5.0f;

    // Grade assignment
    if (s.percentage >= 90) s.grade = 'A';
    else if (s.percentage >= 80) s.grade = 'B';
    else if (s.percentage >= 70) s.grade = 'C';
    else if (s.percentage >= 60) s.grade = 'D';
    else s.grade = 'F';

    // Append record to file
    fp = fopen(FILE_NAME, "ab");
    if (fp == NULL) {
        printf("Error: Could not open file for writing!\n");
        return;
    }

    fwrite(&s, sizeof(struct Student), 1, fp);
    fclose(fp);

    printf("\nStudent record added successfully!\n");
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
