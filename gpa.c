// Name:        Bryan Powell
// File name:   gpa.c
// Description: Retrieves the number of classes and grades from user and computes gpa

#include <stdio.h>

int main (void)
{
    //variable declaration
    float gpa, numberGrade, sum = 0;
    int i = 0, numCourse;
    char letterGrade, modifier;

    printf("Enter the number of 3-hour courses: ");
    scanf("%d", &numCourse);

    for (i; i < numCourse; i++)
    {
        printf("\n\nWhat grade did you earn?\n");
        printf("Enter A, B, C, D, or F: ");
        scanf(" %c", &letterGrade);

        printf("\nEnter modifier - for letter grades A-, etc. + for letter grades B+, etc. and _ for letter grades A, B, etc.: ");
        scanf(" %c", &modifier);

        switch (letterGrade)
        {
            case 'A':
            case 'a':
                numberGrade = 4.0;
                break;
            case 'B':
            case 'b':
                numberGrade = 3.0;
                break;
            case 'C':
            case 'c':
                numberGrade = 2.0;
                break;
            case 'D':
            case 'd':
                numberGrade = 1.0;
                break;
            case 'F':
            case 'f':
                numberGrade = 0.0;
                break;
        }

        if (modifier == '-')
            numberGrade = numberGrade - 0.3;
        else if (modifier == '+')
            numberGrade = numberGrade + 0.3;

        sum = sum + numberGrade;

        //For debugging
        //printf("\n%d", i);
        //printf("\n%f", numCourse);
    }

    gpa = sum / (float)numCourse;

    printf("\n\nThe final gpa is %1.2f\n", gpa);

    return 0;
}
