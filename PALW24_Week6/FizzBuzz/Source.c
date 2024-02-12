// PAL Week 6 - Program 2:
//					fizz buzz program (one of my favorites!)
// 
// PROG71985-W23/F23/W24
// Omar Nunez Siri
// 
// revision history
// 1.0			2024-02-10	

#define MAXARR 11
#define FIZZ 3
#define BUZZ 5

void fizzBuzz(int*, int);
#include <stdio.h>

int main(void)
{
	int numbers[MAXARR] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 15};

	fizzBuzz(numbers, MAXARR);
	return 0;
}

// why is it good practice to pass the length of the array?
// 1. ensures no overrun
// 2. usability (any length)
void fizzBuzz(int* numbers, int length)
{
	for (int i = 0; i < length; i++)
	{
		if (numbers[i] % FIZZ == 0 && numbers[i] % BUZZ == 0)
		{
			printf("FizzBuzz\n");
		}
		else if (numbers[i] % FIZZ == 0)
		{
			printf("Fizz\n");
		}
		else if (numbers[i] % BUZZ == 0)
		{
			printf("Buzz\n");
		}
	}
}