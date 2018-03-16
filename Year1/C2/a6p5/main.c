/*
 * JTSK-320112
 * a6_p5.c
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	char ch;
	scanf("%d%c", &n, &ch);
	printf("Concating the content of %d files...\n", n);

	int i;
	FILE* file_read;
	FILE* file_write=fopen("output.txt", "wb");
	if(file_write==NULL)
	{
		printf("Error opening file!\n");
		return 0;
	}

	size_t bytes;
	char input[64];
	char file_name[20];
	printf("The result is:\n");
	for(i=0; i<n; ++i)
	{
		scanf("%s", file_name);
		file_read=fopen(file_name, "rb");
		if(file_read==NULL)
		{
			printf("Error opening file\n");
			return 0;
		}	

		bytes=fread(input, 1, 64, file_read);//Incase it is not a multiple of 64

		printf("%s", input);
		fwrite(input, 1, bytes, file_write);
	}

	printf("The result was written into output.txt\n");
	return 0;
}
