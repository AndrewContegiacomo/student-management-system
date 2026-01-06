#include <stdio.h>
#include <stdlib.h>
#include "../include/student.h"

int main() {
    int choice;

    // Main application loop
    do {
        // Display the menu options
        printf("\n=== Student Management System ===\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Update Student Details\n");
        printf("4. Delete Student\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");

        // Read user input
        if (scanf("%d", &choice) != 1) {
            // Input validation: if user enters a character instead of int
            printf("Invalid input! Please enter a number.\n");
            // Clear the input buffer to prevent infinite loop
            while(getchar() != '\n'); 
            continue;
        }

        // Handle user choice
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                updateStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 0:
                printf("Exiting the application. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 0); // Continue until user chooses 0

    return 0;
}
