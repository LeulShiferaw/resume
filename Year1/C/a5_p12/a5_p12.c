/*
	JTSK-320111
	a5_p12.c
	Leul Shiferaw
	l.shiferaw@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

void myreplace(char *str, char c, char e)
{
	for(; *str!='\0'; ++str)
		if(*str==c)
			*str = e;
}

int main()
{
	char c, e, str[70];

	printf("Enter string: ");
	fgets(str, sizeof(str), stdin);
	str[strlen(str)-1] = '\0';

	while(strcmp(str, "quit"))
	{
		printf("Enter c: ");
		scanf("%c", &c);
		getchar();

		printf("Enter e: ");
		scanf("%c", &e);
		getchar();

		printf("Pre replacement: %s\n", str);
		myreplace(str, c, e);
		printf("Post replacement: %s\n", str);

		printf("Enter string: ");
		fgets(str, sizeof(str), stdin);
		str[strlen(str)-1] = '\0';
	}	
	return 0;
}