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
    printf("Student DataBase Management System\n");
    return 0;
}
