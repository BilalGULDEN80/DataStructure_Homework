#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define SIZE 20
void insertToMax_heap(int *array, int x, int index);
int deleteMax(int *array, int index);

int main(int argc, char *argv[]) {
	int heap[SIZE + 1] = {0};  
	int heapSize = 0;
	insertToMax_heap(heap, 10, heapSize);
    insertToMax_heap(heap, 20, heapSize);
    insertToMax_heap(heap, 15, heapSize);
    insertToMax_heap(heap, 40, heapSize);
    insertToMax_heap(heap, 50, heapSize);
    insertToMax_heap(heap, 30, heapSize);
    printHeap(heap, heapSize);    
    printf("Silinen maksimum: %d\n", deleteMax(heap, heapSize));
	printHeap(heap, heapSize);

    printf("Silinen maksimum: %d\n", deleteMax(heap, heapSize));
    printHeap(heap, heapSize);

    printf("Silinen maksimum: %d\n", deleteMax(heap, heapSize));
    printHeap(heap, heapSize);

    return 0;
}

void insertToMax_heap(int *array, int x, int index)
{
	if(index == SIZE)
		printf("Heap dolu\n");
	else 
		{
			array[index] = x;
			while(index != 1 && array[index / 2] < array[index]) 
			{
				swap(&array[index / 2], &array[index]); 
				index /= 2;
			}
		}
}
int deleteMax(int *array, int index) 
{
	int max, i = 1;
	if(index == 1) 
	{
		printf("Heap bos\n");
		return 0;
	}
	else 
	{
		max = array[i];
		array[i] = array[index-1]; // son elemano baþa atadýk
		array[index-1] = 0; // Heapin en baþa atanan son elemaný sildim
		while(array[i] < array[2*i] || array[i] < array[(2*i) + 1]) {
		if(array[2*i] > array[(2*i) + 1]) { 
		swap(&array[2*i], &array[i]); 
		i = 2*i;
	}
		else { 
				swap(&array[(2*i) + 1], &array[i]); 
				i = (2*i) + 1;
			}
		}
		return max;
	}
}
