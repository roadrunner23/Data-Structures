#ifndef _List_H
#define _List_H

typedef int ElementType;

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
void Delete(ElementType X, List L);
ElementType Pop(List L);
Position FindPrevious(ElementType X, List L);
void Insert(ElementType X, ElementType Y, List L, Position P);
void DeleteList(List L);
void PrintList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType RetrieveElement(Position P);
ElementType RetrieveIntimacy(Position P);

struct Node
{
	ElementType Element;
	ElementType Intimacy;
	Position    Next;
};

#endif
#pragma once
