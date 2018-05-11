//This program contains the functions needed to create the equipment list. 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "equipment.h"
#include "readline.h"

//Create a function that stores the equipment to the end of the list
struct equipment *append_to_list(struct equipment *list){
//Declare input variables, arrays, and pointers
	struct equipment *new_equip;
	int n;
	char str1[NAME_LEN], str2[NAME_LEN];

	//Allocate space for the new equipment
	new_equip = malloc(sizeof(struct equipment));
        if(new_equip == NULL)
        {
        	printf("Malloc failed");
                return list;
        }

	//Ask the user to enter the data and store it
	printf("Enter equipment type: ");
	read_line(str1, NAME_LEN);
	
	printf("Enter description: ");
	read_line(str2, NAME_LEN);

	strcpy(new_equip->type, str1);
        strcpy(new_equip->description, str2);
	
	//Check whether the equipment already exists
	struct equipment *temp = list;
	while(temp != NULL)
        {
                if(strcmp(temp->description, new_equip->description)==0 && strcmp(temp->type, new_equip->type)==0)
                {
                        printf("\nEquipment already exists\n");
                        return list;
                }
                if(temp->next == NULL)
                        break;
                temp = temp->next;
        }

	//Ask the user for quantity value	
	printf("Enter quantity: ");
        scanf("%d", &n);
        new_equip->quantity = n;
        
	//Check whether the list is empty and stores the information on the list
	if(list == NULL)
	{
		list = new_equip;
		new_equip->next = NULL;
		return list;
	}

	temp->next = new_equip;
	new_equip->next = NULL;
	return list;
}

//Create a function that updates the quantity of an equipment
void update(struct equipment *list)
{

	//Declare input variables, arrays, and pointers
	struct equipment *new_equip, *temp;
	int n;
	char str1[NAME_LEN], str2[NAME_LEN];

        new_equip = malloc(sizeof(struct equipment));
	
	//Ask the user to enter the data and store it
	printf("Enter equipment type: ");
        read_line(str1, NAME_LEN);

        printf("Enter description: ");
        read_line(str2, NAME_LEN);
	
	printf("Enter quantity: ");
        scanf("%d", &n);

	strcpy(new_equip->type, str1);
        strcpy(new_equip->description, str2);

	//Look for the equipment and update it
	for(temp = list; temp != NULL; temp = temp->next)		
	{
		if(strcmp(temp->description, new_equip->description)==0 && strcmp(temp->type, new_equip->type)==0)
                {		
			temp->quantity = temp->quantity + n;
			printf("%s %s updated, quantity: %d\n", temp->type, temp->description, temp->quantity);
			free(new_equip);
			return;
		}
	}
	printf("Equipment not found\n");
	free(new_equip);
}

//Create a function that prints the list
void printList(struct equipment *list){
  struct equipment *p;

	//Set up for loop to print each equipment in the list
	printf("Equipment   Description    Quantity\n");
	for(p = list; p != NULL; p = p->next)
		printf("%s   %s   %d\n", p->type, p->description, p->quantity);
  
}

//Create a function that deallocates the memory used
void clearList(struct equipment *list)
{
	struct equipment *p;

	//Set up while loop to deallocate memory
	while(list != NULL)
	{
		p = list;
		list = list->next;
		if(p != NULL)
			free(p);
	} 

}
