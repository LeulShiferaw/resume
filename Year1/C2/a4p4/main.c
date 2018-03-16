/*
 * JTSK-320112
 * a4_p4.c
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person
{
	char name[30];
	int age;
};

//Age first
int cmp_age(const struct person a, const struct person b)
{
	if(a.age > b.age)
		return 1;
	else if(a.age < b.age)
		return -1;
	if(strcmp(a.name, b.name)>0)
		return 1;
	return -1;
}

//Name first
int cmp_name(const struct person a, const struct person b)
{
	if(strcmp(a.name, b.name)>0)
		return 1;
	else if(strcmp(a.name, b.name)<0)
		return -1;
	if(a.age > b.age)
		return 1;
	return -1;
}

void swap(struct person *A, struct person *B)
{
	struct person temp;
	strcpy(temp.name, A->name);
	temp.age=A->age;
	strcpy(A->name, B->name);
	A->age=B->age;
	strcpy(B->name, temp.name);
	B->age=temp.age;
}

//Bubble sort
void sort(struct person A[], int n, int(*fun)(const struct person, const struct person))
{
	int i,swapped=1;
	while(swapped)
	{
		swapped=0;
		for(i=1; i<n; ++i)
		{
			if(fun(A[i-1], A[i])==1)
			{
				swap(A+i-1, A+i);
				swapped=1;
			}
		}		
	}
}

void print(struct person A[], int n)
{
	int i;
	for(i=0; i<n; ++i)
		printf("{%s, %d}; ", A[i].name, A[i].age);
	printf("\n");
}

int main()
{	
	int(*fun[2])(const struct person,const struct person)={cmp_age, cmp_name};

	int n;
	scanf("%d", &n);
	getchar();

	int i;	
	struct person A[n];
	for(i=0;i<n;++i)
	{
		fgets(A[i].name, sizeof(A[i].name), stdin);
		A[i].name[strlen(A[i].name)-1]='\0';
		scanf("%d", &A[i].age);
		getchar();	
	}	

	//With respect to name
	sort(A, n, fun[1]);
	print(A, n);
		
	//With respect to age
	sort(A, n, fun[0]);
	print(A, n);

	return 0;
}
