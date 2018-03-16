#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init(Stack* s)
{
	s->count=0;
}

void push(Stack* s, char v[])
{
	if(s->count<100)
	{
		strcpy(s->array[s->count], v);
		++s->count;
		return;
	}		
	else 
	{
		printf("Stack Overflow");
		return;
	}

}

char* pop(Stack* s)
{
	if(s->count>0)
	{
		--s->count;
		return s->array[s->count];
	}
	else
	{
		printf("Stack Underflow");
		return NULL;
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
		printf("%s ", s->array[i]);
	printf("\n");
}
