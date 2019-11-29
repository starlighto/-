#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Data char
typedef struct Node {
	Data data;
	struct Node *L_link;
	struct Node *R_link;
}Node;
Node* finalNode(Node *s);
Node* createNode(Node *s, Data e);
void push(Node *s, Data e);
void pop(Node *s);
void search(Node *s, Data e);
void count(Node *s);
void show(Node *s);
void reverse(Node *s);
void Print(Node *s);
void printNode(Node *s);
void isListEmpty(Node *s);

void main() {
	char input1, input2;

	Node *s;
	s = (Node*)malloc(sizeof(Node));
	s->data = '.';
	s->L_link = NULL;
	s->R_link = NULL;
	printf("고객 번호[어린이:1 청소년:2 20대 이상:3]\n");
	printf(" + :Push \n P :POP \n A :Show all data \n R :Reverse stack \n S :탐색\n C :Count customer\n Q: Quit\n");

	while (1) {
		printf("\n입력: ");
		scanf_s("%c",&input1);
		switch (input1) {
		case '+':
			scanf_s("%c",&input2);
			push(s, input2);
			break;

		case 'P':
			pop(s);
			break;

		case 'S':
			scanf_s("%c",&input2);
			search(s, input2);
			break;

		case 'C':
			count(s);
			break;

		case 'A':
			show(s);
			break;

		case 'R':
			reverse(s);
			break;

		case 'Q':
			printf("\n");
			exit(1);
			break;
		default: break;
		}
		while (input1 != EOF && input1 != '\n') {
			scanf_s("%c",&input1);
		}
	}

}
Node* finalNode(Node *s) {
	while (s->R_link != NULL) {
		s = s->R_link;
	}
	return s;
}

Node* createNode(Node *s, Data e) {
	Node *p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->L_link = s;
	p->R_link = NULL;
	s->R_link = p;
	printf("push %c\n", e);
	return p;
}

void push(Node *s, Data e) {
	Node *p = finalNode(s); 
	p = createNode(p, e);  
}

void pop(Node *s) {
	Node *p = finalNode(s); 
	if (p->L_link == NULL) {
		isListEmpty(s);
		return;
	}
	printf("pop : %c\n", p->data);
	p->L_link->R_link = NULL; 
	free(p); 
}

void search(Node *s, Data e) {
	Node *p = s;

	if (s->R_link == NULL) {
		isListEmpty(s);
		return;
	}

	int cnt = 0; 
	int find = 0;  
	isListEmpty(s);
	while (p != NULL) { 
		if (p->data == e) {
			find = 1;
			printf("%c is in node%d\n", p->data, cnt);  
			break; 
		}
		p = p->R_link;
		cnt++;
	}
	if (find != 1) printf("there is no %c\n", e);
}

void count(Node *s) {
	Node *p = s;
	int cnt = 0; 
	isListEmpty(s);

	while (p->R_link != NULL) { 
		cnt++; 
		p = p->R_link;
	}

	printf("the number of customer is %d\n", cnt);  
}

void show(Node *s) {
	int cnt = 0;
	if (s->R_link == NULL) {
		isListEmpty(s);
		return;
	}
	while (s != NULL) {
		if (cnt != 0) Print(s); 
		s = s->R_link;
		cnt++;
	}
	printf("\n");
}

void reverse(Node *s) {
	if (s->R_link == NULL) {
		isListEmpty(s);
		return;
	}
	s = finalNode(s);
	int cnt = 0;
	while (s->L_link != NULL) {
		Print(s);
		s = s->L_link;
		cnt++;
	}
	printf("\n");
}
void Print(Node *s) {
	printf("%c ", s->data);
}
void printNode(Node *s) {
	printf("data : %c | L-link : %p | R-link : %p |\n",
		s->data, s->L_link, s->R_link);
}
void isListEmpty(Node *s) {
	if (s->R_link == NULL) printf("stack is empty!!\n");
}