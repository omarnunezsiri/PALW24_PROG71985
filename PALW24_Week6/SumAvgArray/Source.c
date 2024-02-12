// PAL Week 6 - Program 1:
//					determines the sum and average given an array of grades (floats)
// 
// PROG71985-W23/F23/W24
// Omar Nunez Siri
// 
// revision history
// 1.0			2023-02-11		initial
// 1.1			2023-10-10		reviewed
// 1.2			2024-02-10		reviewed for W24

#include <stdio.h>

#define MAX_ARRAY 10
int main(void)
{
	// do we need to specify the size of the array?
	float grades[MAX_ARRAY] = { 90.2, 70.0, 65.2, 95.1, 90.0, 90.0, 89.99, 100.0, 99.5, 93.3 };

	float sum = 0;
	float average;

	// why do we favor the for loop over others?
	for (int i = 0; i < MAX_ARRAY; i++)
	{
		printf("%f\n", grades[i]);
		sum += grades[i]; // what does [i] do?
	}

	average = sum / MAX_ARRAY;
	printf("Sum of the grades: %f\n", sum);
	printf("Average grade: %f\n", average);
	return 0;
}

// extra note: can we design a function to calculate the sum and average?