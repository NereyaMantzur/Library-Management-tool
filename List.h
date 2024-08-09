#ifndef LIST_H
#define LIST_H


typedef struct ListNode
{
	void* data;
	struct ListNode* next;
}ListNode;

typedef struct List
{
	ListNode head;
}List;

#endif // !LIST_H
