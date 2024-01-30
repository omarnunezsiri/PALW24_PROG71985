// PAL Week 4 - Program 4:
//					use of for-loop to calculate PI^exponent
// 
// PROG71985-W23/F23
// Omar Nunez Siri
// 
// revision history
// 1.0			2023-01-28		initial
// 1.1			2023-09-25		reviewed

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

int main(void)
{
	int exponent; // given by user input (PI^exponent)
	double power;

	printf("PI to the power of: ");

	int user_input = scanf("%d", &exponent);

	// checking for valid input
	if (user_input != 1)
	{
		printf("You did not enter an integer. Cya...\n");
		exit(EXIT_FAILURE);
	}

	power = pow(PI, exponent); // using math pow function

	printf("PI^%d = %lf\n", exponent, power);
	return 0;
}

/*
*	int exponent; // given by user input (PI^exponent)
*	double power = 1;

*	printf("PI to the power of: ");
*	scanf("%d", &exponent); // how do we deal with the current green squiggle line?

	* 1. Declaration or variable initialization
	* 2. Condition
	* 3. Common (decrement/increment)

	for (int i = 1; i <= exponent; i++)
	{
		power = power * PI;
	}

	printf("PI^%d = %lf\n", exponent, power);
	return 0;
*/