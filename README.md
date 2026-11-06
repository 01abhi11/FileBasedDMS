# File-Based Student Database Management System

A menu-driven, console-based academic management system implemented in C. This project provides persistent storage for student records using direct binary file operations (`fopen`, `fread`, `fwrite`), ensuring data remains intact across program executions.

---

## 📌 Project Features

- **Add Student Record:** Register roll number, student name, branch, semester, and 5 subject marks with duplicate check and range validation.
- **Display All Records:** Read and display formatted tabular records from binary storage.
- **Search Student:** Quick lookup using unique roll numbers.
- **Update Student Record:** Modify student details or marks safely using temporary file replacement.
- **Delete Student Record:** Remove records safely without corrupting database integrity.
- **Calculate Academic Result:** Generate individual marksheets with total marks, percentage, grade (A–F), and pass/fail status.
- **Database Summary:** Aggregate metrics including total enrollment, class average percentage, and overall pass percentage.
- **Persistent Binary Storage:** Records are stored directly in `students.dat`.

---

## 🛠️ Tech Stack & Concepts

- **Language:** C (Standard C99 / C11)
- **Data Structures:** `struct Student` for structured record representation
- **File Handling:** Binary file operations (`rb`, `wb`, `ab`), `remove()`, and `rename()`
- **Input Validation:** Buffer clearing, duplicate key prevention, and mark range checking (0–100)

---

## 🚀 Getting Started

### Prerequisites
A working C compiler (`gcc` / `clang` / MinGW).

### Compilation
Compile the program using GCC:
```bash
gcc main.c -o main
