#include <stdio.h>
#include <stdlib.h>

#include "List.h"

List* initList()
{
	List* list = (List*)malloc(sizeof(List));
	if (!list)
	{
		return NULL;
	}
	list->head = initListNode();
	return list;
}

ListNode* initListNode()
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (!newNode)
	{
		return NULL;
	}
	newNode->data = NULL;
	newNode->next = NULL;
	return newNode;
}

List* insertFirst(List* list, void* data) {
	if (!list) {
		return NULL;
	}

	ListNode* newNode = initListNode();
	if (!newNode) {
		return NULL;
	}

	newNode->data = data;
	newNode->next = list->head->next;
	list->head->next = newNode;

	return list;
}

int deleteNode(List* list, ListNode* node) {
	if (!list || !node || !node->next) {
		return 0;
	}

	ListNode* temp = node->next;
	node->data = temp->data;
	node->next = temp->next;
	free(temp);

	return 1;
}




