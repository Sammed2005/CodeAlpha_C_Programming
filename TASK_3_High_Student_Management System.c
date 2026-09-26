#include <stdio.h>
#include <stdlib.h>
#define FILE_NAME "students.dat"
struct Student
{
    int rollNo;
    char name[50];
    float marks;
};
void addStudent()
{
    FILE *fp;
    struct Student s;
    fp = fopen(FILE_NAME, "ab");
    if (fp == NULL)
    {
        perror("File error");
        return;
    }
    printf("\n         ADD STUDENT  \n");
    printf("Enter Roll Number : ");
    scanf("%d", &s.rollNo);
    printf("Enter Name        : ");
    scanf(" %[^\n]", s.name);
    printf("Enter Marks       : ");
    scanf("%f", &s.marks);
    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
    printf("\nStudent added successfully!\n");
}
void displayStudents()
{
    FILE *fp;
    struct Student s;
    fp = fopen(FILE_NAME, "rb");
    if (fp == NULL)
    {
        printf("\nNo student records found.\n");
        return;
    }
    printf("              STUDENT RECORDS\n");
    printf("%-10s %-20s %-10s\n",
           "Roll No", "Name", "Marks");
    while (fread(&s, sizeof(s), 1, fp) == 1)
    {
        printf("%-10d %-20s %-10.2f\n",
               s.rollNo, s.name, s.marks);
    }
    fclose(fp);
}
int main()
{
    int choice;
    do
    {
        printf("        STUDENT MANAGEMENT SYSTEM\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;
            case 3:
                printf("\nProgram ended successfully.\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while (choice != 3);
    return 0;
}
