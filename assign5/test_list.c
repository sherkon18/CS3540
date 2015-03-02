//Name: Dalibor Labudovivc
//Prof. J.Higgins
//Course: CS3540-01
//Assignment: Assign5

#include "list.h"
#include <stdio.h>

void display_in_reverse(const list* list);

void display (const list* list);

int main ()
{
// testing all function 
 printf("create list\n");
 list* list = create_list();

 printf("current list: ");
 display(list);

 printf("\n\nappend Red");
 append (list, "Red");

 printf("\n\ncurrent list: ");
 display(list);

 printf("\nprepend Yellow");
 prepend (list, "Yellow");

 printf("\ncurrent list: ");
 display(list);

 printf("\n\ninsert Green to 2nd position");
 insert (list, "Green", 1);

 printf("\ncurrent list: ");
 display(list);

 printf("\n\ninsert Purple into 4th position");
 insert (list, "Purple", 3);

 printf("\ncurrent list: ");
 display(list);

 printf("\n\nremove 4th color from list");
 remove_from_list(list, 3);

 printf("\ncurrent list: ");
 display(list);

 printf("\n\nappend Pink");
 append(list, "Pink");

 printf("\ncurrent list: ");
 display(list);

 printf("\n\nprepend White");
 prepend(list, "White");

 printf("\ncurrent list: ");
 display(list);

 printf("\n\ncurrent list in reverse: ");
 display_in_reverse(list);

 printf("\n\ndelete list");
 delete_list(list);

 printf("\ncurrent list: ");
 display(list);

 return 0;
}
//display functions
void display (const list* list)
{
    if(list != NULL && !is_list_empty(list))
    {
        node* node = list -> front;

        int i;
        for(i = 0; i < size(list); node = node -> next, i++)
        {
            printf("%s ", (char*)(node -> item));
        }
    }

}

void display_in_reverse(const list* list)
{
    if(list != NULL && !is_list_empty(list))
    {
        node* node = list -> rear;

        int i;
        for(i = size(list) - 1; i >= 0; node = node -> previous, i--)
        {
            printf("%s ", (char*)(node -> item));
        }
    }

}




