// PAL Week 10 - Examine a C Program - Reviewing pointers using floats
// 
// PROG71985-W23/W24
// 
// revision history
// 1.0			2023-03-13		initial
// 2.0			2024-03-09		refactored

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	// Height in centimeters
	float* pHeight = (float*)malloc(sizeof(float)); // magic! what's going on here?
	// allocating memory *dynamically*

	// always check! but what exactly are we checking?
	// maybe we don't have enough memory
	if (pHeight == NULL)
	{
		fprintf(stderr, "Error allocating memory. Exiting!");
		exit(EXIT_FAILURE);
	}

	*pHeight = 2.50f;
	printf("*pHeight: %f -- pHeight: %p\n", *pHeight, pHeight);

	float anotherHeightInCm = *pHeight; // copy
	anotherHeightInCm = 7.50f; // will this also change the value at pHeight?

	printf("another: %f -- *pHeight: %f\n", anotherHeightInCm, *pHeight);

	free(pHeight); // why is this important? clear memory (avoids memory leaks)
	return 0;
}