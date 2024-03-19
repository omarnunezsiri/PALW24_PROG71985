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
}KMERCH;

// a creator/constructor (skip this for now)
KMERCH CreateMerch(char*, char*, char*, float, bool);

// setters
void setMerchName(KMERCH*, char*);
void setMerchType(KMERCH*, char*);
void setMerchIdolGroup(KMERCH*, char*);
void setMerchPrice(KMERCH*, float);
void setMerchOwnership(KMERCH*, bool);

/* // prefer pointers over creating copies to *get* information */

// getters
char* getMerchName(KMERCH*);
char* getMerchType(KMERCH*);
char* getMerchIdolGroup(KMERCH*);
float getMerchPrice(KMERCH*);
bool getMerchOwnership(KMERCH*); 

// display
void displayMerchInformation(KMERCH*);

// file i/o
void writeMerchToFile(KMERCH*, FILE*);
KMERCH* readMerchFromFile(FILE*);


#endif // !MERCHANDISE_H