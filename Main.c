
/* Please be aware that the code in its current state is in the initial phase and has undergone minimal testing. It is strongly recommended to thoroughly test and make any necessary modifications before utilizing it. */
/* I cannot be held responsible for any issues or difficulties arising from using the code without making appropriate modifications. */
/* doubly linked list implementation in C */
/*
doublyLinkedList Implementation in C
File: Main.c
Author: Malkoot Khan
Date: 13/07/2023
*/

#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true }bool;

struct Node {
	int item;
	struct Node* prev;
	struct Node* next;
};

struct Node* createNode(int data) {
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->item = data;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

void insertAtStart(struct Node** start, int data) {
	struct Node* s = *start;
	struct Node* newNode = createNode(data);
	if (s == NULL) {
		*start = newNode;
		return;
	}
	newNode->next = *start;
	(*start)->prev = newNode;
	*start = newNode;
}

void display(struct Node* start) {
	if (start == NULL) {
		printf("The list is empty!\n");
		return;
	}
	struct Node* t = start;
	while (t != NULL) {
		printf("%d ", t->item);
		t = t->next;
	}
	printf("\n");
}
void insertAtEnd(struct Node** start, int data) {
	struct Node* newNode = createNode(data);
	if (*start == NULL) {
		*start = newNode;
		return;
	}
	struct Node* s = *start;
	while (s->next != NULL) 
		s = s->next;
	s->next = newNode;
	newNode->prev = s;
}
void search(struct Node** start, int item) {
	if (*start == NULL) {
		printf("The list is empty!\n");
		return;
	}
	struct Node* s = *start;
	while (s != NULL) {
		if (item == s->item) {
			printf("Item found!\n");
			return;
		}
		s = s->next;
	}
	printf("Item not found!\n");
}
void insertAtPos(struct Node** start, int data, int pos) {
	struct Node* newNode = createNode(data);
	struct Node* s = *start;
	if (pos == 0) {
		newNode->next = *start;
		(*start)->prev = newNode;
		*start = newNode;
		return;
	}
	int count = 1;
	while (s != NULL) {
		if (count == pos) {
			struct Node* t = s->prev;
			newNode->next = s;
			s->prev = newNode;
			newNode->prev = t;
			t->next = newNode;
			return;
		}
		s = s->next;
		count++;
	}
	printf("Invalid Position!\n");
}
void deleteFirst(struct Node** start) {
	if (*start == NULL) {
		printf("The list is empty!\n");
		return;
	}
	struct Node* t = *start;

	if ((*start)->next == NULL)
	{
		free(*start);
		*start = NULL;
		return;
	}
	*start = t->next;
	free(t);
	(*start)->prev = NULL;
}
void deleteLast(struct Node** start) {
	if (*start == NULL) {
		printf("The list is empty!\n");
		return;
	}
	struct Node* s = *start;
	if (s->next == NULL) {
		free(s);
		*start = NULL;
		return;
	}
	while (s->next != NULL)
		s = s->next;
	s->prev->next = NULL;
	free(s);
}
void deleteAtPos(struct Node** start, int pos) {
	struct Node* s = *start;
	if (*start != NULL) {

		if (pos == 0) {
			*start = s->next;
			(*start)->prev = NULL;
			free(s);
			return;
		}
		int count = 0;
		while (s != NULL) {
			if (count == pos)
			{
				s->prev->next = s->next;
				s->next->prev = s->prev;
				free(s);
				return;
			}
			s = s->next;
			count++;
		}
		printf("Invalid Position!\n");
		return;
	}
	printf("The list is empty!\n");
}
int main() {
	struct Node* head = NULL;
	insertAtEnd(&head,10);
	insertAtEnd(&head, 20);
	insertAtEnd(&head, 30);
	insertAtEnd(&head, 40);
	display(head);
	insertAtPos(&head, 500, 2);
	display(head);
	printf("after delete\n");
	deleteAtPos(&head, 3);
	display(head);
	deleteAtPos(&head, 1);
	display(head);
	//deleteFirst(&head);
	deleteAtPos(&head, 0);
	deleteAtPos(&head, 2);
	display(head);


	return 0;
}

