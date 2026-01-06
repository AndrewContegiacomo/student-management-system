#ifndef STUDENT_H
#define STUDENT_H

// Maximum lengths for string buffers
#define MAX_NAME_LEN 50
#define FILE_NAME "students.txt"

// Structure representing a single student record
typedef struct {
    int roll_number;             // Unique ID for the student
    char name[MAX_NAME_LEN];     // Student's full name
    float grade;                 // Student's grade or GPA
} Student;

// Function Prototypes

void addStudent();       // Create a new record
void viewStudents();     // Read and display all records
void updateStudent();    // Modify an existing record
void deleteStudent();    // Remove a record

#endif // STUDENT_H
