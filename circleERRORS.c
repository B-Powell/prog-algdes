//Name:         Bryan Powell
//FileName:     circle.c
//Description:  Retrieves a number (radius) from user and
//              computes and displays the Area and Circumference
//              of a circle.


#include <stdio.h>

int main (void)
{
    const float PI = 3.14159265359;
    float radius, area, circumference;

    printf("Please enter a number: ");
    scanf("%f", &radius);

    //Debugging tool
    //printf("\n\nradius = %f", radius);

    //Computes Area and Circumference
    area = PI * radius * radius;
    circumference = 2 * PI * radius;

    //Prints results
    printf("\n\nThe area of a circle with radius %f is %f\n", radius, area);
    printf("The circumference of a circle with radius %f is %f\n\n", radius, circumference);

    return 0;


