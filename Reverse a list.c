#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stacksadt.h"


void clear_stdin();

int main(void)
{
	bool done = false;
	int* dataPtr;
	STACK* stack;

	stack = createstack();

	while (!done)
	{
		dataPtr = (int*)malloc(sizeof(int));
		printf("Enter a number: <EOF> to stop: ");
		if ((scanf_s("%d", dataPtr)) == NULL
			|| fullstack(stack)) {
			clear_stdin();
			done = true;
		}
			else
		{
			pushstack(stack, dataPtr);

		}

	}

	printf("\n\nThe list of numbers reversed:\n");
	while (!emptystack(stack))
	{
		dataPtr = (int*)popstack(stack);
		printf("%3d\n", *dataPtr);
		free(dataPtr);
	}
	destroystack(stack);
}

void clear_stdin()
{
	int ch;

	while ((ch = getchar()) != EOF && ch != '\n') {};
}
