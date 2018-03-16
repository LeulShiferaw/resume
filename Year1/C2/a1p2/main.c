/*
 * JTSK-320112
 * a1_p2.c
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */
#include <stdio.h>

#define LSB(A) ((A)&1 ? 1:0)//And gate the number with 1 if it is true(1) then the last one must have been one else it will be 0

int main()
{
	unsigned char c;
	scanf("%c", &c);

	printf("The decimal representation is: %d\n", (int)c);
	printf("The least significant bit is: %d\n", LSB(c));
	return 0;
}
