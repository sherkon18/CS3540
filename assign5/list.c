//Name: Dalibor Labudovivc
//Prof. J.Higgins
//Course: CS3540-01
//Assignment: Assign5

#include "list.h"
#include <assert.h>
#include <stdlib.h>


node* create_node(void* item)
{
	node* n = malloc(sizeof(node));
	n -> item = item;
	n -> next = NULL;
	n -> previous = NULL;

	return n;
}

list* create_list()
{
	list* list = malloc(sizeof(list));
	list -> front = NULL;
	list -> rear = NULL;
	list -> size = 0;

	return list;
}
//determine if the list is empty
int is_list_empty(const list* list)
{
	//determine if the list is empty
	assert (list != NULL);
	//return size of zero
	return list -> size == 0;
}
//determine list size
int size(const list* list)
{
	assert (list != NULL);
	return list -> size;
}

void prepend(list* list, void* item)
{
	assert(list != NULL);
	//create a node
	node* node = create_node(item);
	//if the list is empty this node is first in the list 
	if(is_list_empty(list))
	{
	    list -> front = node;
		list -> rear = node;
		node -> next = node -> previous = node;
		
	}
	//else place the node at the beginning
	else
	{
		list -> front -> previous = node;
		node -> next = list -> front;
		node -> previous = list -> rear;
		list -> rear -> next = list -> front = node;
	}
	list -> size++;

}
//place node at the back of the list
void append(list* list, void* item)
{
	assert (list != NULL);

	node* node = create_node(item);

	if(is_list_empty(list))
	{
		list -> front = node;
		list -> rear = node;
		node -> previous = node;
		node -> next = node;
	}
	else
	{
		node -> previous = list -> rear;
		node -> next = list -> front;

		list -> rear -> next = node;
		list -> rear = node;
		list -> front -> previous = node;
	}

	list -> size++;
}
// place node at a specific position
int insert(list* list, void* item, int index)
{
	assert (list != NULL);

	int result = 0 <= index && index <= size(list);

	if(result)
	{
		if(index == 0)
			prepend(list, item);
		else if(index == size(list))
			append(list, item);
		else
		{
			node* temp = list -> front;
			node* node = create_node(item);
		
			int i;
			for(i = 0; i < index - 1; i++)
				temp = temp -> next;

			node -> next = temp -> next;
			temp -> next -> previous = node;
			node -> previous = temp;
			temp -> next = node;

			list -> size++;
		}
	}

	return result;
}
//deletes the list
void delete_list(list* list)
{
	assert (list != NULL);

	node* temp;
	node* node = list -> front;

	int i;
	for(i = 0; i < size(list); i++)
	{
		temp = node;
		node = node -> next;
		free(temp);
	}
	//free up memory
	free(list);

}

void* get(const list* list, int index)
{
 assert (list != NULL);
 void* result = NULL;
 if (index >= 0 && index < size(list))
 {
   node* temp = list -> front;
   int i;
   for (i = 0; i < index; i++)
     temp = temp -> next;
	 result = temp -> item;
 }
 return result;
}

int set(list* list, void* item, int index)
{
  assert (list != NULL);
  int result = index >= 0 && index < size(list);
  if (result)
  {
    node* temp = list -> front;
    int i;
    for (i = 0; i < index; i++)
      temp = temp -> next;
	  temp -> item = item;
  }
  return result;
}

// removes from the list at a specific location
int remove_from_list(list* list, int index)
{
	assert(list != NULL);
	node* temp = list -> front;
	int result = index >= 0 && index < size(list);

    if (result)
    {
		node* node;

    if (index == 0)
    {
		node = list -> front;
		list -> front = node -> next;
		list -> front -> previous = list -> rear;
		list -> rear -> next = list -> front;

      if (list -> front == NULL)
		list -> rear = NULL;
		
    }

	if(index == size(list) - 1)
	{
		node = list -> rear;
		list -> rear = node -> previous;
		list -> rear -> next = list -> front;
		list -> front -> previous = list -> rear;
	}

    else
    {
        int i;
		for (i = 0; i < index - 1; i++)
			temp = temp -> next;

        node = temp -> next;
        temp -> next = node -> next;
		node -> next -> previous = temp;

        if (temp -> next == NULL)
			list -> rear = temp;
			
    }
	//free up momemory
    free (node);
    list -> size--;
  }
  return result;

}

