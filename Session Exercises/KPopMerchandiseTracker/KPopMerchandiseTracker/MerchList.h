#pragma once

#ifndef LIST_H
#define LIST_H

#include "MerchNode.h"
#include "stdbool.h"
#include <stdio.h>

typedef struct MerchList
{
	PKMNODE head;
}KMLIST, * PKMLIST;

KMLIST CreateList();
bool AddKMerchToList(PKMLIST, KMERCH);
void DisplayList(PKMLIST);
bool StreamWriteList(PKMLIST, char*);
bool StreamReadList(PKMLIST, char*);
void DisposeList(PKMLIST);

#endif // !LIST_H