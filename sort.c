//Name:         Bryan Powell
//FileName:     sort.c
//Description:  Sorts an array of user-defined length from greatest to smallest

#include <stdio.h>

//Function signatures
int GetArraySize ();
void GetUserArray (int n, int *list);
void SortSmallToBig(int n, int *list);
int GetMax (int temp, int *list);
void Results (int n, int *list);

int main (void)
{
    int n = GetArraySize();
    int list[n];
    GetUserArray(n, list);
    SortSmallToBig(n, list);
    Results (n, list);

    return 0;
}

int GetArraySize() //Retrieves the number of arrays from the user
{
    int size_of_array = 0;
    do
    {
        printf("How many numbers are being sorted: ");
        scanf("%d", &size_of_array);

        if (size_of_array < 2)
            printf("\n\n%d is not a valid amount of numbers to sort.\n\n", size_of_array);
    } while (size_of_array < 2);

    return size_of_array;
}

void GetUserArray (int n, int *list) //Retrieves the numbers the user wants sorted
{
    printf("Please input the values to sort:\n");
    int i = 0;
    for (i; i < n; i++)
    {
        scanf("%d", &list[i]);
    }
    return;
}

void SortSmallToBig(int n, int *list) //sorts the user's numbers from smallest to biggest
{
    int temp = n;
    int j = 0;
    for (j; j < 5; j++) //Runs the sorting algorithm multiple times to ensure that a smaller value is not placed in the wrong spot
    {
        temp = n;
        for (temp; temp > 0; temp--)
        {
            int max = GetMax(temp, list);
        }
    }
    return;
}

int GetMax(int temp, int *list) //also sorts array from smallest to biggest
{
    int i = 0;
    int max = -32000000;
    int placeholder;
    for (i; i < temp; i++)
    {
        if ((list[i] > list[i+1]) && (list[i] >= max))
        {
            placeholder = list[temp-1];
            list[temp-1]=list[i];
            list[i] = placeholder;
        }
            max = list[i];
    }
    return max;
}

void Results (int n, int *list) //Prints the results of the sorted array
{
    int i = 0;
    printf("\n\nThe sorted results are: ");
    for (i; i < n; i++)
    {
        printf("%d ", list[i]);
    }

    printf("\n\n\n");
    /*For debugging:        ///////////////////////////////
    i = 0;
    for (i; i < n *2; i++)
        printf("%d\t%d\n", i, list[i]);
    ////////////////////////////////////////////////////*/
    return;
}







