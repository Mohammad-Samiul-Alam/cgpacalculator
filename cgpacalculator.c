#include <stdio.h>

int main() {
    int n;
        // Display grade system table
        printf("\nGrade System Table:\n");
        printf("----------------------------\n");
        printf("| Grade | Grade Point      |\n");
        printf("----------------------------\n");
        printf("|  A+   | 4.00             |\n");
        printf("|  A    | 3.75             |\n");
        printf("|  A-   | 3.50             |\n");
        printf("|  B+   | 3.25             |\n");
        printf("|  B    | 3.00             |\n");
        printf("|  C    | 2.50             |\n");
        printf("|  D    | 2.00             |\n");
        printf("|  F    | 0.00             |\n");
        printf("----------------------------\n");

        // Ask user for number of courses
        printf("\nEnter number of courses: ");
        scanf("%d", &n);

    printf("\n%d", n);
    return 0;
}
