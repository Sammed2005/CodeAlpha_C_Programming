#include <stdio.h>
#define MAX 10
void readMatrix(int A[MAX][MAX], int rows, int cols)
{
    int i, j;
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
}
void displayMatrix(int A[MAX][MAX], int rows, int cols)
{
    int i, j;
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            printf("%5d", A[i][j]);
        }
        printf("\n");
    }
}
void addMatrix(int A[MAX][MAX], int B[MAX][MAX],
               int C[MAX][MAX], int rows, int cols)
{
    int i, j;
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}
void multiplyMatrix(int A[MAX][MAX], int B[MAX][MAX],
                    int C[MAX][MAX],
                    int r1, int c1, int c2)
{
    int i, j, k;
    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            C[i][j] = 0;

            for(k = 0; k < c1; k++)
            {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
}
void transposeMatrix(int A[MAX][MAX],
                     int T[MAX][MAX],
                     int rows, int cols)
{
    int i, j;
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            T[j][i] = A[i][j];
        }
    }
}
int main()
{
    int A[MAX][MAX], B[MAX][MAX];
    int add[MAX][MAX], multiply[MAX][MAX];
    int transpose[MAX][MAX];
    int r1, c1, r2, c2;

    printf("             MATRIX OPERATIONS\n");
    printf("\nEnter rows and columns of Matrix A: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter elements of Matrix A:\n");
    readMatrix(A, r1, c1);
    printf("\nEnter rows and columns of Matrix B: ");
    scanf("%d %d", &r2, &c2);
    printf("Enter elements of Matrix B:\n");
    readMatrix(B, r2, c2);
    printf("                 INPUT MATRICES\n");
    printf("\nMatrix A:\n");
    displayMatrix(A, r1, c1);
    printf("\nMatrix B:\n");
    displayMatrix(B, r2, c2);
    printf("             1. MATRIX ADDITION\n");
    if(r1 == r2 && c1 == c2)
    {
        addMatrix(A, B, add, r1, c1);
        printf("\nA + B =\n");
        displayMatrix(add, r1, c1);
    }
    else
    {
        printf("Addition is not possible.\n");
        printf("Both matrices must have the same size.\n");
    }
    printf("          2. MATRIX MULTIPLICATION\n");
    if(c1 == r2)
    {
        multiplyMatrix(A, B, multiply, r1, c1, c2);
        printf("\nA x B =\n");
        displayMatrix(multiply, r1, c2);
    }
    else
    {
        printf("Multiplication is not possible.\n");
        printf("Columns of A must equal rows of B.\n");
    }
    printf("             3. TRANSPOSE OF A\n");
    transposeMatrix(A, transpose, r1, c1);
    printf("\nTranspose of Matrix A =\n");
    displayMatrix(transpose, c1, r1);
    printf("          PROGRAM COMPLETED SUCCESSFULLY\n");
    return 0;
}
