//Name:         Bryan Powell
//FileName:     search.c
//Description:  highlights difference between linear and binary search functions

#include <stdio.h>

//Function signatures (listed first out of habit)
void GetSearchArray (int *list);
int UserSearchVal ();
int LinearSearch (int s, int *list, int n);
int BinarySearch (int s, int *list, int n);
void Results (int i, int s);

//Global variable that sets the array length
const int n = 10;

int main (void) //Performs very little instruction outside of function calls
{
    int list[n];

    GetSearchArray (list);
    int s = UserSearchVal ();
    int ls_results = LinearSearch (s, list, n);
    int bs_results = BinarySearch (s, list, n);
    if (ls_results == bs_results)
        Results (bs_results, s); //Prints results of search
    else
        printf("\n\n   ERROR!   \n\n"); //Prints error to screen because linear search results did not match binary search results

    return 0;
}

void GetSearchArray (int *list) //Prompts user for an array that is already in order
{
    printf("Please input 10 integers in ascending order: \n");
    int i = 0;
    for (i; i < n; i++)
        scanf("%d", &list[i]);
    return;
}

int UserSearchVal () //Prompts user for the value to search
{
    printf("Please enter an integer to search: ");
    int search_val;
    scanf("%d", &search_val);
    return search_val;
}

int LinearSearch (int s, int *list, int n) //Performs search of every element of array
{
    int i = 0;
    for (i; i < n; i++)
    {
        if (s == list[i])
            return i; //If match is found, function will return index of match
    }

    return -1; //If no match, this function will return -1
}

int BinarySearch (int s, int *list, int n) //Performs Binary search of array
{
    int k = n / 2;
    if (s == list[k])
        return k; //If match is found here, returns results k
    int i = 0;
    if (s < list[k]) //If match is found here (in lower half of array), i is returned, if no match, -1 returned
    {
        for (i; i < k; i++)
        {
            if (s == list [i])
                return i;
        }
        return -1;
    }

    else //If match is found here (in upper half of array), i is returned, if no match, -1 returned
    {
        i = k + 1;
        for (i; i <= n; i++)
        {
            if (s == list[i])
                return i;
        }
        return -1;
    }
}

void Results (int i, int s) //Prints the results of the search
{
    if (i > -1)
        printf("\n\nA match for %d was found at position %d\n\n", s, i);
    else
        printf("\n\nA match for %d was not found.\n\n", s);
    return;
}
