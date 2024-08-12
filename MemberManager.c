#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "MemberManager.h"

MemberManager* initMemberManager()
{
	MemberManager* manager = (MemberManager*)malloc(sizeof(MemberManager));
	if (!manager)
	{
		return NULL;
	}
	manager->memberArr = NULL;
	manager->count = 0;
	manager->nextID = 1;
	return manager;
}

Member* initMember()
{
	Member* newMember = (Member*)malloc(sizeof(Member));
	if (!newMember)
	{
		return NULL;
	}
	newMember->memberID = -1;
	printf("Please enter Member name: ");
	newMember->name = getStr();
	printf("Please enter phone numer [10 digits]: ");
	newMember->phoneNumber = initPhoneNumber();
	//newMember->loanArr = initLoanArr(MAX_BOOKS);

	return newMember;
}

int addNewMember(MemberManager* manager)
{
	printf("\n============================== Member adding ==============================\n\n");

	manager->memberArr = (Member*)realloc(manager->memberArr, sizeof(Member) * (manager->count + 1));
	if (!manager->memberArr)
	{
		return 0;
	}
	Member* add = initMember();
	add->memberID = manager->nextID++;
	manager->memberArr[manager->count] = *add;
	manager->count++;
	printf("\n========================= Member added suuccesfully! ======================\n\n");
	return 1;
}

int removeMember(MemberManager* manager)
{
	printf("\n============================== member removing ============================\n\n");
	printMemberArr(manager->memberArr, manager->count);
	printf("Please enter ID of the member you want to remove: ");
	int memberID;
	scanf("%d", &memberID);
	getchar();
	for (int i = 0; i < manager->count; i++)
	{
		if (memberID == manager->memberArr[i].memberID)
		{
			//if (manager->memberArr[i].loanArr != NULL)
			//{
			//	printf("\n=========================== Failed to remove member =========================\n\n");
			//	return 0;
			//}
			swapMembers(&manager->memberArr[i], &manager->memberArr[manager->count - 1]);
			freeMember(&manager->memberArr[manager->count - 1]);
			manager->count--;
			printf("\n=============================== member removed! =============================\n\n");
			return 1;
		}
	}
	printf("\n========================== Failed to remove member ========================\n\n");
	return 0;
}

void printMemberArr(const Member* memberArr, int count)
{
	if (count == 0)
	{
		handleError("No members in the system!\n");
		return;
	}

	printf("#  |Member ID      |Member name    |Member phone number\n");
	for (int i = 0; i < count; i++)
	{
		printf("%-2d |", i + 1);
		printMember(&memberArr[i]);
	}
}

void printMember(const Member* member)
{
	printf("%-15d|%-15s|%s\n", member->memberID, member->name, member->phoneNumber);
}

void swapMembers(Member* memberA, Member* memberB)

{
	Member temp = *memberA;
	*memberA = *memberB;
	*memberB = temp;
}

int freeMember(Member* member)
{
	//freeLoanArr(member->loanArr);
	free(member);
	return 1;
}

char* initPhoneNumber()
{
	char phone[11];
	char* temp = NULL;

	do {
		scanf("%10s", phone);
		getchar();

		if (isValidPhone(phone)) {
			temp = (char*)malloc(strlen(phone) + 1);
			if (temp) {
				strcpy(temp, phone);
			}
		}
		else {
			printf("Invalid phone number. Try again.\n");
		}
	} while (!temp);

	return temp;
}

int isValidPhone(char* phone)
{
	if (!phone || strlen(phone) != 10) {
		return 0;
	}

	while (*phone) {
		if (!isdigit(*phone)) {
			return 0;
		}
		phone++;
	}

	return 1;
}
