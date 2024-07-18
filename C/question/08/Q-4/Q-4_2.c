#include <stdio.h>
#include "Member.h"
#include "CircDblLinkedList.h"

typedef enum
{
	TERMINATE,INS_FRONT,INS_REAR,RMV_FRONT,RMV_REAR,PRINT_CRNT,
	RMV_CRNT,SRCH_NO,SRCH_NAME,PRINT_ALL,NEXT,PREV,RETRIEVE,CLEAR
} Menu;

Menu SelectMenu(void)
{
	int i;
	int ch;
	char *mstring[]=
	{
		"머리에 노드를 삽입","꼬리에 노드를 삽입","머리 노드를 삭제",
		"꼬리 노드를 삭제","선택한 노드를 출력","선택한 노드를 삭제",
		"번호로 검색","이름으로 검색","모든 노드를 출력",
		"선택한 노드를 뒤쪽으로","선택한 노드를 앞쪽으로","n번째 위치의 노드",
		"모든 노드를 삭제",
	};
	
	do
	{
		for(i=TERMINATE;i<CLEAR;i++)
		{
			printf("(%d) %-22.22s ",i+1,mstring[i]);
			if((i%3)==2)
				putchar('\n');
		}
		printf("(0) 종료 : ");
		scanf("%d",&ch);
	} while(ch<TERMINATE || ch>CLEAR);
	
	return (Menu)ch;
}

int main()
{
	int n;
	Menu menu;
	Dlist list;
	Initialize(&list);
	do
	{
		Member x;
		switch(menu=SelectMenu())
		{
			case INS_FRONT:
				x=ScanMember("머리에 삽입",MEMBER_NO | MEMBER_NAME);
				InsertFront(&list,&x);
				break;
			case INS_REAR:
				x=ScanMember("꼬리에 삽입",MEMBER_NO | MEMBER_NAME);
				InsertRear(&list,&x);
				break;
			case RMV_FRONT:
				RemoveFront(&list);
				break;
			case RMV_REAR:
				RemoveRear(&list);
				break;
			case PRINT_CRNT:
				PrintLnCurrent(&list);
				break;
			case RMV_CRNT:
				RemoveCurrent(&list);
				break;
			case SRCH_NO:
				x=ScanMember("검색",MEMBER_NO);
				if(Search(&list,&x,MemberNoCmp)!=NULL)
					PrintLnCurrent(&list);
				else
					puts("그 번호의 데이터가 없습니다.");
				break;
			case SRCH_NAME:
				x=ScanMember("검색",MEMBER_NAME);
				if(Search(&list,&x,MemberNameCmp)!=NULL)
					PrintLnCurrent(&list);
				else
					puts("그 이름의 데이터가 없습니다.");
				break;
			case PRINT_ALL:
				Print(&list);
				break;
			case NEXT:
				Next(&list);
				break;
			case PREV:
				Prev(&list);
				break;
			case RETRIEVE:
				scanf("%d",&n);
				Retrieve(&list,n);
				break;
			case CLEAR:
				Clear(&list);
				break;
		}
	} while(menu!=TERMINATE);
	
	Terminate(&list);
	
	return 0;
}
