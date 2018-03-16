/*
	JTSK-320111
	a6_p3.c
	Leul Shiferaw
	l.shiferaw@jacobs-univeristy.de
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_upper(char *str)
{
	int res = 0;

	for(; *str!='\0'; ++str)
		if(isalpha(*str) && isupper(*str))
			++res;

	return res;
}

int main()
{
	char str[101]; //If 100 characters 101th will be '\0'

	printf("Enter string: ");
	fgets(str, sizeof(str), stdin);
	str[strlen(str)] = '\0';

	while(strcmp(str, "\n"))
	{
		printf("Number of uppercases: %d\n", count_upper(str));

		printf("Enter string: ");
		fgets(str, sizeof(str), stdin);
		str[strlen(str)] = '\0';
	}

	return 0;
}