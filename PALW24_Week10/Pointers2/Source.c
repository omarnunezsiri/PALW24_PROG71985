// PAL Week 10 - Examine a C Program - Reviewing pointers using structures
// 
// PROG71985-W23/W24
// 
// revision history
// 1.0			2023-03-12		initial
// 2.0			2023-03-09		refactored

#include <stdio.h>
#include <stdbool.h>

#define MIN_GRADE 0
#define MAX_GRADE 100

typedef struct Grade
{
	float floatingGrade; // 0-100
	char letter;         // SABCDF
	bool pass;           // true (passed) ; false (didn't pass)
}GRADE;

void setGradeFloatingGrade(GRADE* g, float newGrade)
{
	if (newGrade >= MIN_GRADE && newGrade <= MAX_GRADE)
	{
		g->floatingGrade = newGrade;
	}
}

void displayGrade(GRADE g)
{
	printf("val: %.1f -- letter: %c -- pass? %d\n", g.floatingGrade, g.letter, g.pass);
}

int main(void)
{
	GRADE newGrade = { .floatingGrade = 91.33, .letter = 'S', .pass = true };

	displayGrade(newGrade);

	GRADE* pGrade = &newGrade; // structures are datatypes, we can have pointers to structures!
	setGradeFloatingGrade(pGrade, 70.333333);
	pGrade->letter = 'C';

	displayGrade(*pGrade); // notice how we are changing pGrade but displaying newGrade?

	printf("%p --- %p\n", &newGrade, pGrade); // what will this display?
	return 0;
}