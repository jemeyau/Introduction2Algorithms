#include <iostream>

using namespace std;

void printArray(const int a[], const int len);

int partition(int a[], int p, int r)
{
	int i = p - 1;
	for(int j = p; j<r; j++)
	{
		if(a[j] <= a[r])
		{
			i += 1;
			int temp = a[j];
			a[j] = a[i];
			a[i] = temp;
		}
	}
	int temp = a[i+1];
	a[i+1] = a[r];
	a[r] = temp;
	return i+1;
}

void quickSort(int a[], int p, int r)
{
	if(p<r)
	{
		printArray(a,6);
		int q = partition(a, p, r);
		quickSort(a, p, q-1);
		quickSort(a, q+1, r);
	}
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
	quickSort(a, 0, 5);
	printArray(a, 6);
}
