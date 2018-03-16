/* 
 * JTSK-320112
 * a3_p4.c
 * Leul Shiferaw
 * l.shiferaw@jacobs-university.de
 */
#include "linked_list.h"

int main()
{
	struct list* mylist=NULL;

	char c;
	int n;
	while(1)
	{
		scanf("%c", &c);
		switch(c)
		{
			case 'a':
				scanf("%d", &n);
				mylist=push_back(mylist, n);
				break;
			case 'b':
				scanf("%d", &n);
				mylist=push_front(mylist, n);
				break;
			case 'r':
				mylist=delfir(mylist);	
				break;
			case 'p':
				print_list(mylist);
				break;
			case 'q':
				mylist=dispose_list(mylist);
				return 0;
				break;
		}	
	}
	return 0;
}
