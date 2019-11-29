#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define bool int 

struct node
{
	char data;
	struct node *next;
};
void pushstack(struct node** top_ref, int new_data);
int popstack(struct node** top_ref);

void pushstack(struct node** top_ref, int new_data)
{
	struct node* new_node =
		(struct node*) malloc(sizeof(struct node));

	if (new_node == NULL)
	{
		printf("Stack overflow n");
		getchar();
		exit(0);
	}

	new_node->data = new_data;
	new_node->next = (*top_ref);
	(*top_ref) = new_node;
}

int popstack(struct node** top_ref)
{
	char res;
	struct node *top;
	if (*top_ref == NULL)
	{
		printf("Stack overflow n");
		getchar();
		exit(0);
	}
	else
	{
		top = *top_ref;
		res = top->data;
		*top_ref = top->next;
		free(top);
		return res;
	}
}

