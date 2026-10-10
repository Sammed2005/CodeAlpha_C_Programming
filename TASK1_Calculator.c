#include <stdio.h>
int main(void)
{
    float num1, num2, result;
    int choice;
    printf("\n===== BASIC CALCULATOR =====\n");
    printf("Enter first number: ");
    if (scanf("%f", &num1) != 1)
    {
        printf("Invalid input!\n");
        return 1;
    }
    printf("Enter second number: ");
    if (scanf("%f", &num2) != 1)
    {
        printf("Invalid input!\n");
        return 1;
    }
    printf("\n----- MENU -----\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter your choice: ");
    if (scanf("%d", &choice) != 1)
    {
        printf("Invalid choice!\n");
        return 1;
    }
    switch (choice)
    {
        case 1:
            result = num1 + num2;
            printf("Addition = %.2f\n", result);
            break;
        case 2:
            result = num1 - num2;
            printf("Subtraction = %.2f\n", result);
            break;
        case 3:
            result = num1 * num2;
            printf("Multiplication = %.2f\n", result);
            break;
        case 4:
            if (num2 == 0)
            {
                printf("Error: Cannot divide by zero!\n");
            }
            else
            {
                result = num1 / num2;
                printf("Division = %.2f\n", result);
            }
            break;
        default:
            printf("Invalid choice! Select 1 to 4.\n");
    }
    printf("\nPROGRAM COMPLETED SUCCESSFULLY!\n");
    return 0;
}
