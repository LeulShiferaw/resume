#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void init(Stack* s)
{
	s->count=0;
}

void push(Stack* s, int v)
{
	if(s->count<12)
	{
		s->array[s->count]=v;
		++s->count;
		printf("%d", v);
		return;
	}		
	else 
	{
		printf("Stack Overflow");
		return;
	}

}

void pop(Stack* s)
{
	if(s->count>0)
	{
		printf("%d", s->array[s->count-1]);
		--s->count;
		return;
	}
	else
	{
		printf("Stack Underflow");
		return;
	}
}

void empty(Stack* s)
{
	s->count=0;
}

int isEmpty(Stack* s)
{
	return s->count==0;
}	

void print(Stack* s)
{
	int i;
	for(i=s->count-1; i>=0; --i)
		printf("%d ", s->array[i]);
	printf("\n");	
}
