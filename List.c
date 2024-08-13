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
	list->head = NULL;
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
	newNode->next = list->head;
	list->head = newNode;
	return list;
}


int deleteNode(ListNode* node) {
	if (!node || !node->next) {
		return 0;
	}
	ListNode* temp = node->next;
	node->next = temp->next;
	free(temp);
	return 1;
}


