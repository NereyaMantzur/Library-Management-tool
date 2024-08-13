#ifndef LIST_H
#define LIST_H


typedef struct ListNode
{
	void* data;
	struct ListNode* next;
}ListNode;

typedef struct List
{
	ListNode* head;
}List;

List* initList();
ListNode* initListNode();
List* insertFirst(List* list, void* data);
int deleteNode(ListNode* node);


#endif // !LIST_H
