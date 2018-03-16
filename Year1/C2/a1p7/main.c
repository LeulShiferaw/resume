/*
 * JTSK-320112
 * a1_p7.c
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */

#include <stdio.h>

void print(char c)
{
	int i;
	for(i=7; i>=0; --i)
		printf("%d", (c&(1<<i))==(1<<i));
	printf("\n");

}
void set3bits(unsigned char *c, int i, int j, int k)
{
	*c|=(1<<i);
	*c|=(1<<j);
	*c|=(1<<k);//Or gate with a number whose required bits are on
}

int main()
{
	int i,j,k;
	unsigned char c;
	scanf("%c%d%d%d", &c, &i, &j, &k);
	
	printf("The decimal representation is: %d\n", (int)c);

	//Before change
	printf("The binary representation is: ");
	print(c);

	//Change
	set3bits(&c, i, j, k);

	//After change
	printf("After setting the bits: ");
	print(c);

	return 0;
}
