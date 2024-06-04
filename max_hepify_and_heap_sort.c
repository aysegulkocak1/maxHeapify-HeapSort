#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void max_heapify(int *arr, int i, int N) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest;
    
    if (left < N && arr[left] > arr[i])
        largest = left;
    else
        largest = i;
    
    if (right < N && arr[right] > arr[largest])
        largest = right;
    
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        max_heapify(arr, largest, N);
    }
}

void build_max_heapify(int *arr,int N){
	int i;
    for (i = N / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, N);
}

void heap_sort(int *arr, int N) {
    int i;
    printf("dizinin buyukten kucuge siralanmis hali:\n");
	// bu þekilde de desc orderda sýralayabilirsin ya da min_hepify ile desc orderda sýralayabilirsin
    for (i = N - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        max_heapify(arr, 0, i);
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;
    printf("dizinin siralanmamis hali:\n");
    build_max_heapify(arr,n);
    
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    
    heap_sort(arr, n);
    
    printf("kucukten buyuge dizinin siralanmis hali:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}

