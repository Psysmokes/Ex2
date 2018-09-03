#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int indexStart;
	int indexEnd;
	struct node* next;
}Node;

Node* createNode(int indexStart, int indexEnd);
void addNode(Node** head, int indexStart, int indexEnd);
