#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "ArrayLinkedList.h"

static Index GetIndex(List *list)
{
	if(list->deleted==Null)
		return ++(list->max);
	else
	{
		Index rec=list->deleted;
		list->deleted=list->n[rec].Dnext;
		return rec;
	}
}

static void DeleteIndex(List *list,Index idx)
{
	if(list->deleted==Null)
	{
		list->deleted=idx;
		list->n[idx].Dnext=Null;
	}
	else
	{
		Index ptr=list->deleted;
		list->deleted=idx;
		list->n[idx].Dnext=ptr;
	}
}

static void SetNode(Node *n,const Member *x,Index next)
{
	n->data=*x;
	n->next=next;
}

void Initialize(List *list,int size)
{
	list->n=calloc(size,sizeof(Node));
	list->head=Null;
	list->crnt=Null;
	list->max=Null;
	list->deleted=Null;
}

Index search(List *list,const Member *x,int compare(const Member *x,const Member *y))
{
	Index ptr=list->head;
	while(ptr!=Null)
	{
		if(compare(&list->n[ptr].data,x)==0)
		{
			list->crnt=ptr;
			return ptr;
		}
		ptr=list->n[ptr].next;
	}
	return Null;
}

void InsertFront(List *list,const Member *x)
{
	Index ptr=list->head;
	list->head=list->crnt=GetIndex(list);
	SetNode(&list->n[list->head],x,ptr);
}

void InsertRear(List *list,const Member *x)
{
	if(list->head==Null)
		InsertFront(list,x);
	else
	{
		Index ptr=list->head;
		while(list->n[ptr].next!=Null)
			ptr=list->n[ptr].next;
		list->n[ptr].next=list->crnt=GetIndex(list);
		SetNode(&list->n[list->n[ptr].next],x,Null);
	}
}

void RemoveFront(List *list)
{
	if(list->head!=Null)
	{
		Index ptr=list->n[list->head].next;
		DeleteIndex(list,list->head);
		list->head=list->crnt=ptr;
	}
}

void RemoveRear(List *list)
{
	if(list->head!=Null)
	{
		if(list->n[list->head].next==Null)
			RemoveFront(list);
		else
		{
			Index ptr=list->head;
			Index pre;
			while(list->n[ptr].next!=Null)
			{
				pre=ptr;
				ptr=list->n[ptr].next;
			}
			list->n[pre].next=Null;
			DeleteIndex(list,ptr);
			list->crnt=pre;
		}
	}
}

void RemoveCurrent(List *list)
{
	if(list->head!=Null)
	{
		if(list->crnt==list->head)
			RemoveFront(list);
		else
		{
			Index ptr=list->head;
			while(list->n[ptr].next!=list->crnt)
				ptr=list->n[ptr].next;
			list->n[ptr].next=list->n[list->crnt].next;
			DeleteIndex(list,list->crnt);
			list->crnt=ptr;
		}
	}
}

void Clear(List *list)
{
	while(list->head!=Null)
		RemoveFront(list);
	list->crnt=Null;
}

void PrintCurrent(const List *list)
{
	if(list->crnt==Null)
		printf("선택한 노드가 없습니다.");
	else
		PrintMember(&list->n[list->crnt].data);
}

void PrintLnCurrent(const List *list)
{
	PrintCurrent(list);
	putchar('\n');
}

void Print(const List *list)
{
	if(list->head==Null)
		puts("노드가 없습니다.");
	else
	{
		Index ptr=list->head;
		puts("[모두 보기]");
		while(ptr!=Null)
		{
			PrintLnMember(&list->n[ptr].data);
			ptr=list->n[ptr].next;
		}
	}
}

void Purge(List *list,int compare(const Member *x,const Member *y))
{
	Index ptr=list->head;
	Index next_ptr;
	
	while(ptr!=Null) // 머리노드부터 차례대로 중복되는 노드가 있는지 검사
	{
		next_ptr=list->n[ptr].next;
		
		while(next_ptr!=Null)
		{
			if(compare(&list->n[ptr].data,&list->n[next_ptr].data)==0)
			{
				list->crnt=next_ptr; // 중복되는 노드를 현재 커서에 위치
				RemoveCurrent(list);
			}
			next_ptr=list->n[next_ptr].next; // ptr과 동일하지 않다면 다음 노드로 이동
		}
		ptr=list->n[ptr].next; // ptr과 중복되는 노드를 모두 검사하였다면 다음 노드로 이동하여 검사
	}
	list->crnt=list->head;
}

void Terminate(List *list)
{
	Clear(list);
	free(list->n);
}
