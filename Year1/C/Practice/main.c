#include <stdio.h>
#include <stdlib.h>

void itobs(unsigned int no, char *str)
{
	unsigned int maxsize = sizeof(unsigned int)*8 + 1;

	int i;
	for(i=0; i<maxsize-1; ++i)
	{
		if(no & (1<<i))
			str[maxsize-2-i] = '1';
		else str[maxsize-2-i] = '0';
	}

	str[maxsize-1] = '\0';
}

int main()
{
	char *str = (char*) malloc(sizeof(char)*(sizeof(unsigned int)*8+1));

	unsigned int x;
	scanf("%d", &x);

	itobs(x, str);
	printf("%s\n", str);
	free(str);
	return 0;
}
