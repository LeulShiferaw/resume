/*
 * JTSK-320112
 * a5_p1.c
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */

#include "stack.h"
#include <stdio.h>

int main()
{
	char c;

	int n;
	Stack s;
	init(&s);
	while(1)
	{
		scanf("%c", &c);
		getchar();

		switch(c)
		{
			case 's':
				scanf("%d", &n);
				getchar();
				printf("Pushing ");
				push(&s, n);
				printf("\n");
				break;
			case 'p':
				printf("Popping ");
				pop(&s);
				printf("\n");
				break;
			case 'e':
				printf("Emptying Stack ");
				print(&s);
				empty(&s);
				break;
			case 'q':
				printf("Quit\n");
				return 0;
		}	
	}
	return 0;
}
