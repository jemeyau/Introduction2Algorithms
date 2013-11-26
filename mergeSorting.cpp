#include <iostream>

using namespace std;

void printArray(const int a[], const int len);

void merge(int a[], int p, int q, int r)
{
	int lenOfL = q - p + 1;
	int lenOfR = r - p;
	int left[lenOfL];
	int right[lenOfR];
	//复制数组
	for(int i=0; i<lenOfL; i++)
	{
		left[i] = a[i];
	}

	for(int i=0; i<lenOfR; i++)
	{
		right[i] = a[i+lenOfL];//此处需注意 数组 a 的开始位置为 i+lenOfL
	}

	//合并操作
	int ia = 0;
	int ib = 0;
	int index = 0;
	while(ia<lenOfL && ib<lenOfR)
	{
		if(left[ia] < right[ib])
		{
			a[index] = left[ia];
			ia++;
		} else {
			a[index] = right[ib];
			ib++;
		}
		index++;
	}
	while(ia<lenOfL)
	{
		a[index] = left[ia];
		ia++;
		index++;
	}
	while(ib<lenOfR)
	{
		a[index] = right[ib];
		ib++;
		index++;
	}

}

void mergeSort(int a[], int p, int r)
{
	if(p<r)
	{
		int q = (p+r)/2;
		mergeSort(a, p, q);
		mergeSort(a, q+1, r);
		merge(a, p, q, r);
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
	printArray(a, 6);
	mergeSort(a, 0, 5);
	printArray(a, 6);
}
