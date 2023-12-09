#include "cstack.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int hstack_t;
#define I 10
struct list 
{
	void* data;
	struct list* last;
};

struct stack 
{
	hstack_t hstack;
	unsigned int count;
	unsigned int size;
	struct list second;
	struct stack* next;
} primary[I];

void init (void)
{
	register int i;
	for (i=1;i<I;i++)
	{
		primary[i].hstack=-1;
		primary[i].count=0;
		primary[i].next=NULL;
	}
}

void slstore (struct stack* i, struct stack* start)
{
	struct stack *old, *p;
	old=start;
	while(start)
	{
		old=start;
		start=start->next;
	}
	old->next=i;
	i->next=NULL;
}

hstack_t stack_new(void)
{
	
	struct stack* p;
	p=(struct stack*) malloc(sizeof(struct stack));
	if (!p) p=realloc(p,(10*sizeof(struct stack)));
	if (!p) printf("error member \n");
	
	static hstack_t i=0;
	i++;
	primary[i].hstack=i;
	primary[i].next=p;
	//slstore (p, &primary[hstack].next);
	return i;
}
void stack_free(const hstack_t hstack)
{
    /*primary[hstack].hstack=-1;
	primary[hstack].size=0;
	primary[hstack].next=NULL;*/
	free (&primary[hstack]);
}

int stack_valid_handler(const hstack_t hstack)
{
   if (primary[hstack].hstack==hstack)
    return 0;
return 1;
}

unsigned int stack_size(const hstack_t hstack)
{
    return primary[hstack].count;
}

void stack_push(const hstack_t hstack, const void* data_in, const unsigned int size)
{
	if(stack_valid_handler(hstack)==0)
	{
	struct stack* p;
	if (data_in!=NULL)
	{
    primary[hstack].second.last = memcpy(primary[hstack].second.data, data_in, size);
	primary[hstack].size += size;
	primary[hstack].count++;
	}
	slstore (p, (struct stack*)primary[hstack].second.last);
	}
}

unsigned int stack_pop(const hstack_t hstack, void* data_out, const unsigned int size)
{	if(stack_valid_handler(hstack)==0)
	{
    if (primary[hstack].count == -1) {
        printf("Stack is empty\n");
        return 0;
    }
    memcpy(data_out, primary[hstack].second.data, size);
	primary[hstack].size -= size;
	primary[hstack].count--;
	
	}
}
