#include <stdio.h>

/**
 * Prints a histogram to the screen using horizontal bar chart.
 * Parameters:
 *   list - a list of integers
 *   n - the number of values in the list
 */
void printHistogram (int *list, int *hist, int n );

/**
 * This program requests data from the user and then
 * computes and prints a histogram. You may assume that
 * the data values entered are in the range of 0 to 9.
 */
int main ( void )
{
	int i, n;

	// Data entry
	//
	printf ("How many values in your data set? ");
	scanf ("%d", &n);

	int list[n];
	for (i=0; i < n; i++) {
		printf ("Enter a value: ");
		scanf ("%d", &list[i]);
	}

	// Processing data to compute histogram
	//
	int hist[10];


	// Printing histogram
	printHistogram (list, hist, n);

	return 0;
}

void printHistogram (int *list, int *hist, int n )
{
    int i = 0, j = 0;

    for (i; i < 10; i++)
    {
        int counter = 0;
        for (j; j < n; j++)
        {
            if (list[j] == i)
                counter++;
        }
        hist[i] = counter;
    }

    printf("{");
    i = 0, j = 0;
    for (i; i < 10; i++)
    {
        printf("%d", hist[i]);
        if (i < 9)
            printf(", ");
    }
    printf("}\n\n");

    i = 0;
    for (i; i < 10; i++)
    {
        printf("[%d]", i);
        for (j; j < hist[i]; j++)
            printf("*");
        printf("\n");
    }


    return;
}
