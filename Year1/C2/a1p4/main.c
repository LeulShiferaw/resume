/*
 * JTSK-320112
 * a1_p4.c
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */
#include <stdio.h>

#define INTERMEDIATE

int main()
{
	int n, dot=0;
	scanf("%d", &n);

	int x[n], y[n];

	int i;
	for(i = 0; i<n; ++i)
		scanf("%d", (x+i));
	for(i = 0; i<n; ++i)
		scanf("%d", (y+i));

	#ifdef INTERMEDIATE
		printf("The intermediate product values are:\n");
		for(i = 0; i<n; ++i)
			printf("%d\n", x[i]*y[i]);
	#endif
	for(i = 0; i<n; ++i)
		dot+=x[i]*y[i];
	printf("The scalar product is: %d\n", dot);

	return 0;
}
