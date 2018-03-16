/*
 * JTSK-320112
 * a3_p2.c
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>

struct list
{
	int info;
	struct list *next;
};

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

//Insert value at index ind
struct list* insert(struct list* mylist, int ind, int value)
{
	if(ind<0)
	{
		printf("Invalid position!\n");
		return mylist;
	}

	int i=0;
	struct list*prev=NULL, *last=mylist;//Before the first element
	while(i!=ind)//Keep incrementing both prev and last
	{
		if(last==NULL)
		{
			printf("Invalid position!\n");
			return mylist;
		}
		prev=last;
		last=last->next;
		++i;	
	}
	
	struct list*newel=(struct list*)malloc(sizeof(struct list));
	if(!newel)
	{
		printf("Error allocating!\n");
		exit(1);
	}

	newel->info=value;
	newel->next=last;//Point to last
	if(prev==NULL)//If there is no element before then it must be the first element
		return newel;
	prev->next=newel;//Else sandwich b/n prev and last
	return mylist;
}

//Reverse list
struct list* rev(struct list* mylist, struct list* prev)
{
	//Base cases
	if(!mylist)
		return mylist;
	if(!mylist->next)//If it is the last element
	{
		mylist->next=prev;
		return mylist;//Return b/c it is the new head
	}
	//Reverse the rest of the elements
	struct list* temp=rev(mylist->next, mylist);
	mylist->next=prev;//Make the current one point to the prev
	return temp;
}
int main()
{
	struct list* mylist=NULL;

	char c;
	int n, m;
	while(1)
	{
		scanf("%c", &c);
		switch(c)
		{
			case 'a':
				scanf("%d", &n);
				mylist=push_back(mylist, n);
				break;
			case 'b':
				scanf("%d", &n);
				mylist=push_front(mylist, n);
				break;
			case 'r':
				mylist=delfir(mylist);	
				break;
			case 'p':
				print_list(mylist);
				break;
			case 'q':
				mylist=dispose_list(mylist);
				return 0;
				break;
			case 'i':
				scanf("%d%d", &n, &m);
				mylist=insert(mylist, n, m);
				break;			
			case 'R':
				mylist=rev(mylist, NULL);
				break;	
		}	
	}
	return 0;
}
