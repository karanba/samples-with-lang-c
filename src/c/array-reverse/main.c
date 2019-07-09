#include <stdio.h>
#include <stdlib.h>

void reverse(int arr[], int size)
{
	int temp;

	for(int i = 0; i < size / 2; i++)
	{
		temp = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - 1 - i] = temp;
	}
	
}

void printArray(int arr[], int size)
{
	for(int i=0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
}

int main(int argc, char** argv)
{
	
	int arr[9] = {1,2,3,4,5,6,7,8,9};
	int size = sizeof(arr) / sizeof(arr[0]);
	printArray(arr, size);
	reverse(arr, size);
	printArray(arr, size);

	return 0;
}

