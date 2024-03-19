// PAL Week 11 - Examine a C Program - Item ADT header
// 
// PROG71985-W23
// Omar Nunez Siri
// 
// revision history
// 1.0			2023-03-19		initial

#pragma once

#ifndef ITEM_H
#define ITEM_H

#include <stdio.h>

typedef struct Item
{
	short int id;
}ITEM, * PITEM;

ITEM CreateItem(short int);
void DisplayItem(ITEM);
void StreamWriteItem(ITEM, FILE*);
ITEM StreamReadItem(FILE*);
void DisposeItem(PITEM);

#endif // !ITEM_H