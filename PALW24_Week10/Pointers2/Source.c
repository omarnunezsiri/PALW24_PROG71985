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
	// trust, but verify
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
	// 0xAA
	GRADE newGrade = { .floatingGrade = 91.33, .letter = 'S', .pass = true };

	displayGrade(newGrade);
	// 91.33 ---- S --- 1

	GRADE* pGrade = &newGrade; // structures are datatypes, we can have pointers to structures!
	setGradeFloatingGrade(pGrade, -60.0f);
	//pGrade->letter = 'X';

	displayGrade(newGrade); // notice how we are changing pGrade but displaying newGrade?
	// 70.33333 -- C --- 1

	printf("%p --- %p\n", &newGrade, pGrade); // what will this display? 0xAA --- 0xAA
	return 0;
}