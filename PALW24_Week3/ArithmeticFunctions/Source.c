// PAL Week 3 - Program 3:
//					arithmetic functions
// 
// PROG71985-W23
// Omar Nunez Siri
// 
// revision history
// 1.0			2023-01-21		initial

#include <stdio.h>

#define MINUTES_IN_HOUR 60 // MACRO (constant): assign the value 60 to MINUTES_IN_HOUR
int main(void)
{
	// variables
	int seconds = 31536000;                  // seconds in a year (365.2425 days)
	int minutes = 525600;	 				 // minutes in a year (365.2425 days)
	int hours = minutes / MINUTES_IN_HOUR;   // convert minutes to hours in a year

	printf("A year has %d seconds, %d minutes and %d hours.\n", seconds, minutes, hours);
	return 0;
}