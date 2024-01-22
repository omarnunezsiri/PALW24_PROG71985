// PAL Week 3 - Program 2:
//					scanf and scanf_s
// 
// PROG71985-W23
// Omar Nunez Siri
// 
// revision history
// 1.0			2023-01-21		initial

#define _CRT_SECURE_NO_WARNINGS // to use the scanf (unsafe) function

#include <stdio.h>

int main(void)
{
	int cats;
	int dogs;

	printf("How many cats do you have?\n");
	scanf("%d", &cats); 
	printf("So you have %d cat(s)!\n", cats);

	printf("Now...how many dogs do you have?\n");
	scanf_s("%d", &dogs); // _s stands for secure
	printf("So you have %d dog(s) and %d cat(s)!\n", dogs, cats);
	return 0;
}