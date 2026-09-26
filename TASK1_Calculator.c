#include <stdio.h>
int main()
{
    float num1, num2, result;
    int choice;
    printf("        BASIC CALCULATOR PROGRAM\n");
    printf("Enter first number  : ");
    scanf("%f", &num1);
    printf("Enter second number : ");
    scanf("%f", &num2);
    printf("              RESULTS\n");
    for(choice = 1; choice <= 4; choice++)
    {
        switch(choice)
        {
            case 1:
                result = num1 + num2;
                printf("Addition       : %.2f + %.2f = %.2f\n",
                       num1, num2, result);
                break;
            case 2:
                result = num1 - num2;
                printf("Subtraction    : %.2f - %.2f = %.2f\n",
                       num1, num2, result);
                break;
            case 3:
                result = num1 * num2;
                printf("Multiplication : %.2f * %.2f = %.2f\n",
                       num1, num2, result);
                break;
            case 4:
                if(num2 == 0)
                {
                    printf("Division:Cannot divide byzero\n");
                }
                else
                {
                    result = num1 / num2;
                    printf("Division       :%.2f / %.2f = %.2f\n",
                           num1, num2, result);
                }
                break;
        }
    }
    printf(" PROGRAM COMPLETED SUCCESSFULLY\n");
    return 0;
}
