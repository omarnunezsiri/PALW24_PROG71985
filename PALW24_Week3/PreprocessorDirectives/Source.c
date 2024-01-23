// PAL Week 3 - Program 5:
//					preprocessor directives
// 
// PROG71985-W23
// Omar Nunez Siri
// 
// revision history
// 1.0			2023-01-21		initial

#include <stdio.h>

int main(void)
{
	float centimeters;
	printf("Please enter a value (cm): ");

	/* Pre-processor directive: Windows compiler */
#ifdef _WIN32 
	scanf_s("%f", &centimeters);
#else
	scanf("%f", &centimeters); 
#endif

	float meters = centimeters / 100;

	printf("%f cm is %f meters", centimeters, meters);
}