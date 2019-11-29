#include <stdio.h> 
#define MAX_ELEMENT 100000 

typedef struct {
	int key;
} element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} heap_t;
element delete_max_heap(heap_t *h) {
	int parent, child;
	element newe, temp;
	newe = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		if ((child < h->heap_size) && ((h->heap[child].key) < h->heap[child + 1].key)) {
			child++;
		}
		if (temp.key >= h->heap[child].key) {
			break;
		}
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return newe;
}
