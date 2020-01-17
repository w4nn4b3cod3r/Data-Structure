// Understand the theory of the bubble sort
// here both v1 & v2 version of bubble sort is implemented 
// v2 is where array is already sorted then break the program quickly


#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int *p, int *length)
{
    int i , j;
    for( i = 0; i < *length; i++)
    {
        bool isSorted = true;
        for(j = i+1; j <= *length-1; j++)
        {
            if(p[i] > p[j])
            {
                int swap = p[i];
                p[i] = p[j];
                p[j] = swap;
                isSorted = false;
            }
        }// end of inner loop
        if(isSorted){
            printf("\n\t\t\tAlready sorted array.\n");
            return;
        }
    }
}
int main() 
{ 
    int bblesort[] = {7,2,5,4,1,0,3,6};
    int sortedArr[] = {1,2,3,4,5,6};
    printf("\t\t\tBefore: ");
    int length = sizeof(bblesort) / sizeof(bblesort[0]);
    int len2 = sizeof(sortedArr) / sizeof(sortedArr[0]);
    for (int i = 0; i < length; i++)
    {
        printf("%d ", bblesort[i]);
    }
    printf("\n");
    bubbleSort(bblesort, &length);
    printf("\t\t\tAfter: ");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", bblesort[i]);
    }
    return 0;
}