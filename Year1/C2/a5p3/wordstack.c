/*
 * JTSK-320112
 * a5_p3.c
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */

#include "stack.h"
#include <stdio.h>
#include <string.h>

int main()
{
	char c;
	char str[30];
	Stack s,q;
	init(&s);
	init(&q);
	int i,n,pal;
	while(1)
	{
			
		c=' ';
		while(1)
		{
			scanf("%s", str);
			if(strcmp(str, "exit")==0)
				return 0;
			scanf("%c", &c);
			push(&s, str);
			if(c=='\n') break;	
		}
		//Till half
		n=s.count/2;
		pal=1;//is palindrome
		for(i=0;i<n;++i)
		{
			if(strcmp(s.array[i],pop(&s))!=0)//Pop gets the last element, and i start from the top
			{
				printf("The sentence is not palindromic by words!\n");
				pal=0;//Is not palindrome
				break;
			}
		}
		if(pal)
			printf("The sentence is palindromic by words!\n");
		empty(&s);
	}
	return 0;
}
