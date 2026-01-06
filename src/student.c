#include <stdio.h>
#include "../include/student.h" // Include the local header

// Placeholder implementation for adding a student
void addStudent() {
    Student s;
    FILE *fp;

    // Input Data
    printf("Enter Roll Number (ID): ");
    scanf("%d", &s.roll_number);
    
    printf("Enter Name (single word): ");
    scanf("%s", s.name); 
    
    printf("Enter Grade: ");
    scanf("%f", &s.grade);

    // Open File
    fp = fopen(FILE_NAME, "a"); 

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Edit File
    fprintf(fp, "%d %s %.2f\n", s.roll_number, s.name, s.grade);

    // Close
    printf("Student added successfully!\n");
    fclose(fp);
}

// Placeholder implementation for viewing students
void viewStudents() {
    Student s;
    FILE *fp;

    //Open File Read Mode
    fp = fopen(FILE_NAME, "r");

    if (fp == NULL) {
        printf("No records found! (File does not exist)\n");
        return;
    }

    printf("\n--- List of Students ---\n");
    // Print table header
    printf("%-10s %-20s %-10s\n", "Roll No", "Name", "Grade");
    printf("------------------------------------------\n");

    // Read Loop
    while (fscanf(fp, "%d %s %f", &s.roll_number, s.name, &s.grade) != EOF) {
        
        // Print the current record formatted to the screen
        printf("%-10d %-20s %-10.2f\n", s.roll_number, s.name, s.grade);
    }

    printf("------------------------------------------\n");
    // Close File
    fclose(fp);
}

void updateStudent() {
    Student s;
    FILE *fp, *tempFp;
    int id_to_change;
    int found = 0;

    printf("Enter Roll Number to change: ");
    scanf("%d", &id_to_change);

    //Open original file (Read) and temp file (Write)
    fp = fopen(FILE_NAME, "r");
    tempFp = fopen("temp.txt", "w");

    if (fp == NULL || tempFp == NULL) {
        printf("Error opening files.\n");
        if (fp) fclose(fp); // Close fp if it was opened successfully
        return;
    }

    // Copy all students EXCEPT the one to delete
    while (fscanf(fp, "%d %s %f", &s.roll_number, s.name, &s.grade) != EOF) {
        if (s.roll_number != id_to_change) {
            fprintf(tempFp, "%d %s %.2f\n", s.roll_number, s.name, s.grade);
        } else {
            
            printf("Current Information:\n");
            printf("%d %s %.2f\n", s.roll_number, s.name, s.grade);

            printf("Enter new Roll Number (ID): ");
            scanf("%d", &s.roll_number);
    
            printf("Enter new Name (single word): ");
            scanf("%s", s.name); 
    
            printf("Enter new Grade: ");
            scanf("%f", &s.grade);

            fprintf(tempFp, "%d %s %.2f\n", s.roll_number, s.name, s.grade);
            found = 1; // Mark as found, skip writing to temp file
        }
    }

    // Close files to release locks
    fclose(fp);
    fclose(tempFp);

    // Replace original file with the updated temp file
    if (found) {
        remove(FILE_NAME);            // Delete old file
        rename("temp.txt", FILE_NAME); // Rename temp to original name
        printf("Success! Student with ID %d has been updated.\n", id_to_change);
    } else {
        remove("temp.txt");           // Delete unused temp file
        printf("Student with ID %d not found.\n", id_to_change);
    }
}

void deleteStudent(){
    Student s;
    FILE *fp, *tempFp;
    int id_to_delete;
    int found = 0;

    printf("Enter Roll Number to delete: ");
    scanf("%d", &id_to_delete);

    //Open original file (Read) and temp file (Write)
    fp = fopen(FILE_NAME, "r");
    tempFp = fopen("temp.txt", "w");

    if (fp == NULL || tempFp == NULL) {
        printf("Error opening files.\n");
        if (fp) fclose(fp); // Close fp if it was opened successfully
        return;
    }

    // Copy all students EXCEPT the one to delete
    while (fscanf(fp, "%d %s %f", &s.roll_number, s.name, &s.grade) != EOF) {
        if (s.roll_number != id_to_delete) {
            fprintf(tempFp, "%d %s %.2f\n", s.roll_number, s.name, s.grade);
        } else {
            found = 1; // Mark as found, skip writing to temp file
        }
    }

    // Close files to release locks
    fclose(fp);
    fclose(tempFp);

    // Replace original file with the updated temp file
    if (found) {
        remove(FILE_NAME);            // Delete old file
        rename("temp.txt", FILE_NAME); // Rename temp to original name
        printf("Success! Student with ID %d has been deleted.\n", id_to_delete);
    } else {
        remove("temp.txt");           // Delete unused temp file
        printf("Student with ID %d not found.\n", id_to_delete);
    }
}
