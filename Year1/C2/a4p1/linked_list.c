#include "linked_list.h"

void print_list(struct list* mylist)
{
	struct list *p;
	for(p=mylist; p; p=p->next)
		printf("%d ", p->info);
	printf("\n");
}

struct list* push_front(struct list* mylist, int value)
{
	struct list* newel;
	newel=(struct list*)malloc(sizeof(struct list));
	if(!newel)
	{
		printf("Error allocating!\n");
		exit(1);
	}
	newel->info=value;
	newel->next=mylist;
	return newel;
}

struct list* push_back(struct list* mylist, int value)
{
	struct list* newel;
	newel=(struct list*)malloc(sizeof(struct list));
	if(!newel)
	{
		printf("Error allocating!\n");
		exit(1);
	}
	newel->info=value;
	newel->next=NULL;
	if(!mylist)
		return newel;
	struct list* cursor=mylist;
	while(cursor->next)
		cursor=cursor->next;
	cursor->next=newel;
	return mylist;
}

//Delete the first element of mylist and return the head of the new list
struct list* delfir(struct list* mylist)
{
	struct list* temp;
	if(mylist)
	{
		temp=mylist->next;
		free(mylist);
		mylist=temp;
	}
	return mylist;
}

struct list* dispose_list(struct list* mylist)
{
	struct list* temp;
	while(mylist)
	{
		temp=mylist->next;
		free(mylist);
		mylist=temp;	
	}
	return NULL;
}

