//ADT의 연결리스트 기반 구현내용에 BOTTOM 값(스택의 맨 아래 값)을 반환하는 void* stackBottom(STACK* stack) 함수를 정의하여 추가하시오.
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct node
{
	void* dataptr;
	struct node* link;
}STACK_NODE;
typedef struct
{
	int count;
	STACK_NODE* top;
}STACK;


STACK* creatstack(void) {
	STACK* stack;
	stack = (STACK*)malloc(sizeof(STACK));
	if (stack) {
		stack->count = 0;
		stack->top = NULL;
	}
	return stack;
}
bool pushstack(STACK* stack, void* datainptr)
{
	STACK_NODE* newptr;
	newptr = (STACK_NODE*)malloc(sizeof(STACK_NODE));
	if (!newptr)
		return false;
	newptr->link = stack->top;
	stack->top = newptr;
	(stack->count)++;
	return true;
}
void popstack(STACK* stack) {
	void* dataoutptr;
	STACK_NODE* temp;

	if (stack->count == 0)
		dataoutptr = NULL;
	else
	{
		temp = stack->top;
		dataoutptr = stack->top->dataptr;
		stack->top = stack->top->link;
		free(temp);
		(stack->count)--;
	}
	return dataoutptr;
}
void* stacktop(STACK* stack) {
	if (stack->count == 0)
		return NULL;
	else
		return stack->top->dataptr;
}
bool emptystack(STACK*stack)
{
	return (stack->count == 0);
}
bool fullstack(STACK* stack) {
	STACK_NODE* temp;
	if ((temp =
		(STACK_NODE*)malloc(sizeof(*(stack->top)))))
	{
		free(temp);
		return false;
	}
	return true;
}
int stackcount(STACK*stack) {
	return stack->count;
}
STACK* destroystack(STACK*stack) {
	STACK_NODE* temp;
	if (stack) {

		while (stack->top != NULL) {
			free(stack->top->dataptr);
			temp = stack->top;
			stack->top = stack->top->link;
			free(temp);
		}
		free(stack);
	}
	return NULL;

}

void* stackbottom(STACK* stack) {
	STACK_NODE* temp;
	if (emptystack)
		return 0;
	else {
		while (stack->count >= 2) {
			free(stack->top->dataptr);
			temp = stack->top;
			stack->top = stack->top->link;
			free(temp);
			stack->count--;
		}
	}return stack->top->dataptr;
}
