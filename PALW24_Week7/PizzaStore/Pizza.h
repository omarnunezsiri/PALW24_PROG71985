// PAL Week 7 - Pizza ADT header
// 
// PROG71985-F23
// Omar Nunez Siri
// 
// revision history
// 1.0			2023-10-15		initial

#pragma once
#include "Topping.h"

#define MAXTOPPINGS 5

typedef struct Pizza {
	int id;
	int currentIndex; // to indicate how many toppings we currently have
	TOPPING toppings[MAXTOPPINGS]; // reusing the topping struct
}PIZZA;

PIZZA CreatePizza(int); // creates a Pizza
void DisplayPizza(PIZZA); // displays a Pizza
void AddNewTopping(PIZZA*, TOPPING); // adds a new topping
void StreamWritePizza(PIZZA, char[]); // writes a Pizza to a file
void StreamReadPizza(PIZZA*, char[]); // reads a Pizza from a file