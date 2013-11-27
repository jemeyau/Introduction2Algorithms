#include <iostream>

using namespace std;

void printArray(const int a[], const int len);

/**
 * 待排序数组中元素的大小要小于 k
 */
int* sort(int a[], int k, int len)
{
	int c[k];
	int b[len];
	for(int i=0; i<k; i++)
		c[i] = 0;
	for(int i=0; i<len; i++)
		c[a[i]] += 1;
	for(int i=1; i<k; i++)
		c[i] = c[i] + c[i-1];
	for(int i=len-1; i>=0; i--)
	{
		b[c[a[i]] - 1] = a[i];
		c[a[i]] -= 1;
	}

	cout << "a: ";
	printArray(a, 6);
	cout << "b: ";
	printArray(b, 6);
	cout << "c: ";
	printArray(c, 60);
	return b;
}

void printArray(const int a[], const int len)
{
	for(int i=0; i<len; i++)
		cout << a[i] << " " ;
	cout << endl;
}

int main()
{
	int a[] = {31,41, 59, 26, 41, 58};
	//printArray(a, 6);
	sort(a, 60, 6);
	//printArray(b, 6);
}
