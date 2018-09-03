#include "node.h";


Node* createNode(int indexStart, int indexEnd) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->indexEnd = indexEnd;
	p->indexStart = indexStart;
	p->next = NULL;
};
void addNode(Node** head, int indexStart, int indexEnd) {
	Node* p = createNode(indexStart, indexEnd);
	Node* temp = NULL;
	if (*head == NULL) {
		head = p;
	}
	else {
		
		temp = *head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		
		temp->next = p;
	}
}