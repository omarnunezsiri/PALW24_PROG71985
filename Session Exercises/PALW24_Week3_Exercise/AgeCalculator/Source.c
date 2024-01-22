// PAL Week 3 - Exercise:
//					Prompt user for age in years and convert to months, days and hours
// 
// PROG71985-W23
// Madison
// 
// revision history
// 1.0			2024-01-22		initial
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#define MONTHS_IN_YEAR 12
#define DAYS_IN_YEAR 365
#define HOURS_IN_YEAR 8760

int main(void) {
	printf("Hello from Madison\n");

	// Prompt the user to enter their age (in years)
	int age_in_years;
	
	printf("Please enter your age in years\n");
	scanf("%d", &age_in_years);
	printf("You are %d years old.\n", age_in_years);

	// challenge: check if the user is an adult or not and if they are then proceed with the usual program
	if (age_in_years >= 18) {
		// Calculate and display their age in: Months, Days and Hours
		int age_in_months = MONTHS_IN_YEAR * age_in_years;
		int age_in_days = DAYS_IN_YEAR * age_in_years;
		int age_in_hours = HOURS_IN_YEAR * age_in_years;

		printf("You are an adult.\n");
		printf("You are %d months old, %d days old, and %d hours old.", age_in_months, age_in_days, age_in_hours);
	}
	else {
		printf("You are not an adult\n");
		printf("Exiting...");
		exit(EXIT_FAILURE);
	}

	return 0;
}