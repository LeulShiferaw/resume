/**
 * @file queue.c
 */

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

static void copy_to_node(Item item, Node *pn);
static void copy_to_item(Node *pn, Item *pi);

void initialize_queue(Queue *pq)
{
	pq->front = pq->rear = NULL;
	pq->items = 0;
}

int queue_is_full(const Queue *pq)
{
	return pq->items == MAXQUEUE;
}

int queue_is_empty(const Queue *pq)
{
	return pq->items == 0;
}

int queue_item_count(const Queue *pq)
{
	return pq->items;
}

int enqueue(Item item, Queue *pq)
{
	// add missing stuff
	if(queue_is_full(pq))
		return -1;
	Node *nele=(Node*)malloc(sizeof(Node));
	copy_to_node(item, nele);
	if(queue_is_empty(pq))
	{
		nele->next=NULL;
		pq->front=nele;
		pq->rear=nele;
		++pq->items;
		return 0;
	}
	nele->next=NULL;
	pq->rear->next=nele;
	pq->rear=nele;
	++pq->items;
        return 0;
}

int dequeue(Item *pitem, Queue *pq)
{
	// add missing stuff
	if(queue_is_empty(pq))
		return -1;	
	
	--pq->items;

	copy_to_item(pq->front, pitem);
	Node *temp=pq->front->next;
	free(pq->front);
	pq->front=temp;

	return 0;
}

void empty_queue(Queue *pq)
{
	Item dummy;
	while (!queue_is_empty(pq)) {
		dequeue(&dummy, pq);
	}
}

static void copy_to_node(Item item, Node *pn)
{
	pn->item = item;
}

static void copy_to_item(Node *pn, Item *pi)
{
	*pi = pn->item;
}
