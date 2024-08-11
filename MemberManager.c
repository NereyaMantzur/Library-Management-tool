#include <stdio.h>
#include <stdlib.h>

#include "MemberManager.h"

MemberManager* initMemberManager()
{
	MemberManager* memberManager = (MemberManager*)malloc(sizeof(MemberManager));
	return memberManager;
}