#include <stdio.h>

void selectionSort(int *a, int *length)
{
    int min, j, i;
    for (i = 0; i < *length - 2; ++i)
    {
        int min = i;
        for (j = i + 1; j < *length; ++j)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        int swapValue = a[i];
        a[i] = a[min];
        a[min] = swapValue;
    }
}
int main()
{
    int a[] = {2, 6, 4, 1, 5, 3};
    int length = sizeof(a) / sizeof(a[0]);
    selectionSort(a, &length);
    for (int k = 0; k < length; k++)
    {
        printf("%d ", a[k]);
    }
    return 0;
}