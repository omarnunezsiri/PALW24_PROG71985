// PAL Week 5 - Program 5:
//					implement displayFactors function
// 
// PROG71985-W23/F23
// Omar Nunez Siri
// 
// revision history
// 1.0			2023-02-04		initial
// 1.1			2023-10-03		reviewed

#include <stdio.h>
#include <stdbool.h>
void displayFactors(int);

int main(void)
{
	int num;
	printf("Please enter a positive integer: ");

	scanf_s("%d", &num);

	// checking if the number is positive
	bool isPositive = num > 0;

	// if the number is positive, display the factors; else, display an error message
	if (isPositive)
	{
		displayFactors(num);
	}
	else 
	{
		printf("You did not enter a positive integer. Exiting the program...\n");
	}
	
	return 0;
}

void displayFactors(int num)
{
	/*
	* Quick Review of For Loops
	* 1. Initialization
	* 2. Condition
	* 3. Increment/Decrement (common section)
	*/
	for (int i = 1; i <= num; i++)
	{
		if (num % i == 0)
		{
			printf("%d\n", i);
		}
	}
}