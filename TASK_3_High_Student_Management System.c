#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "students.dat"
#define TEMP_FILE "temp.dat"

struct Student
{
    int rollNo;
    char name[50];
    float marks;
};

/* Add Student */
void addStudent()
{
    FILE *fp;
    struct Student s, temp;

    printf("\n ADD STUDENT \n");
    printf("Enter Roll Number: ");

    if (scanf("%d", &s.rollNo) != 1 || s.rollNo <= 0)
    {
        printf("Invalid roll number!\n");
        return;
    }

    fp = fopen(FILE_NAME, "rb");

    if (fp != NULL)
    {
        while (fread(&temp, sizeof(temp), 1, fp) == 1)
        {
            if (temp.rollNo == s.rollNo)
            {
                printf("Roll number already exists!\n");
                fclose(fp);
                return;
            }
        }
        fclose(fp);
    }

    printf("Enter Name: ");
    if (scanf(" %49[^\n]", s.name) != 1)
    {
        printf("Invalid name!\n");
        return;
    }

    printf("Enter Marks (0-100): ");
    if (scanf("%f", &s.marks) != 1 ||
        s.marks < 0 || s.marks > 100)
    {
        printf("Invalid marks!\n");
        return;
    }

    fp = fopen(FILE_NAME, "ab");

    if (fp == NULL)
    {
        perror("File error");
        return;
    }

    if (fwrite(&s, sizeof(s), 1, fp) == 1)
        printf("Student added successfully!\n");
    else
        printf("Error saving student!\n");

    fclose(fp);
}

/* Display Students */
void displayStudents()
{
    FILE *fp;
    struct Student s;
    int count = 0;

    fp = fopen(FILE_NAME, "rb");

    if (fp == NULL)
    {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n STUDENT RECORDS \n");
    printf("%-10s %-25s %-10s\n",
           "Roll No", "Name", "Marks");

    while (fread(&s, sizeof(s), 1, fp) == 1)
    {
        printf("%-10d %-25s %-10.2f\n",
               s.rollNo, s.name, s.marks);
        count++;
    }

    if (count == 0)
        printf("No records available.\n");

    fclose(fp);
}

/* Search Student */
void searchStudent()
{
    FILE *fp;
    struct Student s;
    int rollNo, found = 0;

    printf("Enter Roll Number to Search: ");

    if (scanf("%d", &rollNo) != 1)
    {
        printf("Invalid input!\n");
        return;
    }

    fp = fopen(FILE_NAME, "rb");

    if (fp == NULL)
    {
        printf("No student records found.\n");
        return;
    }

    while (fread(&s, sizeof(s), 1, fp) == 1)
    {
        if (s.rollNo == rollNo)
        {
            printf("\nStudent Found!\n");
            printf("Roll Number: %d\n", s.rollNo);
            printf("Name       : %s\n", s.name);
            printf("Marks      : %.2f\n", s.marks);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found)
        printf("Student not found!\n");
}

/* Update Student */
void updateStudent()
{
    FILE *fp, *temp;
    struct Student s;
    int rollNo, found = 0, error = 0;

    printf("Enter Roll Number to Update: ");

    if (scanf("%d", &rollNo) != 1)
    {
        printf("Invalid input!\n");
        return;
    }

    fp = fopen(FILE_NAME, "rb");

    if (fp == NULL)
    {
        printf("No student records found.\n");
        return;
    }

    temp = fopen(TEMP_FILE, "wb");

    if (temp == NULL)
    {
        fclose(fp);
        printf("Unable to create temporary file.\n");
        return;
    }

    while (fread(&s, sizeof(s), 1, fp) == 1)
    {
        if (s.rollNo == rollNo)
        {
            found = 1;

            printf("Enter New Name: ");
            if (scanf(" %49[^\n]", s.name) != 1)
            {
                error = 1;
                break;
            }

            printf("Enter New Marks (0-100): ");
            if (scanf("%f", &s.marks) != 1 ||
                s.marks < 0 || s.marks > 100)
            {
                printf("Invalid marks!\n");
                error = 1;
                break;
            }
        }

        if (fwrite(&s, sizeof(s), 1, temp) != 1)
        {
            error = 1;
            break;
        }
    }

    if (ferror(fp))
        error = 1;

    fclose(fp);

    if (fclose(temp) != 0)
        error = 1;

    if (error || !found)
    {
        if (!found && !error)
            printf("Student not found!\n");
        else
            printf("File operation failed.\n");

        remove(TEMP_FILE);
        return;
    }

    if (remove(FILE_NAME) != 0 ||
        rename(TEMP_FILE, FILE_NAME) != 0)
    {
        printf("Unable to replace student records file.\n");
        printf("Check students.dat and temp.dat before retrying.\n");
        return;
    }

    printf("Student updated successfully!\n");
}

/* Delete Student */
void deleteStudent()
{
    FILE *fp, *temp;
    struct Student s;
    int rollNo, found = 0, error = 0;

    printf("Enter Roll Number to Delete: ");

    if (scanf("%d", &rollNo) != 1)
    {
        printf("Invalid input!\n");
        return;
    }

    fp = fopen(FILE_NAME, "rb");

    if (fp == NULL)
    {
        printf("No student records found.\n");
        return;
    }

    temp = fopen(TEMP_FILE, "wb");

    if (temp == NULL)
    {
        fclose(fp);
        printf("Unable to create temporary file.\n");
        return;
    }

    while (fread(&s, sizeof(s), 1, fp) == 1)
    {
        if (s.rollNo == rollNo)
        {
            found = 1;
            continue;
        }

        if (fwrite(&s, sizeof(s), 1, temp) != 1)
        {
            error = 1;
            break;
        }
    }

    if (ferror(fp))
        error = 1;

    fclose(fp);

    if (fclose(temp) != 0)
        error = 1;

    if (error || !found)
    {
        if (!found && !error)
            printf("Student not found!\n");
        else
            printf("File operation failed.\n");

        remove(TEMP_FILE);
        return;
    }

    if (remove(FILE_NAME) != 0 ||
        rename(TEMP_FILE, FILE_NAME) != 0)
    {
        printf("Unable to replace student records file.\n");
        printf("Check students.dat and temp.dat before retrying.\n");
        return;
    }

    printf("Student deleted successfully!\n");
}

/* Main Function */
int main()
{
    int choice;

    do
    {
        printf("\n  STUDENT MANAGEMENT SYSTEM \n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Update Student\n");
        printf("4. Search Student\n");
        printf("5. Display Students\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Restart the program.\n");
            return 1;
        }

        switch (choice)
        {
            case 1:
                addStudent();
                break;
            case 2:
                deleteStudent();
                break;
            case 3:
                updateStudent();
                break;
            case 4:
                searchStudent();
                break;
            case 5:
                displayStudents();
                break;
            case 6:
                printf("Program ended successfully.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}
