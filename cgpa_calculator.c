#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ==========================
// View Previous Results
// ==========================
void viewPreviousResults() {
    FILE *file = fopen("cgpa_output.txt", "r");
    if (file == NULL) {
        printf("\nNo previous CGPA records found!\n");
        return;
    }

    char ch;
    printf("\n=========== PREVIOUS CGPA RECORDS ===========\n\n");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    printf("\n=============================================\n");
    fclose(file);
}

// ==========================
// Main Program (SEARCH REMOVED)
// ==========================
int main() {
    int n, i, choice;
    float gradePoint, credit;
    float totalCredits, totalWeightedPoints;
    int conditionalFlag;
    int conditionalCount;
    char studentName[100];
    char studentID[50];

    FILE *outputFile;

    while (1) {
        printf("\n=========================================\n");
        printf("          CGPA CALCULATOR PROJECT        \n");
        printf("=========================================\n");
        printf("1. Calculate New CGPA\n");
        printf("2. View Previous Results\n");
        printf("3. Exit\n");   // changed from 4 to 3
        printf("Enter your choice (1-3): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a valid number.\n");
            while (getchar() != '\n');
            continue;
        }

        if (choice == 3) {    // exit option updated
            printf("\nExiting program... Goodbye!\n");
            break;
        }

        if (choice == 2) {
            viewPreviousResults();
            printf("\nPress Enter to return to the main menu...");
            getchar(); getchar();
            continue;
        }

        if (choice == 1) {
            // ================================
            // NAME VALIDATION (Must contain 1 letter)
            // ================================
            while (1) {
                int hasLetter = 0;

                printf("\nEnter Student Name: ");
                scanf(" %[^\n]", studentName);

                for (int j = 0; studentName[j] != '\0'; j++) {
                    char c = studentName[j];
                    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
                        hasLetter = 1;
                        break;
                    }
                }

                if (!hasLetter) {
                    printf("Invalid Name! Must contain at least ONE letter.\n");
                    continue;
                }

                break;
            }

            printf("Enter Student ID: ");
            scanf(" %[^\n]", studentID);

            printf("\nGrade System Table:\n");
            printf("------------------------------\n");
            printf("| Grade  | Grade Point       |\n");
            printf("------------------------------\n");
            printf("|  A+    | 4.00              |\n");
            printf("|  A     | 3.75              |\n");
            printf("|  A-    | 3.50              |\n");
            printf("|  B+    | 3.25              |\n");
            printf("|  B     | 3.00              |\n");
            printf("|  C     | 2.50              |\n");
            printf("|  D     | 2.00              |\n");
            printf("|  F     | 0.00              |\n");
            printf("------------------------------\n");

            while (1) {
                float temp;
                printf("\nEnter number of courses: ");
                if (scanf("%f", &temp) != 1) {
                    printf("Invalid input!\n");
                    while (getchar() != '\n');
                    continue;
                }

                if (temp <= 0 || (int)temp != temp) {
                    printf("Enter whole positive number only.\n");
                    continue;
                }

                n = (int)temp;
                break;
            }

            totalCredits = 0.0;
            totalWeightedPoints = 0.0;
            conditionalFlag = 0;
            conditionalCount = 0;

            for (i = 1; i <= n; i++) {
                printf("\nCourse %d:\n", i);

                while (1) {
                    printf("Enter grade point (0.00 - 4.00): ");
                    if (scanf("%f", &gradePoint) != 1) {
                        printf("Invalid input!\n");
                        while (getchar() != '\n');
                        continue;
                    }

                    if (gradePoint < 0.0 || gradePoint > 4.0) {
                        printf("Must be between 0.00 and 4.00.\n");
                        continue;
                    }
                    break;
                }

                if (gradePoint < 2.00) {
                    conditionalFlag = 1;
                    conditionalCount++;
                }

                while (1) {
                    float tempCredit;
                    printf("Enter credit hours: ");
                    if (scanf("%f", &tempCredit) != 1) {
                        printf("Invalid input!\n");
                        while (getchar() != '\n');
                        continue;
                    }

                    if (tempCredit <= 0 || (int)tempCredit != tempCredit) {
                        printf("Enter whole number only.\n");
                        continue;
                    }

                    credit = tempCredit;
                    break;
                }

                totalCredits += credit;
                totalWeightedPoints += gradePoint * credit;
            }

            outputFile = fopen("cgpa_output.txt", "a");
            if (outputFile == NULL) {
                printf("Error saving file!\n");
                return 1;
            }

            fprintf(outputFile, "\n------------------------------------------\n");
            fprintf(outputFile, "Student Name: %s\n", studentName);
            fprintf(outputFile, "Student ID: %s\n", studentID);

            float cgpa = totalWeightedPoints / totalCredits;
            char grade[3];

            if (cgpa >= 4.00) sprintf(grade, "A+");
            else if (cgpa >= 3.75) sprintf(grade, "A");
            else if (cgpa >= 3.50) sprintf(grade, "A-");
            else if (cgpa >= 3.25) sprintf(grade, "B+");
            else if (cgpa >= 3.00) sprintf(grade, "B");
            else if (cgpa >= 2.50) sprintf(grade, "C");
            else if (cgpa >= 2.00) sprintf(grade, "D");
            else sprintf(grade, "CA");

            printf("\n================= RESULT =================\n");
            printf("Student Name: %s\n", studentName);
            printf("Student ID: %s\n", studentID);
            printf("Total Subjects: %d\n", n);
            printf("CGPA: %.2f\n", cgpa);
            printf("Grade: \"%s\"\n", grade);

            fprintf(outputFile, "Total Subjects: %d\n", n);
            fprintf(outputFile, "CGPA: %.2f\n", cgpa);
            fprintf(outputFile, "Grade: \"%s\"\n", grade);

            if (conditionalFlag == 1) {
                printf("Status: Conditionally Allowed\n");
                fprintf(outputFile, "Status: Conditionally Allowed\n");
            } else {
                printf("Status: Passed\n");
                fprintf(outputFile, "Status: Passed\n");
            }

            fclose(outputFile);
            printf("\nOutput saved successfully!\n");
            printf("===========================================\n");

            printf("\nPress Enter to return to the main menu...");
            getchar(); getchar();
        } else {
            printf("Invalid choice! Please enter 1 to 3.\n");
        }
    }

    return 0;
}
