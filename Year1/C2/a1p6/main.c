/*
 * JTSK-320112
 * a1_p6.c
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */

#include <stdio.h>

int main()
{
	unsigned char c;
	scanf("%c", &c);

	printf("The decimal representation is: %d\n", (int)c);

	int i;
	printf("The binary representation is: ");
	for(i=7; i>=0; --i)
		printf("%d", (c&(1<<i))==(1<<i));//Status of the ith bit
	printf("\n");

	return 0;
}
