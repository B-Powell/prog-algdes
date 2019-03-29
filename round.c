//Name:         Bryan Powell
//FileName:     round.c
//Description:  Retrieves a number from user and
//              computes and displays the value
//              rounded to the nearest hundredth.


#include<stdio.h>

int main (void)
{
    float num_input;

    //Retrieves a number from the user
    printf("Please enter a number: ");
    scanf("%f", &num_input);

    //Displays the rounded value of the user's number
    printf("\n\nThe rounded value is %.2f", num_input);

    return 0;
}

