//Name:         Bryan Powell
//FileName:     game.c
//Description:  Selects a random number and allows user to guess

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
    //Variable declaration
    int counter, user_guess, rand_number, u_continue = 1;
    time_t t;

    printf("WELCOME TO THE NUMBER GUESSING GAME!\n");
    printf("Enter \"0\" at any time to end the current round.\n\n");

    //initializes random number generator
    srand((unsigned) time(&t));

    do
    {
        rand_number = (rand() % 100) + 1;
        counter = 0;

        do
        {
            printf("Take a guess at the random number: ");
            scanf("%d", &user_guess);

            if (user_guess == 0)
                break;

            if (user_guess < rand_number)
                printf("Too low, try again\n");
            if (user_guess > rand_number)
                printf("Too high, try again\n");
            counter++;
        } while (user_guess != rand_number && user_guess != 0);

        if (user_guess == 0)
            printf("\nYou decided to quit and have made %d attempts in your game.\n", counter);
        if (user_guess == rand_number)
            printf("\nCongratulations! You have won the game after making %d attempts.\n", counter);


        do
        {
            printf("Would you like to play again? (1 for yes, 0 for no): ");
            scanf("%d", &u_continue);

            if ((u_continue != 1) && (u_continue != 0))
                printf("Invalid Response\n");
        } while ((u_continue != 1) && (u_continue != 0));

        if (u_continue == 1)
            printf("Sure! You are about to begin a new game.\n\n");

    } while (u_continue == 1);







    return 0;
}
