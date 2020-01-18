#include <stdio.h>

void displayArray(int d_array[], int* length);
void merge_sort(int d_array[], int left, int right);
void mergeArray(int d_array[], int left, int middle, int right);

int main()
{
	int un_array[] = { 2,4,1,3 };
	printf("Before: ");
	int length = sizeof(un_array) / sizeof(un_array[0]);
	displayArray(un_array, &length);
	//printf("\nSize of the array: %d\n", length);
	printf("After: ");
	merge_sort(un_array, 0, (length-1));
	displayArray(un_array, &length);
	return 0;
}
void merge_sort(int d_array[], int left, int right)
{
	int mid = 0;
	if (left < right) {
		mid = ((left + right) / 2); // devided the array to a subarray
		// for the left array
		merge_sort(d_array, left, mid);
		// for the right array
		merge_sort(d_array, (mid + 1), right);
		// merging the left and right array in sorted way to a new array
		mergeArray(d_array, left, mid, right);
	}
}
void mergeArray(int d_array[], int left, int middle, int right)
{
	int i, j, k; int q[4] = { 0 };
	i = left; j = (middle + 1); k = 0;
	for (;;) {
		if (d_array[i] < d_array[j])
			q[k++] = d_array[i++];
		else
			q[k++] = d_array[j++];
		if (i > middle || j > right)
			break;
	}
	while (i <= middle) q[k++] = d_array[i++];
	while (j <= right) q[k++] = d_array[j++];
	k = 0;
	for (int l = left; l <= right; l++)
	{
		d_array[l] = q[k++];
	}
}
void displayArray(int d_array[], int* length)
{
	for (int i = 0; i < *(length); i++)
	{
		printf("%d ", d_array[i]);
	}
	printf("\n");
}
