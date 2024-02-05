
// PAL Week 5 - Exercise:
// • Prompt the user to enter two numbers
// • Determine the Greatest Common Divisor(GCD) of both
// numbers.
// • Output the divisor back to the user.
// • Bonus Challenge :
//		• Refactor your program to allow the user to keep entering numbers
//			until one of them is a non - positive number(<= 0)
// 
// PROG71985W24
// PAL Attendees: Madison, Nathan
// 
// revision history:
// 1.0			2024-02-05			initial

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int GCD(int, int);

int main() {
	
	/* prompt the user to enter two numbers (do not validate input) */
	int num1;
	int num2;
	int gcd; 
	
	// first number
	printf("Please enter the first number:\n");
	scanf("%d", &num1);

	// second number
	printf("Please enter the second number:\n");
	scanf("%d", &num2);

	/* generate GCD */
	gcd = GCD(num1, num2);

	/* display GCD */
	printf("The greatest common divisor between %d and %d is %d\n", num1, num2, gcd);
	return 0;
}

int GCD(int num1, int num2)
{
	int GCD;

	// Solution 1: Uncomment the following lines
	//int divisor;

	///*
	//* 1. Declaration
	//* 2. Condition
	//* 3. Increment/Decrement (common section)
	//*/
	//for (divisor = 1; divisor <= num1 && divisor <= num2; divisor++)
	//{
	//	if(num1 % divisor == 0 && num2 % divisor == 0)
	//		GCD = divisor;
	//}

	// Solution 2: Uncomment the following lines
	//int num1_loop = num1;
	//int num2_loop = num2;
	//int counter1 = 0;
	//int counter2 = 0;
	//int differnce = 0;

	//while (num1 > 0 || num2 > 0)
	//{

	//	// there's an operation here but nothing being assigned
	//	num1_loop = num1_loop - 1;
	//	counter1++;
	//	num2_loop = num2_loop - 1;
	//	counter2++;
	//	if (num2_loop <= 0)
	//	{
	//		differnce = counter1;
	//		break;
	//	}
	//	if (num1_loop <= 0)
	//	{
	//		differnce = counter2;
	//		break;
	//	}
	//	//printf("%d num1  %d num2\n", num1_loop, num2_loop);
	//}

	////printf("diffence %d\n", differnce);


	//int remainder;
	//for (int loop = 1; loop <= differnce; loop++)
	//{
	//	if (((num1 % loop) == 0) && ((num2 % loop) == 0))
	//	{
	//		remainder = loop;
	//	}
	//	else {
	//		continue;
	//	}
	//}
	//
	//GCD = remainder;

	return GCD;
}