/*
 * JTSK-320112
 * a4_p2.c
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int size = 100;

//Print upper case
void print_uc(char str[])
{
	int i;
	int n=strlen(str);

	for(i=0; i<n; ++i)
		if(str[i]>='a'&&str[i]<='z')
			printf("%c", 'A'+str[i]-'a');
		else printf("%c", str[i]);
	printf("\n");
}

//Print lower case
void print_lc(char str[])
{
	int i;
	int n=strlen(str);

	for(i=0; i<n; ++i)
		if(str[i]>='A'&&str[i]<='Z')
			printf("%c", 'a'+str[i]-'A');
		else printf("%c", str[i]);
	printf("\n");
}

//Print in reverse
void print_rev(char str[])
{
	int i, n=strlen(str);

	for(i=0; i<n; ++i)
		if(str[i]>='A'&&str[i]<='Z')
			printf("%c", 'a'+str[i]-'A');
		else if(str[i]>='a'&&str[i]<='z')
			printf("%c", 'A'+str[i]-'a');
		else printf("%c", str[i]);
	printf("\n");
}

int main()
{
	char str[size];
	fgets(str, sizeof(str), stdin);
	str[strlen(str)-1]='\0';

	void (*fun[3])(char [])={print_uc, print_lc, print_rev};
	
	int n;
	while(1)
	{
		scanf("%d", &n);
		getchar();
		if(n==4)
			return 0;
		fun[n-1](str);
	}	
	return 0;
}
