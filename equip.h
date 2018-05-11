//This is a header file that contains the struct equipment declaration and prototypes for the functions needed to create the list.
#include "readline.h"

#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#define NAME_LEN 30
struct equipment{
	char type[NAME_LEN+1];
	char description[NAME_LEN+1];
	int quantity;
	struct equipment *next;
};
struct equipment *append_to_list(struct equipment *list);
void update(struct equipment *list);
void printList(struct equipment *list);
void clearList(struct equipment *list);

#endif
