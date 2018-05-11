//The purpose of this program is to create a list of equipments in a gym according to each equipment's type, description, and quantity.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "equipment.h"

/**********************************************************
 *  * main: Prompts the user to enter an operation code,     *
 *   *       then calls a function to perform the requested   *
 *    *       action. Repeats until the user enters the        *
 *     *       command 'q'. Prints an error message if the user *
 *      *       enters an illegal code.                          *
 *       **********************************************************/

int main(void)
{
  char code;

  struct equipment *e_list = NULL;  
  printf("Operation Code: a for appending to the list, u for updating an equipment"
	  ", p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': e_list = append_to_list(e_list);
                break;
      case 'u': update(e_list);
                break;
      case 'p': printList(e_list);
                break;
      case 'q': clearList(e_list);
		return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}
