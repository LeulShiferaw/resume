#JTSK-320112
#a4_p1.c
#Leul Shiferaw
#l.shiferaw@jacobs-university.de

CC=gcc
OBJ=linked_list.o use_linked_list.o
OPTIONS=-Wall

all: use_linked_list 

use_linked_list: $(OBJ)
	$(CC) $(OPTIONS) $(OBJ) -o use_linked_list
linked_list.o: linked_list.h linked_list.c

use_linked_list.o: use_linked_list.c

clean: 
	rm -f use_linked_list *.o
