#include<stdio.h>

void swap(int *lhs, int* rhs);
void down(int* arr, int current, int last);
void reheap_down(int* arr, int length) {

	int end = length - 1;
	int current = get_parent(end);

	while (current >= 0) {
		down(arr, current--, end);
	}
}
void swap(int *lhs, int* rhs) {
	int temp = *lhs;
	*lhs = *rhs;
	*rhs = temp;
}
void down(int* arr, int current, int last) {

	int left;
	int right;
	int max;

	while ((current * 2) + 1 <= last) {
		left = (current * 2) + 1;
		right = (current * 2) + 2;
		max = current;

		if (arr[left] > arr[max]) {
			max = left;
		}

		if (right <= last && arr[right] > arr[max]) {
			max = right;
		}

		if (max != current) {
			swap(&arr[current], &arr[max]);
			current = max;
		}
		else {
			return;
		}
	}
}
