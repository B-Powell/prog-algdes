//Name:         Bryan Powell
//FileName:     interest.c
//Description:  Computes account balance after interest is added

#include <stdio.h>

int main(void)
{
    double deposit;
    double i;
    int x;

    //Prompts user for account information and stores in appropriate variables
    printf("Please input initial deposit: $");
    scanf("%lf.2", &deposit);
    printf("Please input interest rate: %% ");
    scanf("%lf.2", &i);
    printf("Please input the number of years: ");
    scanf("%d", &x);

    /*//for debugging
    printf("\n%.2f", deposit);
    printf("\n%.2f", i);
    printf("\n%d", x);
    */

    //Calculates account information based on user input
    i = i/100;
    int months = x*12;
    int h;
    for (h = 0; h < months; h++)
    {
        deposit = deposit + (deposit*i);
    }


    /*//for debugging
    printf("\n%.2f", deposit);
    printf("\n%.2f", i);
    printf("\n%d", x);
    printf("\n%d", months);
    */

    printf("After %d of years, the deposit in the savings account is now $%.2f\n\n", x, deposit);

    return 0;
}
