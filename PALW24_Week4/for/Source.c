// PAL Week 4 - Program 3:
//					use of for loop to determine the factors of a number
// 
// PROG71985-W23/F23
// Omar Nunez Siri
// 
// revision history
// 1.0			2023-01-28		initial
// 2.0			2023-09-21		refactored (for loop)
// 3.0			2023-01-27		refactored (input validation)

#include <stdio.h>
#include <stdlib.h> // what is this library for?

int main(void)
{
	int number;
	printf("Please enter a number to determine its factors: ");
	int items_scanned = scanf_s("%d", &number);

	// trust the user, but always verify ;)
	if (items_scanned != 1)
	{
		printf("You did not enter an integer");
		exit(EXIT_FAILURE);
	}

	for (int counter = 1; counter <= number; counter++) // do we need to include the number given or not?
	{
		if (number % counter == 0)
			printf("%d is a factor of %d\n", counter, number);
	}


	return 0;
}