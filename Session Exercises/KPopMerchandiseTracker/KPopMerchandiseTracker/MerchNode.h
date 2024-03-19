#pragma once

#ifndef NODE_H
#define NODE_H

#include "Merchandise.h"

typedef struct Node
{
	KMERCH merch;
	struct Node* next;
}KMNODE, * PKMNODE;

PKMNODE CreateNode(KMERCH);
PKMNODE GetNextNode(PKMNODE);
KMERCH GetNodeKMerch(PKMNODE);
void SetNextNode(PKMNODE, PKMNODE);
void DisposeNode(PKMNODE);

#endif // !NODE_H