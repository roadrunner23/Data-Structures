#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int IsEmpty(Stack S)
{
	return S->Next == NULL;
}

Stack CreateStack()
{
	Stack S;

	S = malloc(sizeof(struct Node));

	if(S == NULL)
		printf("Out of space!");

	return S;
}

void DisposeStack(Stack S)
{
	if(S != NULL)
		free(S);
}

void MakeEmpty(Stack S)
{
	if(S == NULL)
		printf("Must use CreateStack first");
	else
	{
		while(!IsEmpty(S))
			Pop(S);
	}
}

void Push(PtrToCell CurrentCell, Stack S)
{
	PtrToNode TmpCell;

	TmpCell = malloc(sizeof(struct Node));
	if(TmpCell == NULL)
		printf("Out of space!");
	else
	{
		TmpCell->CellElement = CurrentCell;
		TmpCell->Next = S->Next;
		S->Next = TmpCell;
	}
}

PtrToCell Top(Stack S)
{
	if(!IsEmpty(S))
		return S->Next->CellElement;
	else
		printf("Empty Stack");

	return 0;
}

PtrToCell Pop(Stack S)
{
	PtrToNode FirstNode;
	PtrToCell FirstCell;

	if(IsEmpty(S))
		printf("Empty Stack");
	else
	{
		FirstNode = S->Next;
		FirstCell = FirstNode->CellElement;
		S->Next = S->Next->Next;
		free(FirstNode);
	}

	return FirstCell;
}
