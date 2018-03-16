/*
	JTSK-320111
	a5_p5.c
	Leul Shiferaw
	l.shiferaw@jacobs-university.de
*/

#include <stdio.h>
#include <string.h>

#define false 0
#define true 1

int is_consonant(char *p)
{
	if((*p>='a'&&*p<='z') || (*p>='A'&&*p<='Z'))
	{
		switch(*p)
		{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U': 
				return false;
			default: 
				return true;
		}
	}
	return false;
}

int count_consonants(char str[])
{	
	int res = 0;
	char *p;
	for(p = str; *p != '\0'; ++p)
		if(is_consonant(p))
			++res;
	return res;
}

int main()
{
	char str[100];
	
	//Enter string
	printf("Enter string: ");
	fgets(str, sizeof(str), stdin);
	str[strlen(str)-1] = '\0';

	while(strlen(str)!=0)
	{
		printf("%d\n", count_consonants(str));
		
		printf("Enter string: ");
		fgets(str, sizeof(str), stdin);
		str[strlen(str)-1] = '\0';
	}

	return 0;
}
