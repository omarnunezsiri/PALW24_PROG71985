// PAL Week 7 - Pizza ADT implementation
// 
// PROG71985-F23
// Omar Nunez Siri
// 
// revision history
// 1.0			2023-10-15		initial

#define _CRT_SECURE_NO_WARNINGS

#include "Pizza.h"
#include <stdlib.h>

PIZZA CreatePizza(int id)
{
	PIZZA Pizza;

	Pizza.id = id;
	Pizza.currentIndex = 0;

	return Pizza;
}

void DisplayPizza(PIZZA thisPizza)
{
	printf("id: %d\n", thisPizza.id);
	printf("currentIndex: %d\n", thisPizza.currentIndex);
	printf("\nToppings:\n");

	for (int i = 0; i < thisPizza.currentIndex; i++)
	{
		DisplayTopping(thisPizza.toppings[i]);
	}
}


// Pass by Reference/Value review
void AddNewTopping(PIZZA* thisPizza, TOPPING newTopping)
{
	thisPizza->toppings[thisPizza->currentIndex] = newTopping; // modifying the collection of toppings
	thisPizza->currentIndex++; // currentIndex will be modified
}

void StreamWritePizza(PIZZA thisPizza, char filename[])
{
	FILE* fp = fopen(filename, "w"); // what does "w" mean?
	if (!fp) // file doesn't exist or is corrupted
	{
		fprintf(stderr, "Error opening %s. Exiting...\n", filename);
		exit(1);
	}
	else
	{
		fprintf(fp, "%d\n", thisPizza.id);
		fprintf(fp, "%d\n", thisPizza.currentIndex);

		for (int i = 0; i < thisPizza.currentIndex; i++) // looping through the collection of toppings
		{
			StreamWriteTopping(thisPizza.toppings[i], fp);
		}

		fclose(fp); // don't forget to close your files!
	}
}

void StreamReadPizza(PIZZA* newPizza, char filename[])
{
	FILE* fp = fopen(filename, "r"); // what does "r" mean?
	if (!fp)
	{
		fprintf(stderr, "Error opening %s. Exiting...\n", filename);
		exit(1);
	}
	else
	{
		int id;
		int currentIndex;
		fscanf_s(fp, "%d\n", &id); // read the Pizza's id
		*newPizza = CreatePizza(id);

		fscanf_s(fp, "%d\n", &currentIndex); // read the number of toppings

		/* Read all toppings */
		for (int i = 0; i < currentIndex; i++)
		{
			TOPPING newTopping = StreamReadTopping(fp);
			AddNewTopping(newPizza, newTopping);
		}

		fclose(fp); // don't forget to close your files!
	}
}