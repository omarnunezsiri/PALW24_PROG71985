#define _CRT_SECURE_NO_WARNINGS // we will touch on this in the following week's sessions

#include <stdio.h>

int main(void)
{
	int cats;

	printf("How many cats do you have?\n");
	scanf("%d", &cats); // ignore the green squiggle line under the statement for now
	printf("So you have %d cat(s)!\n", cats);
	return 0;
}