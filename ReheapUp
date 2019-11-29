#include<stdio.h>

void swap(int *lhs, int* rhs);
void up(int* arr, int root, int current);
void reheapup(int* arr, int length) {

	int end = 1;

	while (end < length) {
		up(arr, 0, end++);
	}
}

void up(int* arr, int root, int current) {

	int parent;

	while (current > root) {
		parent = get_parent(current);
		if (arr[parent] >= arr[current])
			return;

		swap(&arr[parent], &arr[current]);
		current = parent;
	}
}
void swap(int *lhs, int* rhs) {
	int temp = *lhs;
	*lhs = *rhs;
	*rhs = temp;
}
