/*
 * JTSK-320112
 * a6_p1.c
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */

#include <stdio.h>

int main()
{
	FILE *fp=fopen("words.txt", "r");

	if(fp==NULL)
	{
		printf("Error opening file!\n");
		return 0;
	}

	int count=0;
	char ch;
	int prev=0;
	while(1)
	{
		ch=getc(fp);
		if(ch==EOF)
			break;
		switch(ch)
		{
			case ' ':case ',': case '?': case '!': case '.': case '\t': case '\r': case '\n':
				if(prev==1)
				{
					++count;
					prev=0;	
				}
				break;
			default: prev=1;
				 break;
		}	
	}

	printf("The file contains %d words.\n", count);
	return 0;
}
