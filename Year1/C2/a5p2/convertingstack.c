/*
 * JTSK-320112
 * a5_p2.c
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */

#include "stack.h"
#include <stdio.h>

int main()
{
	int n;
	Stack s;
	init(&s);
	while(scanf("%d", &n)!=EOF)
	{
		binary(&s, n);
		printf("The binary representation of %d is ", n);
		print(&s);
		empty(&s);
	}
	return 0;
}
