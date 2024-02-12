// PAL Week 6 - Program 3:
//					alter an array/int (pass by val vs. reference)
// 
// PROG71985-W23/F23/W24
// Omar Nunez Siri
// 
// revision history
// 1.0			2024-02-10

#include <stdio.h>

#define MAXARR 10

void alterArray(int*, int);
void alterInt(int);

int main(void)
{
	int originalNum = 5; // 10
	int numbers[MAXARR] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // 2, 4, 6, 8, 10, 12, 14, 16, 18, 20

	// call the function to alter the information
	alterArray(numbers, MAXARR);
	alterInt(originalNum);

	// will this display the altered array?
	for (int i = 0; i < MAXARR; i++)
	{
		printf("%d\n", numbers[i]);
	}

	printf("Original number: %d\n", originalNum); // will this display the altered number?
	return 0;
}

// arrays decay to pointers
// numbers is passed as a reference
void alterArray(int* numbers, int length)
{
	for (int i = 0; i < length; i++)
	{
		numbers[i] = numbers[i] * 2; // alter the array slightly
	}
}	

void alterInt(int number)
{
	number = number * 2; // alter the int slightly
}