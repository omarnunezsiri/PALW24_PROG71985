// PAL Project - K-Pop Merchandise ADT header file
// 
// PROG71985-W24
// PAL Attendees
//
// revision history
// 1.0			2024-03-11		initial version

#pragma once
#ifndef MERCHANDISE_H
#define MERCHANDISE_H

#include <stdbool.h>
#include <stdio.h>

#define MAX_NAME 50
#define MAX_IDOL 30
#define MAX_TYPE 20

typedef struct Merchandise {
	char name[MAX_NAME]; // Name of the item, i.e. "BTS Love Yourself Sweatshirt" 
	char type[MAX_TYPE]; // Type of item, i.e. "Sweatshirt"
	char idol[MAX_IDOL]; // Name of idol/group item belongs to, i.e. "BTS", "Red Velvet"
	float price; // Price of item, i.e. $33.77CAD
	bool owned; // Whether the fan already owns this item
}KMERCH, *PKMERCH;

// a creator/constructor (skip this for now)
KMERCH CreateMerch(char*, char*, char*, float, bool);

// setters
void setMerchName(PKMERCH, char*);
void setMerchType(PKMERCH, char*);
void setMerchIdolGroup(PKMERCH, char*);
void setMerchPrice(PKMERCH, float);
void setMerchOwnership(PKMERCH, bool);

/* // prefer pointers over creating copies to *get* information */

// getters
char* getMerchName(PKMERCH);
char* getMerchType(PKMERCH);
char* getMerchIdolGroup(PKMERCH);
float getMerchPrice(PKMERCH);
bool getMerchOwnership(PKMERCH); 

// display
void displayMerchInformation(PKMERCH);

// file i/o
void writeMerchToFile(PKMERCH, FILE*);
void readMerchFromFile(FILE*, PKMERCH);


#endif // !MERCHANDISE_H