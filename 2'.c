#include<stdio.h> 
#include<stdlib.h> 
#include "head'.h"
#include<stdbool.h> 

bool compare(char character1, char character2)
{
	if (character1 == '(' && character2 == ')')
		return 1;
	else if (character1 == '{' && character2 == '}')
		return 1;
	else if (character1 == '[' && character2 == ']')
		return 1;
	else
		return 0;
}
bool Matched(char ch[])
{
	int i = 0;

	struct node *stack = NULL;

	while (ch[i])
	{
		
		if (ch[i] == '{' || ch[i] == '(' || ch[i] == '[')
			pushstack(&stack, ch[i]);


		if (ch[i] == '}' || ch[i] == ')' || ch[i] == ']')
		{

			if (stack == NULL)
				return 0;

			else if (!compare(popstack(&stack), ch[i]))
				return 0;
		}
		i++;
	}

	if (stack == NULL)
		return 1; 
	else
		return 0;  
}
int main()
{
	char ch[100] = "{(})[]";
	if (Matched(ch))
		printf("\n3°¡Áö °ıÈ£ ( ), [ ], { } ¸ğµÎ ¸ÅÄª? YES \n");
	else
		printf("\n3°¡Áö °ıÈ£ ( ), [ ], { } ¸ğµÎ ¸ÅÄª? NO \n");
	return 0;
}
