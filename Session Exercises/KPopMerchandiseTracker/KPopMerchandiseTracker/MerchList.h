#pragma once

#ifndef LIST_H
#define LIST_H

#include "MerchNode.h"
#include "stdbool.h"
#include <stdio.h>

typedef struct List
{
	PNODE head;
}LIST, * PLIST;

LIST CreateList();
bool AddKMerchToList(PLIST, KMERCH);
void DisplayList(LIST);
void DisposeList(PLIST);

#endif // !LIST_H