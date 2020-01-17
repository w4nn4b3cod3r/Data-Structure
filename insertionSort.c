#include <stdio.h>

void insertionSort(int *p, int *length)
{
    for(int i = 1; i < *length; i++)
    {
        int key =p[i];
        int j = i - 1;
        while(j >= 0 && p[j] > key)
        {
            p[j+1] = p[j];
            j--;
        }
        p[j+1] = key;
    }
}
int main()
{
    int inSort[] = {2,3,1};
    int len = sizeof(inSort) / sizeof(inSort[0]);
    printf("\nBefore: ");
    for(int i = 0; i < len; i++)
    {
        printf("%d\t", inSort[i]);
    }
    insertionSort(inSort, &len);
    printf("\nAfter: ");
    for(int i = 0; i < len; i++)
    {
        printf("%d\t", inSort[i]);
    }
    return 0;
}