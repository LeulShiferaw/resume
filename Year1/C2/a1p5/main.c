/*
 * JTSK-320112
 * a1_p5.c
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */

#include <stdio.h>

int main()
{
	unsigned char c;

	scanf("%c", &c);

	printf("The decimal representation is: %d\n", (int)c);

	int i, v;//v-value

	//Find limit to leave out trailing zeros
	int limit=-1;
	for(i=7; i>=0; --i)
		if((c&(1<<i))==(1<<i)) 
		{
			limit=i;
			break;
		}

	printf("The backwards binary representation is: ");
	for(i = 0; i<=limit; ++i)
	{
		v=(c&(1<<i))==(1<<i);//State of the ith bit
		printf("%d", v);
	}

	printf("\n");
	return 0;
}
