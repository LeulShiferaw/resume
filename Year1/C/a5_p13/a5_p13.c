/*
	JTSK-320111
	a5_p13.c
	Leul Shiferaw
	l.shiferaw@jacobs-university.de
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void mixcase(char *str)
{
	for(; *str!='\0'; ++str)
	{
		if(isalpha(*str))
		{
			if(isupper(*str))
				*str = tolower(*str);
			else if(islower(*str))
				*str = toupper(*str);
		}
	}
}

int main()
{
	char str[80];

	printf("Enter string: ");
	fgets(str, sizeof(str), stdin);
	str[strlen(str)-1] = '\0';

	while(strcmp(str, "exit"))
	{
		printf("%s\n", str);
		mixcase(str);
		printf("%s\n", str);

		printf("Enter string: ");
		fgets(str, sizeof(str), stdin);
		str[strlen(str)-1] = '\0';
	}

	return 0;
}