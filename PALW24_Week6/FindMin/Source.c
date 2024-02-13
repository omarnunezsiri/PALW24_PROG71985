// PAL Week 6 - Program 4:
//					find the minimum value in an array
// 
// PROG71985-W23/F23/W24
// Omar Nunez Siri
// 
// revision history
// 1.0			2024-02-10

#include <stdio.h>
#include "Color.h"
#define MAXARR 10

// why is it good practice to pass the size of the array to the function?
int findMin(int numbers[], int size)
{
	int min = numbers[0];

	for (int i = 1; i < size; i++)
	{
		if (numbers[i] < min)
		{
			min = numbers[i];
		}
	}

	return min;
}

int main(void)
{
	int numbers[MAXARR] = { 5, 3, 7, 2, 8, 4, 9, 1, 6, 10 };

	printf("The numbers are...\n");
	for (int i = 0; i < MAXARR; i++)
	{
		printf("%d\n", numbers[i]); // what is [i]?
	}

	int min = findMin(numbers, MAXARR);

	MintGreen();
	printf("The minimum value is %d\n", min);
	Reset();

	return 0;
}