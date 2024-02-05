// PAL Week 5 - Program 2:
//					implement integerInRange function
// 
// PROG71985-W23/F23/W24
// Omar Nunez Siri
// 
// revision history
// 1.0			2023-02-04		initial
// 1.1			2023-09-28		reviewed
// 2.0			2024-02-03		refactored (function takes 3 arguments)

#include <stdio.h>
#include <stdbool.h>

#define LOWER_LIMIT 0
#define UPPER_LIMIT 65536 // 16-bit integer limits (2^16)

bool integerInRange(int, int, int);

int main(void)
{
	int num;
	bool inRange = false; // why assign it before the loop?
	printf("16-bit Encoder\n");

	do
	{
		printf("Please enter an integer in the 0-2^16 range: ");
		scanf_s("%d", &num); // review - what does _s indicate?

		inRange = integerInRange(num, LOWER_LIMIT, UPPER_LIMIT); // why not use the function directly in the while condition?
		if (inRange)
			printf("%d is in the %d-%d range!\n", num, LOWER_LIMIT, UPPER_LIMIT);
		else
			printf("%d is not in the %d-%d range.\n", num, LOWER_LIMIT, UPPER_LIMIT);

	} while (!inRange);

	return 0;
}

bool integerInRange(int integer, int lowerLimit, int upperLimit)
{
	// can we simplify this?
	if (integer >= lowerLimit && integer <= upperLimit)
		return true;
	else
		return false;
}