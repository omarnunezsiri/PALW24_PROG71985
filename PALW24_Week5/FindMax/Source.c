// PAL Week 5 - Program 1:
//					implement findMax function
// 
// PROG71985-W23/F23/W24
// Omar Nunez Siri
// 
// revision history
// 1.0			2023-02-04		initial
// 1.1			2023-09-28		reviewed
// 2.0			2024-02-03		reviewed for W24

#include <stdio.h>

// function implementation without a prototype
int findMax(int firstNum, int secondNum)
{
	int max;

	if (firstNum > secondNum)
		max = firstNum;
	else
		max = secondNum;

	return max;
}

int main(void)
{
	int firstNum = 30;
	int secondNum = 20;

	int max = findMax(firstNum, secondNum);

	printf("The max between %d and %d is: %d", firstNum, secondNum, max);
	return 0;
}