// PAL Week 7 - Midterm Review - Examine a C Program
//							PizzaStore
// 
// PROG71985-W23/F23
// Omar Nunez Siri
// 
// revision history
// 1.0			2023-02-20		initial
// 2.0			2023-10-14		reviewed/refactored

#define _CRT_SECURE_NO_WARNINGS
#define DATAFILE "PizzaStore.txt" // MACRO

#include <stdio.h> // standard input and output streams (stdin, stdout)
#include "Pizza.h"
#include "Utils.h"

int main(void)
{
	cyan();
	printf("-------------------- Welcome to the Pizza Store Creator --------------------\n");
	reset();

	/* Replace with any examples from below */
	PIZZA myPizza = CreatePizza(1);

	printf("Dough is ready...Proceed to enter %d toppings!\n", MAXTOPPINGS);
	for (int i = 1; i <= MAXTOPPINGS; i++)
	{
		char toppingName[MAXSTR];
		printf("\nEnter topping %d: ", i);

		// Using fgets for user input :)
		fgets(toppingName, MAXSTR, stdin);
		//scanf("%s", toppingName);
		removeTrailingNewLine(toppingName);

		// Add the new topping to the Pizza !
		AddNewTopping(&myPizza, CreateTopping(i, toppingName));

		green();
		printf("Successfully added topping %s to the pizza.\n", toppingName);
		reset();
	}

	yellow();
	printf("\nPizza...");
	DisplayPizza(myPizza);
	reset();

	StreamWritePizza(myPizza, DATAFILE); // save new pizza info to datafile
	return 0;
}

/*
* Example without an existing datafile
	PIZZA myPizza = CreatePizza(1);

	printf("Dough is ready...Proceed to enter %d toppings!\n", MAXTOPPINGS);
	for (int i = 1; i <= MAXTOPPINGS; i++)
	{
		char toppingName[MAXSTR];
		printf("\nEnter topping %d: ", i);

		// Using fgets for user input :)
		fgets(toppingName, MAXSTR, stdin);
		removeTrailingNewLine(toppingName);

		// Add the new topping to the Pizza !
		AddNewTopping(&myPizza, CreateTopping(i, toppingName));

		green();
		printf("Successfully added topping %s to the pizza.\n", toppingName);
		reset();
	}

	yellow();
	printf("\nPizza...");
	DisplayPizza(myPizza);
	reset();

	StreamWritePizza(myPizza, DATAFILE); // save new pizza info to datafile
*/

/*
* Example with existing datafile
	PIZZA myPizza;
	StreamReadPizza(&myPizza, DATAFILE);

	yellow();
	printf("\nPizza...");
	DisplayPizza(myPizza);
	reset();

	StreamWritePizza(myPizza, DATAFILE);
*/