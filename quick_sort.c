#include <stdio.h>
#define LEN(x) (sizeof(x)/sizeof(typeof(x[0])))
#define quickSort(x,y) (quickSortEx(x,0,y-1))
void swap(int *x, int *y);
int partition(int [], int, int);
void quickSortEx(int [], int, int);
void printSortedArray(int [], int);

int main(void){
	int a[] = {34,92,70,40,61,30,26,36,2,30};
	quickSort(a, LEN(a));
	printSortedArray(a, LEN(a));
	return 0;
}

void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

int partition(int arr[], int front, int rear){
	int pivot = arr[rear];
	int pivot_idx = front;
	for (int i = front;i < rear;++i)
		if (arr[i] < pivot)
			swap(&arr[i], &arr[pivot_idx++]);

	swap(&arr[pivot_idx], &arr[rear]);

	return pivot_idx;
}
void quickSortEx(int arr[], int front, int rear){
	int pivot;
	if (front < rear){
		pivot = partition(arr, front, rear);
		quickSortEx(arr, front, pivot-1);
		quickSortEx(arr, pivot+1, rear);
	}
}


void printSortedArray(int arr[], int size){
	for(int i = 0;i<size;++i)
		printf("%d\n", arr[i]);
}
