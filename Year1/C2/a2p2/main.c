/*
 * JTSK-320112
 * a2_p2.c
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char s1[100];
	char s2[100];

	fgets(s1, 100, stdin);
	s1[strlen(s1)-1] = '\0';
	fgets(s2, 100, stdin);
	s2[strlen(s2)-1] = '\0';

	int l1=0, l2=0;//Length one and two

	//Calc length 1
	char *ptr = s1;
	while(*ptr!='\0')
	{
		++l1;
		ptr+=1;
	}
	ptr = s2;
	//Calc length 2
	while(*ptr!='\0')
	{
		++l2;
		ptr+=1;
	}
	
	char *s3 = (char*)malloc(sizeof(char)*(l1+l2+1));//Plus one of the \0
	if(s3==NULL)
	{
		printf("Error allcoating!!\n");
		return 0;
	}

	//Concat the two strings
	strcat(s3, s1);
	strcat(s3, s2);

	printf("Result of concatenation: %s\n", s3);//Print results

	//Free mem
	free(s3);
	return 0;
}
