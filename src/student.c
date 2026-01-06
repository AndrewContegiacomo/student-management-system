#include <stdio.h>
#include "../include/student.h" // Include the local header

// Placeholder implementation for adding a student
void addStudent() {
    Student s;
    FILE *fp;

    // 1. Input Data
    printf("Enter Roll Number (ID): ");
    scanf("%d", &s.roll_number);
    
    printf("Enter Name (single word): ");
    scanf("%s", s.name); 
    
    printf("Enter Grade: ");
    scanf("%f", &s.grade);

    // 2. Open File
    fp = fopen(FILE_NAME, "a"); 

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // 3. Edit File
    //
    fprintf(fp, "%d %s %.2f\n", s.roll_number, s.name, s.grade);

    // 4. Close
    printf("Student added successfully!\n");
    fclose(fp);
}

// Placeholder implementation for viewing students
void viewStudents() {
    void viewStudents() {
    Student s;
    FILE *fp;

    // 1. OPEN FILE IN READ MODE
    fp = fopen(FILE_NAME, "r");

    if (fp == NULL) {
        printf("No records found! (File does not exist)\n");
        return;
    }

    printf("\n--- List of Students ---\n");
    // Print table header
    printf("%-10s %-20s %-10s\n", "Roll No", "Name", "Grade");
    printf("------------------------------------------\n");

    // 2. READ LOOP
    while (fscanf(fp, "%d %s %f", &s.roll_number, s.name, &s.grade) != EOF) {
        
        // Print the current record formatted to the screen
        printf("%-10d %-20s %-10.2f\n", s.roll_number, s.name, s.grade);
    }

    printf("------------------------------------------\n");
    // 3. CLOSE FILE
    fclose(fp);
}

// Placeholder implementation for updating a student
void updateStudent() {
    printf("\n[DEBUG] Function updateStudent called.\n");
}

// Placeholder implementation for deleting a student
void deleteStudent() {
    printf("\n[DEBUG] Function deleteStudent called.\n");
}
