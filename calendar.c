//Name:         Bryan Powell
//FileName:     statistics.c
//Description:  retrieves ages from user continuously then displays the average
//              age along with highest and lowest ages

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    //Variable declaration
    enum Days {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};
    int day_input = -1, num_days = -1, i = 1, counter = 0;
    enum Days last_day;


    //Retrieves start day from user and checks validity
    do
    {
        printf("Start day: ");
        scanf("%d", &day_input);

        //checks validity of start day
        if ((day_input < 0) || (day_input > 6))
            printf("INVALID START DAY\n");
    } while ((day_input < 0) || (day_input > 6));

    //Retrieves number of days in the month and checks validity
    do
    {
        printf("Number of days in the month: ");
        scanf("%d", &num_days);

        //Checks validity of number of days
        if ((num_days < 28) || (num_days > 31))
            printf("INVALID NUMBER OF DAYS\n");
    } while ((num_days < 28) || (num_days > 31));


    printf("\nSun\tMon\tTue\tWed\tThu\tFri\tSat\n");
    printf("----\t----\t----\t----\t----\t----\t----\n");

    //Switch statements to determine the day to start printing under
    switch (day_input)
    {
        case 0:
            printf("%d \t", i);
            counter = 1;
            break;

        case 1:
            printf("\t%d \t", i);
            counter = 2;
            break;

        case 2:
            printf("\t\t%d \t", i);
            counter = 3;
            break;

        case 3:
            printf("\t\t\t%d \t", i);
            counter = 4;
            break;

        case 4:
            printf("\t\t\t\t%d \t", i);
            counter = 5;
            break;

        case 5:
            printf("\t\t\t\t\t%d \t", i);
            counter = 6;
            break;

        case 6:
            printf("\t\t\t\t\t\t%d \t", i);
            counter = 7;
            break;
    }

    //Increments i (the date) and begins the loop to print
    i++;
    for (i; i <= num_days; i++)
    {
        //Conditional statement to print to next line
        if (counter % 7 == 0)
            printf("\n");

        //Prints the next date, and spaces to the next column, also increments the counter (for spacing)
        printf("%d \t", i);
        counter++;
    }

    //Calculates last day of the month
    last_day = ((day_input + num_days) - 1) % 7;

    //prints the last divider line and the last day of the month
    printf("\n----\t----\t----\t----\t----\t----\t----\n");
    printf("The last day of the month is: ");

    switch (last_day)
    {
        case 0: //Sunday
            printf("Sunday.");
            break;
        case 1: //Monday
            printf("Monday.");
            break;
        case 2: //Tuesday
            printf("Tuesday.");
            break;
        case 3: //Wednesday
            printf("Wednesday.");
            break;
        case 4: //Thursday
            printf("Thursday.");
            break;
        case 5: //Friday
            printf("Friday.");
            break;
        case 6: //Saturday
            printf("Saturday.");
    }




    return 0;
}
