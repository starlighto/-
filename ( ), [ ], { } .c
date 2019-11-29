//3가지 괄호 ( ), [ ], { } 모두를 고려한 매칭 문제를 구현하시오
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
		printf("\n3가지 괄호 ( ), [ ], { } 모두 매칭? YES \n");
	else
		printf("\n3가지 괄호 ( ), [ ], { } 모두 매칭? NO \n");
	return 0;
}
