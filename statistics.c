//Name:         Bryan Powell
//FileName:     statistics.c
//Description:  retrieves ages from user continuously then displays the average
//              age along with highest and lowest ages

#include <stdio.h>


int main(void)
{
    //Variable declaration
    int age_in = 0, age_sum, lg_age = -320000, sm_age = 320000, i = 0;
    double avg_age;

    //for-loop to retrieve all user-input ages
    //Since this program only retrieves and calculates ages, I am using
    //a for-loop instead of a different option
    for ( i; i > -1; i++)
    {
        //Retrieves a valid age input from user (other than -1)
        do
        {
            printf("Please enter an age: ");
            scanf("%d", &age_in);
            if (age_in < -1)
                printf("INVALID ENTRY\n");
        } while (age_in < -1);

        //checks user input for exit-condition from loop
        if (age_in == -1)
            break;

        //Sets largest and smallest age
        if (age_in < sm_age)
            sm_age = age_in;
        if (age_in > lg_age)
            lg_age = age_in;

        //Adds user input to total age and increments counter
        age_sum += age_in;
        i++;
    }

    avg_age = (double) age_sum / i;

    printf("\nThe smallest entered age is %d", sm_age);
    printf("\nThe largest entered age is %d", lg_age);
    printf("\nThe average age is %.4f", avg_age);




    return 0;
}
