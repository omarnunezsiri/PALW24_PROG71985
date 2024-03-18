#pragma once

#ifndef NODE_H
#define NODE_H

#include "Merchandise.h"

typedef struct Node
{
	KMERCH merch;
	struct Node* next;
}NODE, * PNODE;

PNODE CreateNode(KMERCH);
PNODE GetNextNode(PNODE);
KMERCH GetNodeKMerch(PNODE);
void SetNextNode(PNODE, PNODE);
void DisposeNode(PNODE);

#endif // !NODE_H