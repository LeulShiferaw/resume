/*
	JTSK-320111
	a5_p11.c
	Leul Shiferaw
	l.shiferaw@jacobs-university.de
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_char(char *str, char c)
{
	int res = 0;

	for(; *str!='\0'; ++str)
		if(*str==c)
			++res;

	return res;
}

int main()
{
	int n;
	
	printf("n: ");
	scanf("%d", &n);
	getchar();

	char *str = (char*)malloc(sizeof(char)*n);
	
	printf("Enter string: ");
	fgets(str, n, stdin);
	str[strlen(str)-1] = '\0';

	char input[] = "BpiDz";

	int x, i, len = strlen(input);
	for(i = 0; i<len; ++i)
	{
		x = count_char(str, input[i]);
		printf("The character '%c' occurs %d ", input[i], x);
		if(x==1)
			printf("time\n");
		else printf("times\n");
	}

	free(str);
	return 0;
}