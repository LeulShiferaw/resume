/*
 * JTSK-320112
 * a6_p4.c
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list
{
	char username[20];
	int pos;
	
	struct list* next;
};

//Find the username and password in head
//If true return 1
//else return 0
int find(FILE* file, struct list* head, char un[], char pass[])
{
	if(head==NULL)
		return 0;

	char curr_pass[20];
	if(strcmp(head->username, un)==0)
	{
		fseek(file, head->pos, SEEK_SET);
		fscanf(file, "%s", curr_pass);
		if(strcmp(curr_pass, pass)==0)
			return 1;
	}
	return find(file, head->next, un, pass);
}

void destroy(struct list* head)
{
	if(head==NULL)
		return;
	destroy(head->next);
	free(head);
	head=NULL;
}

int main()
{
	FILE* file=fopen("users.txt", "r");

	if(file==NULL)
	{
		printf("Error opening file!\n");
		return 0;
	}

	struct list* mylist=NULL;
	struct list* head=NULL;

	char un[20], pass[20];
	//Read the usernames and the position of the corresponding password in mylist
	while(fscanf(file, "%s", un)!=EOF)
	{
		struct list* newele=(struct list*)malloc(sizeof(struct list));
		newele->pos=ftell(file);	
		strcpy(newele->username, un);
		newele->next=NULL;

		if(mylist==NULL)
		{
			mylist=newele;
			head=mylist;
		}
		else 
		{
			mylist->next=newele;
			mylist=mylist->next;
		}
	}

	while(1)
	{
		scanf("%s", un);//Read username

		if(strcmp(un, "exit")==0)
		{
			printf("Exiting...\n");
			return 0;
		}

		scanf("%s", pass);//Input password

		if(find(file, head, un, pass))
			printf("Access to user %s is granted.\n", un);
		else printf("Access to user %s is denied.\n", un);
	}

	destroy(head);
	head=NULL;
	mylist=NULL;

	fclose(file);
	return 0;
}
