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
	if (!list || !node) {
		return 0;
	}

	if (node == list->head) {
		list->head = node->next;
		free(node);
		return 1;
	}

	ListNode* prev = list->head;
	while (prev && prev->next != node) {
		prev = prev->next;
	}


	if (prev && prev->next == node) {
		prev->next = node->next;
		free(node);
		return 1;
	}

	return 0;
}






