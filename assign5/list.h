//Name: Dalibor Labudovivc
//Prof. J.Higgins
//Course: CS3540-01
//Assignment: Assign5

#ifndef _LIST_H_
#define _LIST_H_

typedef struct list_node
{
	void* item;
	struct list_node* next;
	struct list_node* previous;
} node;

typedef struct
{
	node* front;
	node* rear;
	int size;
} list;


list* create_list();

int is_list_empty(const list* list);

int size(const list* list);

void prepend(list* list, void* item);

void append(list* list, void* item);

int insert(list* list, void* item, int index);

int remove_from_list(list* list, int index);

void delete_list(list* list);

void* get(const list* list, int index);

int set(list* list, void* item, int location);

void delete_list(list* list);


#endif 

