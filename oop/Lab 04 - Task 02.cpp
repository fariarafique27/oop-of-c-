//Lab 04 - Task 02

#include "iostream"

using namespace std;

int main()
{
	//to hold the size of array
	int size = 0;

	cout << "How many values you want to enter? ";
	cin >> size;

	cout << endl;

	//allocating memory on runtime (on heap)
	int* pa = new int[size];

	//getting input from user
	for (int i = 0; i < size; i++)
	{
		cout << "Enter value " << (i + 1) << " = ";
		cin >> pa[i];	//or cin >> *(pa + 1)
	}

	//to hold the sum of array elements
	int sum = 0;

	//calculating the sum of array elements
	for (int i = 0; i < size; i++)
	{
		sum = sum + pa[i];	//or sum = sum + *(pa + i)
	}

	//displaying the sum of array elements
	cout << "\nSum of values = " << sum << endl;

	//freeing the memory resources allocated on heap
	delete[] pa;

	return 0;
}