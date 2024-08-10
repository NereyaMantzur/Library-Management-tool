#include <stdio.h>
#include <stdlib.h>

#include "List.h"

int initList(List* list)
{
	if (!list)
	{
		return 0;
	}
	list->head.next = NULL;
	return 1;
}

