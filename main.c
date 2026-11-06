#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "students.dat"
#define TEMP_FILE "temp.dat"

// Structure to store student records
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

// Function prototypes
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();
void calculateResult();
void databaseSummary();
int isDuplicateRollNo(int rollNo);
char determineGrade(float percentage);

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

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer[cite: 1, 4]
            continue;
        }

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                calculateResult();
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

// Helper function to check if roll number already exists
int isDuplicateRollNo(int rollNo) {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        return 0; // File does not exist yet
    }

    struct Student temp;
    while (fread(&temp, sizeof(struct Student), 1, fp) == 1) {
        if (temp.rollNo == rollNo) {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}

// Helper function to assign grade
char determineGrade(float percentage) {
    if (percentage >= 90.0f) return 'A';
    if (percentage >= 80.0f) return 'B';
    if (percentage >= 70.0f) return 'C';
    if (percentage >= 60.0f) return 'D';
    return 'F';
}

// 1. Add Student Record
void addStudent() {
    struct Student s;
    FILE *fp;

    printf("\n--- Add Student Record ---\n");
    printf("Enter Roll Number: ");
    if (scanf("%d", &s.rollNo) != 1) {
        printf("Invalid roll number format!\n");
        while (getchar() != '\n');
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

    do {
        printf("Enter Semester (1-8): ");
        scanf("%d", &s.semester);
        if (s.semester < 1 || s.semester > 8) {
            printf("Invalid semester! Must be between 1 and 8.\n");
        }
    } while (s.semester < 1 || s.semester > 8);

    s.totalMarks = 0;
    for (int i = 0; i < 5; i++) {
        do {
            printf("Enter marks for Subject %d (0-100): ", i + 1);
            scanf("%f", &s.marks[i]);
            if (s.marks[i] < 0.0f || s.marks[i] > 100.0f) {
                printf("Invalid marks! Please enter a value between 0 and 100.\n");
            }
        } while (s.marks[i] < 0.0f || s.marks[i] > 100.0f);
        s.totalMarks += s.marks[i];
    }

    s.percentage = s.totalMarks / 5.0f;
    s.grade = determineGrade(s.percentage);

    fp = fopen(FILE_NAME, "ab");
    if (fp == NULL) {
        printf("Error: Could not open file for writing!\n");
        return;
    }

    fwrite(&s, sizeof(struct Student), 1, fp);
    fclose(fp);

    printf("\nStudent record added successfully!\n");
}

// 2. Display All Records
void displayStudents() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo database file found or no records available.\n");
        return;
    }

    struct Student s;
    int count = 0;

    printf("\n---------------------------------------------------------------------------------------\n");
    printf("%-8s %-20s %-10s %-5s %-12s %-12s %-6s\n", "Roll No", "Name", "Branch", "Sem", "Total Marks", "Percentage", "Grade");
    printf("---------------------------------------------------------------------------------------\n");

    while (fread(&s, sizeof(struct Student), 1, fp) == 1) {
        printf("%-8d %-20s %-10s %-5d %-12.2f %-12.2f %-6c\n",
               s.rollNo, s.name, s.branch, s.semester, s.totalMarks, s.percentage, s.grade);
        count++;
    }

    printf("---------------------------------------------------------------------------------------\n");
    if (count == 0) {
        printf("Database is empty.\n");
    } else {
        printf("Total records displayed: %d\n", count);
    }

    fclose(fp);
}

// 3. Search Student
void searchStudent() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records available to search.\n");
        return;
    }

    int rollNo, found = 0;
    struct Student s;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &rollNo);

    while (fread(&s, sizeof(struct Student), 1, fp) == 1) {
        if (s.rollNo == rollNo) {
            printf("\n--- Student Found ---\n");
            printf("Roll Number : %d\n", s.rollNo);
            printf("Name        : %s\n", s.name);
            printf("Branch      : %s\n", s.branch);
            printf("Semester    : %d\n", s.semester);
            printf("Marks       : %.1f, %.1f, %.1f, %.1f, %.1f\n",
                   s.marks[0], s.marks[1], s.marks[2], s.marks[3], s.marks[4]);
            printf("Total Marks : %.2f / 500\n", s.totalMarks);
            printf("Percentage  : %.2f%%\n", s.percentage);
            printf("Grade       : %c\n", s.grade);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No student record found with Roll Number %d.\n", rollNo);
    }

    fclose(fp);
}

// 4. Update Student Record
void updateStudent() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records available to update.\n");
        return;
    }

    FILE *tempFp = fopen(TEMP_FILE, "wb");
    if (tempFp == NULL) {
        printf("Error creating temporary file!\n");
        fclose(fp);
        return;
    }

    int rollNo, found = 0;
    struct Student s;

    printf("\nEnter Roll Number to update: ");
    scanf("%d", &rollNo);

    while (fread(&s, sizeof(struct Student), 1, fp) == 1) {
        if (s.rollNo == rollNo) {
            found = 1;
            printf("\nEnter New Name: ");
            scanf(" %[^\n]s", s.name);

            printf("Enter New Branch: ");
            scanf("%s", s.branch);

            do {
                printf("Enter New Semester (1-8): ");
                scanf("%d", &s.semester);
            } while (s.semester < 1 || s.semester > 8);

            s.totalMarks = 0;
            for (int i = 0; i < 5; i++) {
                do {
                    printf("Enter new marks for Subject %d (0-100): ", i + 1);
                    scanf("%f", &s.marks[i]);
                } while (s.marks[i] < 0.0f || s.marks[i] > 100.0f);
                s.totalMarks += s.marks[i];
            }

            s.percentage = s.totalMarks / 5.0f;
            s.grade = determineGrade(s.percentage);
        }
        fwrite(&s, sizeof(struct Student), 1, tempFp);
    }

    fclose(fp);
    fclose(tempFp);

    if (found) {
        remove(FILE_NAME);
        rename(TEMP_FILE, FILE_NAME);
        printf("\nStudent record updated successfully!\n");
    } else {
        remove(TEMP_FILE);
        printf("No record found with Roll Number %d.\n", rollNo);
    }
}

// 5. Delete Student Record
void deleteStudent() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records available to delete.\n");
        return;
    }

    FILE *tempFp = fopen(TEMP_FILE, "wb");
    if (tempFp == NULL) {
        printf("Error creating temporary file!\n");
        fclose(fp);
        return;
    }

    int rollNo, found = 0;
    struct Student s;

    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &rollNo);

    while (fread(&s, sizeof(struct Student), 1, fp) == 1) {
        if (s.rollNo == rollNo) {
            found = 1; // Skip writing this record to temp file
        } else {
            fwrite(&s, sizeof(struct Student), 1, tempFp);
        }
    }

    fclose(fp);
    fclose(tempFp);

    if (found) {
        remove(FILE_NAME);
        rename(TEMP_FILE, FILE_NAME);
        printf("\nRecord with Roll Number %d deleted successfully!\n", rollNo);
    } else {
        remove(TEMP_FILE);
        printf("No record found with Roll Number %d.\n", rollNo);
    }
}

// 6. Calculate Academic Result
void calculateResult() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records available.\n");
        return;
    }

    int rollNo, found = 0;
    struct Student s;

    printf("\nEnter Roll Number for Result Card: ");
    scanf("%d", &rollNo);

    while (fread(&s, sizeof(struct Student), 1, fp) == 1) {
        if (s.rollNo == rollNo) {
            found = 1;
            printf("\n========================================\n");
            printf("            ACADEMIC REPORT             \n");
            printf("========================================\n");
            printf("Roll No     : %d\n", s.rollNo);
            printf("Name        : %s\n", s.name);
            printf("Branch      : %s | Sem: %d\n", s.branch, s.semester);
            printf("----------------------------------------\n");
            for (int i = 0; i < 5; i++) {
                printf("Subject %d   : %.2f\n", i + 1, s.marks[i]);
            }
            printf("----------------------------------------\n");
            printf("Total Marks : %.2f / 500\n", s.totalMarks);
            printf("Percentage  : %.2f%%\n", s.percentage);
            printf("Grade       : %c\n", s.grade);
            printf("Status      : %s\n", (s.grade == 'F') ? "FAILED" : "PASSED");
            printf("========================================\n");
            break;
        }
    }

    if (!found) {
        printf("No student record found with Roll Number %d.\n", rollNo);
    }

    fclose(fp);
}

// 7. Database Summary
void databaseSummary() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records in database to summarize.\n");
        return;
    }

    struct Student s;
    int count = 0;
    float sumPercentage = 0.0f;
    int passedCount = 0;

    while (fread(&s, sizeof(struct Student), 1, fp) == 1) {
        count++;
        sumPercentage += s.percentage;
        if (s.grade != 'F') {
            passedCount++;
        }
    }

    fclose(fp);

    if (count == 0) {
        printf("\nDatabase is empty.\n");
        return;
    }

    printf("\n========================================\n");
    printf("            DATABASE SUMMARY            \n");
    printf("========================================\n");
    printf("Total Students Registered : %d\n", count);
    printf("Average Percentage        : %.2f%%\n", sumPercentage / count);
    printf("Students Passed           : %d\n", passedCount);
    printf("Students Failed           : %d\n", count - passedCount);
    printf("Pass Percentage           : %.2f%%\n", ((float)passedCount / count) * 100.0f);
    printf("========================================\n");
}
