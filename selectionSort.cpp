#include <iostream>

using namespace std;

int main()
{
	int a[] = {3,2,1,4,6,5};
	for(int i=0; i<5; i++)
	{
		int smallest = i;
		int j = i + 1;
		for(j; j<6; j++)
		{
			if(a[j] < a[smallest])
				smallest = j;
		}
		int temp = a[smallest];
		a[smallest] = a[i];
		a[i] = temp;
	}
	for(int i=0; i<6; i++)
		cout << a[i] << " ";
	cout << endl;
}