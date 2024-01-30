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

#define PI 3.14159265359

int main(void)
{
	int exponent; // given by user input (PI^exponent)
	double power = 1;

	printf("PI to the power of: ");
	scanf("%d", &exponent); // how do we deal with the current green squiggle line?

	for (int i = 1; i <= exponent; i++)
	{
		power = power * PI;
	}

	printf("PI^%d = %lf\n", exponent, power);
	return 0;
}