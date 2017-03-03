#include "libs.h"

static void DestroyItem(ListNode * node)
{
	free(node);
}

List * Initialize()
{ 
	List * L = malloc(sizeof(List));
	L->size = 0;
	L->head = malloc(sizeof(ListNode));
	return L;
}

void Insert(int position, Item * item, List * L)
{
	ListNode * toAdd = malloc(sizeof(ListNode));
	ListNode * node;
	toAdd->item = item;
	if (position == 0)
	{
		toAdd->next = L->head;
		L->head = toAdd;
	} else
	{
		node = L->head;
		//Go to the element before the one to be inserted
		for (int i = 1; i < position; i++)
		{
			node = node->next;
		}
		if (node->next == NULL)
		{
			node->next = malloc(sizeof(ListNode));
		}
		toAdd->next = node->next;
		node->next = toAdd;
	}
	L->size++;
}

void Remove(int position, List * L)
{
	ListNode * node, * toRemove;
	node = L->head;
	if (position == 0)
	{
		toRemove = L->head;
		L->head = L->head->next;
	} else
	{
		for (int i = 1; i < position; i++) {
			node = node->next;
		}
		toRemove = node->next;
		node->next = node->next->next;
	}
	DestroyItem(toRemove);
	L->size--;
}

Item * Peek(int position, List * L)
{
	ListNode * node;
	Item * toShow;
	node = L->head;
	for (int i = 1; i < position+1; i++)
	{
		node = node->next;
	}
	toShow = node->item;
	return toShow;
}

int Empty(List * L)
{
	return Size(L) == 0;
}

int Size(List * L)
{
	return L->size;
}

void Destroy(List * L)
{
	free(L);
}
