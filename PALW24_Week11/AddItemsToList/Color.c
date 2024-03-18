#include "Color.h"

/* Colored output */
void cyan()
{
	printf("\033[0;36m");
}

void green()
{
	printf("\033[0;32m");
}

void yellow()
{
	printf("\033[0;33m");
}

void reset()
{
	printf("\033[0m");
}