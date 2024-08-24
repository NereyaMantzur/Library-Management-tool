#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "MemberManager.h"
#include "LoanManager.h"

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
	strcpy(newMember->phoneNumber, initPhoneNumber());
	newMember->loanCount = 0;
	for (size_t i = 0; i < MAX_BOOKS; i++)
	{
		newMember->loanArr[i] = NULL;
	}
	return newMember;
}

int addNewMember(MemberManager* manager)
{
	printf("\n========================================= Member adding =========================================\n\n");

	manager->memberArr = (Member*)realloc(manager->memberArr, sizeof(Member) * (manager->count + 1));
	if (!manager->memberArr)
	{
		return 0;
	}
	Member* add = initMember();
	add->memberID = initID(manager);
	manager->memberArr[manager->count] = *add;
	manager->count++;
	printf("\n==================================== Member added succesfully! ==================================\n\n");
	return 1;
}

int removeMember(MemberManager* manager)
{
	printf("\n========================================= Member removing =======================================\n\n");
	printMemberArr(manager->memberArr, manager->count);
	printf("Please enter ID of the member you want to remove: ");

	int memberID;
	scanf("%d", &memberID);
	getchar();

	for (int i = 0; i < manager->count; i++)
	{
		if (memberID == manager->memberArr[i].memberID)
		{
			if (manager->memberArr[i].loanCount > 0)
			{
				handleError("Member still has ACTIVE loans!");
				printf("\n===================================== Failed to remove member ===================================\n\n");
				return 0;
			}

			swapMembers(&manager->memberArr[i], &manager->memberArr[manager->count - 1]);
			freeMember(&manager->memberArr[manager->count - 1]);
			manager->count--;
			manager->memberArr = (Member*)realloc(manager->memberArr, sizeof(Member) * (manager->count));
			if (!manager->memberArr)
			{
				break;
			}
			printf("\n========================================= Member removed ========================================\n\n");
			return 1;
		}
	}

	printf("\n===================================== Failed to remove member ===================================\n\n");
	return 0;
}


int printMemberArr(const Member* memberArr, int count)
{
	if (count == 0)
	{
		handleError("No members in the system!\n");
		return 0;
	}

	printf("#  |Member ID           |Member name         |Member phone number\n");
	for (int i = 0; i < count; i++)
	{
		printf("%-2d |", i + 1);
		printMember(&memberArr[i]);
	}	return 1;
}

int printMember(const Member* member)
{
	printf("%-20d|%-20s|%s\n", member->memberID, member->name, member->phoneNumber);
	return 1;
}

void swapMembers(Member* memberA, Member* memberB)

{
	Member temp = *memberA;
	*memberA = *memberB;
	*memberB = temp;
}

int initID(MemberManager* manager)
{
	for (int i = 0; i < manager->count; i++)
	{
		if (manager->memberArr[i].memberID == manager->nextID)
		{
			manager->nextID++;
		}
	}
	return manager->nextID;
}

char* initPhoneNumber()
{
	char phone[11];
	char* temp = NULL;

	do {
		scanf("%s", phone);
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

int freeMember(Member* member)
{
	freeLoanArr(member->loanArr);
	member = NULL;
	return 1;
}

Member* getMemberByID(MemberManager* memberManager, int ID)
{
	for (int i = 0; i < memberManager->count; i++)
	{
		if (memberManager->memberArr[i].memberID == ID)
		{
			return &memberManager->memberArr[i];
		}
	}
	return NULL;
}



int writeMemberManagerToText(FILE* file, MemberManager* manager)
{
	Member* arr = manager->memberArr;
	fprintf(file, "%d\n", manager->count);
	fprintf(file, "Member ID           |Member name         |Member phone number\n");

	for (size_t i = 0; i < manager->count; i++) {
		fprintf(file, "%d\n%s\n%s\n", arr[i].memberID, arr[i].name, arr[i].phoneNumber);
	}

	return 1;
}

int readMemberManagerFromText(FILE* file, MemberManager* manager)
{
	int count = 0;
	fscanf(file, "%d", &count);
	manager->memberArr = (Member*)malloc(count * sizeof(Member));

	if (!manager->memberArr) {
		return 0;
	}

	manager->count = count;
	manager->nextID = count + 1;

	char buffer[256];
	fgets(buffer, sizeof(buffer), file);
	fgets(buffer, sizeof(buffer), file);

	for (size_t i = 0; i < count; i++)
	{
		Member* temp = &manager->memberArr[i];
		char name[256], phone[11];

		fscanf(file, "%d\n", &temp->memberID);
		fgets(name, sizeof(name), file);
		fgets(phone, sizeof(phone), file);

		name[strcspn(name, "\n")] = '\0';
		phone[strcspn(phone, "\n")] = '\0';

		temp->name = (char*)malloc(strlen(name) + 1);
		if (!temp->name) {
			return 0;
		}
		strcpy(temp->name, name);

		strcpy(temp->phoneNumber, phone);

		for (size_t i = 0; i < MAX_BOOKS; i++)
		{
			temp->loanArr[i] = NULL;
		}
	}

	return 1;
}


int writeMemberManagerToBinary(FILE* file, MemberManager* manager)
{
	fwrite(&manager->count, sizeof(int), 1, file);

	for (int i = 0; i < manager->count; i++)
	{
		Member* temp = &manager->memberArr[i];

		fwrite(&temp->memberID, sizeof(int), 1, file);

		int nameLength = (int)strlen(temp->name) + 1;
		fwrite(&nameLength, sizeof(int), 1, file);
		fwrite(temp->name, sizeof(char), nameLength, file);

		fwrite(temp->phoneNumber, sizeof(char), 11, file);
	}

	return 1;
}


int readMemberManagerFromBinary(FILE* file, MemberManager* manager)
{
	int count = 0;
	fread(&count, sizeof(int), 1, file);

	manager->memberArr = (Member*)malloc(count * sizeof(Member));
	if (!manager->memberArr)
	{
		return 0;
	}

	manager->count = count;

	for (int i = 0; i < count; i++)
	{
		Member* temp = (Member*)malloc(sizeof(Member));
		if (!temp)
		{
			return 0;
		}

		fread(&temp->memberID, sizeof(int), 1, file);

		int nameLength = 0;
		fread(&nameLength, sizeof(int), 1, file);
		temp->name = (char*)malloc(nameLength + 1);
		if (!temp->name)
		{
			free(temp);
			return 0;
		}
		fread(temp->name, sizeof(char), nameLength, file);
		temp->name[nameLength] = '\0';

		fread(&temp->phoneNumber, sizeof(char), 11, file);

		manager->memberArr[i] = *temp;
	}

	return 1;

}