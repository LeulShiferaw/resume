/*
 * JTSK-320112
 * a3_p3.c
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */
#include <stdio.h>
#include <stdlib.h>

struct dlist
{
	char value;
	struct dlist *prev, *next;
};

struct dlist* push_front(struct dlist *mylist, char val)
{
	struct dlist *newel=(struct dlist*)malloc(sizeof(struct dlist));
	if(!newel)
	{
		printf("Error allocating!\n");
		exit(1);
	}

	newel->value=val;
	newel->prev=NULL;
	newel->next=mylist;
	if(mylist)
		mylist->prev=newel;
	return newel;
}

struct dlist* rem(struct dlist *mylist, char val)
{
	//Remove first instances
	struct dlist *temp;
	int norem=0;//Indicate that something was removed
	while(1)
	{
		if(!mylist)
		{
			if(!norem)
				printf("The element is not in the list!\n");
			return mylist;
		}
		if(mylist->value==val)
		{
			norem=1;
			temp=mylist->next;
			free(mylist);
			mylist=temp;	
			mylist->prev=NULL;
		}else break;
	}

	//Remove the rest
	struct dlist *p=mylist;
	while(1)
	{
		if(!p)
		{
			if(!norem)
				printf("The element is not in the list!\n");
			return mylist;
		}
		if(p->value==val)
		{
			norem=1;
			p->prev->next=p->next;//p->prev will never be prev b/c first instances have been removed
			if(p->next)
				p->next->prev=p->prev;
			free(p);
		}
		p=p->next;
	}
}

void print(struct dlist *mylist)
{
	while(mylist!=NULL)
	{
		printf("%c ", mylist->value);
		mylist=mylist->next;
	}
	printf("\n");
}

void print_back(struct dlist *mylist)
{
	if(!mylist)
		return;
	print_back(mylist->next);//Print everything then the current value
	printf("%c ", mylist->value);
}

void dispose_list(struct dlist *mylist)
{
	struct dlist*n=NULL;
	while(!mylist)
	{
		n=mylist->next;
		free(mylist);
		mylist=n;
	}
}

int main()
{		
	int n=0;
	char c='a';
	struct dlist *mylist=NULL;
	while(1)
	{
		scanf("%d", &n);
		getchar();
		switch(n)
		{
			case 1:
				scanf("%c", &c);
				getchar();
				mylist=push_front(mylist, c);
				break;
			case 2:
				scanf("%c", &c);
				getchar();
				mylist=rem(mylist, c);	
				break;
			case 3:
				print(mylist);
				break;
			case 4:
				print_back(mylist);
				printf("\n");
				break;
			case 5:
				dispose_list(mylist);
				return 0;
		}
	}
	return 0;
}
