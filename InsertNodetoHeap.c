#include <stdio.h> 
#define MAX_ELEMENT 10000

typedef struct {
	int key;
} element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} heap_t;

void insert_max_heap(heap_t *h, element newe) {
	int i;
	i = ++(h->heap_size);
	while ((i != 1) && (newe.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = newe;
}
