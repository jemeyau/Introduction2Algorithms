#include <iostream>

using namespace std;

typedef struct{
	 int length;
	 int heapsize;
	 int *a;
} Heap;

int left_child(int i)
{
 	return 2*i + 1;
}

int right_child(int i)
{
 	return 2*i + 2;
}

void max_heapify(Heap &heap, int i)
{
	 int left = left_child(i);
	 int right = right_child(i);
/*	 if(left > heap.heapsize)
         return;
         */
	 int largest;
	 if(left <= heap.heapsize && *(heap.a+left) > *(heap.a+i))
         largest = left;
	 else 
         largest = i;
	 if(right <= heap.heapsize && *(heap.a+right) > *(heap.a+largest))
         largest = right;
	 if(largest != i)
	 {
		 int temp = *(heap.a+largest);
		 *(heap.a+largest) = *(heap.a+i);
		 *(heap.a+i) = temp;
		 max_heapify(heap, largest);
	 }
}

void build_max_heap(Heap &heap)
{
	 heap.heapsize = heap.length - 1;
	 for(int i=heap.length/2-1; i>=0; i--)
     {
         max_heapify(heap,i);
     }
}

void heapsort(Heap &heap)
{
	 build_max_heap(heap);
	 for(int i=heap.length-1; i>0; i--)
	 {
		 int temp = *(heap.a);
		 *(heap.a) = *(heap.a + i);
		 *(heap.a + i) = temp;
		 heap.heapsize -= 1;
         for(int i=0; i<5; i++)
            cout << *(heap.a+i) << " ";
         cout << endl;

		 max_heapify(heap,0);
	 }
}

int main()
{
	 int a[] = {1, 2, -1, 3, 4};
	 Heap heap;
	 heap.length = 5;
	 heap.a = a;
	 heapsort(heap);
/*	 for(int i=0; i<5; i++)
	 	cout << *(heap.a+i) << " ";
	 cout << endl;
     */
}
