// PAL Week 5 - Program 4:
//					implement findMin function
// 
// PROG71985-W23/F23
// Omar Nunez Siri
// 
// revision history
// 1.0			2023-02-04		initial
// 1.1			2023-10-03		reviewed

#include <stdio.h>

int findMin(int, int);

int main(void)
{
	int firstNum = 350;
	int secondNum = 15;

	int min = findMin(firstNum, secondNum); 

	printf("The min between %d and %d is: %d", firstNum, secondNum, min);
	return 0;
}

// what if we wanted to refactor this to find the max as well?
// 1. we could pass a pointer to reference min and max in the function
// 2. or we could assume that firstNum will be the min and secondNum will be the max
int findMin(int firstNum, int secondNum)
{
	int min;

	if (firstNum < secondNum)
		min = firstNum;
	else
		min = secondNum;

	return min;
}