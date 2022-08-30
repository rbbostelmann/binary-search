// C program to implement recursive Binary Search
#include <stdlib.h>
#include <stdio.h>
#include <cs50.h>
#include <time.h>

/*
 * This program generates a random array
 * of int, sorts it, and then takes input
 * (number) and returns the index of the
 * input if present in the array.
 */

/*  Prototypes */
void random_array(int arr[], int length);
int selection_sort(int arr[], int length);
void swap(int *previous, int *next);
void print_array(int arr[], int length);
int binary_search(int arr[], int start, int end, int element);
/*  End of prototypes */

/*  Main function start */
int main(void)
{
    // Generates an array of 20 elements and gets the length thereof
    int arr[20];
    int length = sizeof(arr) / sizeof(arr[0]);

    // Populates the array and prints it
    random_array(arr, length);
    printf("Unsorted array: ");
    print_array(arr, length);

    //  Sorts the array and prints it
    selection_sort(arr, length);
    printf("Sorted array:   ");
    print_array(arr, length);

    // Gets the element for the search
    int element = get_int("Find what number? ");

    // Calls the search function and assigns it to the variable "result"
    int result = binary_search(arr, 0, length - 1, element);

    if (result == -1)
    {
        printf("Element is not present in array.\n");
    }
    else
    {
        printf("Element is present at index %d.\n", result);
    }
    return 0;
}
/*  Main function end */

/*  Function implementation*/
void random_array(int arr[], int length)
{
    // Seeds the rand() call to display different numbers when called
    srand(time(NULL));
    for (int i = 0; i < length; i++)
    {
        arr[i] = rand() % 100;
    }
}

int selection_sort(int arr[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < length; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        swap(&arr[min], &arr[i]);
    }

    return 0;
}

void swap(int *previous, int *next)
{
    int temp = *previous;
    *previous = *next;
    *next = temp;
}

void print_array(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        // Last element
        if (i == length - 1)
        {
            printf("%d\n", arr[i]);
        }
        // Any other element
        else
        {
            printf("%d, ", arr[i]);
        }
    }
}

int binary_search(int arr[], int start, int end, int element)
{
    if (end >= start)
    {
        int mid = start + (end - start) / 2;

        /*
         * If the element is present at the middle,
         * then return it.
         */

        if (arr[mid] == element)
            return mid;
        /*
         * If element is smaller than mid, then
         * it can only be present in left subarray
         */

        if (arr[mid] > element)
            return binary_search(arr, start, mid - 1, element);
        /*
         * Else the element can only be present in right subarray
         */
        return binary_search(arr, mid + 1, end, element);
    }

    // If the element is not present in the array
    return -1;
}
/*  End of function implementation */