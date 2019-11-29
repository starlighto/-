#include <stdio.h>
#include <stdlib.h>

#define Data char 
#define MAX 10 
#define START 1  

char arrayQueue[MAX];
int rear = 0;
int front = 0;

void push(Data data) {
	if (rear%MAX == (front%MAX) - 1) {
		printf("Queue is full\n");
	}
	else {
		arrayQueue[rear%MAX] = data;
		rear++;
		printf("Push %c\n", data);
	}
	printPoint();
}

void pop() {
	if (front%MAX == rear % MAX) {
		printf("Stack is empty!!\n");
		return;
	}

	printf("Pop : %c\n", arrayQueue[front++]);
	arrayQueue[front - 1] = '.';
	printPoint();
}

void show() {
	int i;
	for (i = front; i <= rear; i++) {
		printf("%c  ", arrayQueue[i%MAX]);
	}
	printf("\n");
	printPoint();
}

void count() {
	printf("The number of Queue is %d\n", rear - front + 1);
}

int printPoint() {
	printf("Front = %d\n", front%MAX);
	printf("Rear = %d\n", rear%MAX);
	return 0;
}

void main() {
	char input1, input2;
	int i;
	for (i = 0; i < MAX; i++) arrayQueue[i] = 0;

	printf(" + :Push \n P :Pop\n S :Show all Queue\n C :Count queue\n Q :Quit\n");

	while (1) {
		printf("\nÀÔ·Â: ");
		input1 = getchar();
		input1 = toupper(input1);
		switch (input1) {
		case '+':
			input2 = getchar();
			push(input2);
			break;

		case 'P':
			pop();
			break;

		case 'S':
			show();
			break;

		case 'C':
			count();
			break;

		case 'Q':
			printf("\n");
			exit(1);
			break;
		default: break;
		}
		while (input1 != EOF && input1 != '\n') {
			input1 = getchar();
		}
	}
}
