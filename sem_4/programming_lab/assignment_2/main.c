#include <stdio.h>
#include <stdlib.h>

#define StudentTb "StudentTb.bin"
#define MarksTb "MarksTb.bin"

typedef struct student
{
    int roll;
    char name[30];
} student;

typedef struct marks
{
    int roll;
    float score;
} marks;

// Function prototypes
// type=0 for student and type=1 for marks
long sizeOfFile(FILE *fp);
void *retrieveDataFromFile(FILE *fp, int type);

void insertStudent(student newStudent, FILE *studentTb);
void insertMarks(marks marksDetails, FILE *marksTb);
student *searchStudent(int roll, FILE *studentTb);
marks *searchMarks(int roll, FILE *marksTb);
void displayStudentTb(FILE *studentTb);
void displayMarksTb(FILE *marksTb);
void displayFullResult(FILE *studentTb, FILE *marksTb);

int main()
{
    // open the files in rb+
    FILE *studentTb = fopen(StudentTb, "rb+");
    FILE *marksTb = fopen(MarksTb, "rb+");

    if (!studentTb)
    {
        printf("%s file not found!\n", StudentTb);
        return 1;
    }

    if (!marksTb)
    {
        printf("%s file not found!\n", MarksTb);
        return 1;
    }

    int choice; // To store user choice

    while (1)
    { // Infinite loop for menu
        // Display menu
        printf("\n========= MENU =========\n");
        printf("1. Insert a record in StudentTb\n");
        printf("2. Insert a record in MarksTb\n");
        printf("3. Search Student Name by RollNo\n");
        printf("4. Search Marks by RollNo\n");
        printf("5. Display StudentTb\n");
        printf("6. Display MarksTb\n");
        printf("7. Display Full Result (RollNo Name Marks)\n");
        printf("8. Exit\n");
        printf("========================\n");

        // Input user choice
        printf("Enter your choice (1-8): ");
        scanf("%d", &choice);

        // Process user choice
        switch (choice)
        {
        case 1:
        {
            // Create new student and get data from user
            student newStudent;
            printf("\nEnter student name(max 30 characters): ");
            scanf("\n%[^\n]s", newStudent.name);
            printf("Enter student roll number: ");
            scanf("%d", &newStudent.roll);
            // Insert the new student
            insertStudent(newStudent, studentTb);
            break;
        }
        case 2:
        {
            // Create new marks and get data from user
            marks marksDetails;
            printf("\nEnter student roll number: ");
            scanf("%d", &marksDetails.roll);
            printf("Enter marks: ");
            scanf("%f", &marksDetails.score);
            // Insert the marks details
            insertMarks(marksDetails, marksTb);
            break;
        }
        case 3:
        {
            int roll;
            printf("\nEnter roll number to search name: ");
            scanf("%d", &roll);
            student *st = searchStudent(roll, studentTb);
            if (st)
                printf("Roll: %d\nName: %s\n", roll, st->name);
            else
                printf("No student found with this roll number!\n");
            free(st);
            break;
        }
        case 4:
        {
            int roll;
            printf("\nEnter roll number to search marks: ");
            scanf("%d", &roll);
            marks *mr = searchMarks(roll, marksTb);
            if (mr)
                printf("Roll: %d\nMarks: %.2f\n", roll, mr->score);
            else
                printf("No marks found with this roll number!\n");
            free(mr);
            break;
        }
        case 5:
        {
            displayStudentTb(studentTb);
            break;
        }
        case 6:
        {
            displayMarksTb(marksTb);
            break;
        }
        case 7:
        {
            displayFullResult(studentTb, marksTb);
            break;
        }
        case 8:
            return 0;
        default:
            printf("Invalid choice! Please enter a number between 1 and 5.\n");
        }
    }

    fclose(studentTb);
    fclose(marksTb);
    return 0;
}

// Function definitions
long sizeOfFile(FILE *fp)
{
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    return file_size;
}

void *retrieveDataFromFile(FILE *fp, int type)
{
    long file_size = sizeOfFile(fp);
    long n;
    if (type == 0)
    {
        n = file_size / sizeof(student);
        // Make an array to store the elements
        student *allStudents = (student *)malloc(sizeof(student) * n);
        fread(allStudents, sizeof(student), n, fp);
        fseek(fp, 0, SEEK_SET);
        return allStudents;
    }
    else if (type == 1)
    {
        n = file_size / sizeof(marks);
        // Make an array to store the elements
        marks *allMarks = (marks *)malloc(sizeof(marks) * n);
        fread(allMarks, sizeof(marks), n, fp);
        fseek(fp, 0, SEEK_SET);
        return allMarks;
    }
    else
    {
        printf("The type is invalid!\n");
        return NULL;
    }
}

void insertStudent(student newStudent, FILE *studentTb)
{
    // Move the pointer to the end of the file to append
    fseek(studentTb, 0, SEEK_END);
    // Write the new student
    fwrite(&newStudent, sizeof(student), 1, studentTb);
    printf("Written one student details successfully\nName: %s, Roll: %d\n", newStudent.name, newStudent.roll);
    // Again move the pointer to the beginning of the file
    fseek(studentTb, 0, SEEK_SET);
}

void insertMarks(marks marksDetails, FILE *marksTb)
{
    // Move the pointer to the end of the file to append
    fseek(marksTb, 0, SEEK_END);
    // Write the new marks
    fwrite(&marksDetails, sizeof(marks), 1, marksTb);
    printf("Written one marks details successfully\nScore: %.2f, Roll: %d\n", marksDetails.score, marksDetails.roll);
    // Again move the pointer to the beginning of the file
    fseek(marksTb, 0, SEEK_SET);
}

student *searchStudent(int roll, FILE *studentTb)
{
    // Find out the number of students
    long number_of_students = sizeOfFile(studentTb) / sizeof(student);

    // Traverse through the data to find the required student
    student *st = (student *)malloc(sizeof(student));
    while (number_of_students--)
    {
        fread(st, sizeof(student), 1, studentTb);
        if (st->roll == roll)
            return st;
    }
    fseek(studentTb, 0, SEEK_SET);
    free(st);
    return NULL;
}

marks *searchMarks(int roll, FILE *marksTb)
{
    // Find out the number of marks details
    long number_of_marks = sizeOfFile(marksTb) / sizeof(marks);

    // Traverse through the data to find the required marks details
    marks *mr = (marks *)malloc(sizeof(marks));
    while (number_of_marks--)
    {
        fread(mr, sizeof(marks), 1, marksTb);
        if (mr->roll == roll)
            return mr;
    }
    fseek(marksTb, 0, SEEK_SET);
    free(mr);
    return NULL;
}

void displayStudentTb(FILE *studentTb)
{
    // Find out the number of students
    long number_of_students = sizeOfFile(studentTb) / sizeof(student);
    printf("Total students: %ld\n", number_of_students);

    // Retrieve all students
    student *allStudents = (student *)retrieveDataFromFile(studentTb, 0);

    printf("\n============= StudentTb =============\n");
    printf("Roll                Name\n");
    for (int i = 0; i < number_of_students; i++)
    {
        printf("%-20d", allStudents[i].roll);
        printf("%-30s\n", allStudents[i].name);
    }
    printf("=====================================\n");
    free(allStudents);
}

void displayMarksTb(FILE *marksTb)
{
    // Find out the number of marks
    long number_of_marks = sizeOfFile(marksTb) / sizeof(marks);
    printf("Total marks: %ld\n", number_of_marks);

    // Retrieve all marks
    marks *allMarks = (marks *)retrieveDataFromFile(marksTb, 1);

    printf("\n========== MarksTb ==========\n");
    printf("Roll                Marks\n");
    for (int i = 0; i < number_of_marks; i++)
    {
        printf("%-20d", allMarks[i].roll);
        printf("%-8.2f\n", allMarks[i].score);
    }
    printf("=============================\n");
    free(allMarks);
}

void displayFullResult(FILE *studentTb, FILE *marksTb)
{
    student *allStudents = (student *)retrieveDataFromFile(studentTb, 0);
    marks *allMarks = (marks *)retrieveDataFromFile(marksTb, 1);
    int number_of_students = sizeOfFile(studentTb) / sizeof(student);
    int number_of_marks = sizeOfFile(marksTb) / sizeof(marks);
    printf("\nNumber of students: %ld, Number of marks: %ld\n", number_of_students, number_of_marks);
    printf("\n============ All Results ============\n");
    printf("Roll      Name                Marks\n");
    int i = 0;
    if (number_of_students > number_of_marks)
    {
        while (number_of_students--)
        {
            printf("%-10d", allStudents[i].roll);
            printf("%-20s", allStudents[i].name);
            if (i < number_of_marks)
                printf("%-8.2f\n", searchMarks(allStudents[i].roll, marksTb)->score);
            else
                printf("_\n");
            i++;
        }
    }
    else
    {
        while (number_of_marks--)
        {
            printf("%-10d", allMarks[i].roll);
            if (i < number_of_students)
                printf("%-20s", searchStudent(allMarks[i].roll, studentTb)->name);
            else
                printf("_");
            printf("%-8.2f\n", allMarks[i].score);
            i++;
        }
    }
    printf("=====================================\n");
    free(allStudents);
    free(allMarks);
}