#include <stdio.h>
#define PARENT(x)        ((x-1)/2)
#define SWAP(a,b)  {int t; t = a; a=b; b=t;}

void Heap(int *base, int n);
void ViewArr(int *arr, int n);
int main(void)
{
	int arr[12] = { 11,3,9,1,5,2,7,6,8,10,4,12 };
	ViewArr(arr, 12);
	Heap(arr, 12);
	ViewArr(arr, 12);
	return 0;
}
void InitHeap(int *base, int n);
void Heap(int *base, int n)
{
	int on = n;
	printf("HEAP 생성 과정\n");
	InitHeap(base, n);
}

void InitHeap(int *base, int n)

{
	int pa = 0;

	int now;

	int i;

	for (i = 1; i < n; i++)
	{
		now = i;

		while (now > 0)
		{
			pa = PARENT(now);
			if (base[now] > base[pa])
			{
				SWAP(base[now], base[pa]);

				now = pa;
			}
			else
			{
			break;
			}
		}
		ViewArr(base, i );
	}
}
void ViewArr(int *arr, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%2d ", arr[i]);
	}
	printf("\n");
}
