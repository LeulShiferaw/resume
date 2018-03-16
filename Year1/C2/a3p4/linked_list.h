#include <stdio.h>
#include <stdlib.h>

struct list
{
	int info;
	struct list *next;
};

void print_list(struct list*);
struct list* push_front(struct list*, int);
struct list* push_back(struct list*, int);
struct list* delfir(struct list*);
struct list* dispose_list(struct list*);

