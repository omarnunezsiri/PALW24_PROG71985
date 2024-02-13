// PAL Week 6 - Program 4:
//					determine the size of an array
// 
// PROG71985-W23/F23/W24
// Omar Nunez Siri
// 
// revision history
// 1.0			2024-02-10

#include <stdio.h>
#include "Color.h"

void printArray(int numbers[], int size)
{
	SkyBlue();
	for (int i = 0; i < size; i++)
	{
		printf("%d\n", numbers[i]);
	}
	Reset();
}

int main(void)
{
	int numbers[] = { 5, 3, 7, 2, 8, 4, 9, 1, 6, 10 };
	int size = sizeof(numbers) / sizeof(numbers[0]); // what is this line doing?

	printf("The size of the array is %d\n", size);

	printArray(numbers, size);
	return 0;
}