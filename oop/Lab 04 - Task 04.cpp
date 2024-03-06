//Lab 04 - Task 04

#include "iostream"

using namespace std;

void getEvenOdd(const int ar[], const int n_ar, int*& even, int& n_even, int*& odd, int& n_odd)
{
	//make sure both holds 0
	n_even = n_odd = 0;

	//calculating the count of even and odd numbers of ar
	for (int i = 0; i < n_ar; i++)
	{
		if (ar[i] % 2 == 0)
			n_even++;
		else
			n_odd++;
	}

	//allocating memory (dynamically on heap) to even array which holds even numbers of ar only if there are some even
	if (n_even > 0)
	{
		even = new int[n_even];

		//copying even elements in respective arrays from ar
		for (int i = 0, j = 0; i < n_ar; i++)
		{
			if (ar[i] % 2 == 0)
			{
				even[j] = ar[i];
				j++;
			}
		}
	}

	//allocating memory (dynamically on heap) to even array which holds odd numbers of ar only if there are some odd
	if (n_odd > 0)
	{
		odd = new int[n_odd];

		//copying even elements in respective arrays from ar
		for (int i = 0, j = 0; i < n_ar; i++)
		{
			if (ar[i] % 2 != 0)
			{
				odd[j] = ar[i];
				j++;
			}
		}
	}
}

int main()
{
	int n_arEven = 0;	//holds the size of even number array returned by the function
	int* arEven = NULL;	//holds address of even number array allocated by function

	int n_arOdd = 0;	//holds the size of odd number array returned by the function
	int* arOdd = NULL;	//holds address of odd number array allocated by function

	int ar1[] = { 11, 2, 3, 5, 8, 9, 7, 1 };			//initializing ar1 array
	int ar1_size = sizeof(ar1) / sizeof(ar1[0]);	//size of array ar1

	//calling the funcion and getting the addresses of new arrays in arEven and arOdd along with their sizes n_arEven and n_arOdd respectively
	getEvenOdd(ar1, ar1_size, arEven, n_arEven, arOdd, n_arOdd);

	//display the contents of arEven if any
	if (arEven == NULL)	//or if(n_arEven == 0)
		cout << "No Even Numbers Exist in the Array!" << endl;
	else
	{
		cout << "Even Numbers Exist in the Array: ";
		for (int i = 0; i < n_arEven; i++)
		{
			cout << arEven[i] << "\t";	//or *(arEven + 1)
		}
	}

	//display the contents of arOdd if any
	if (arOdd == NULL)	//or if(n_arOdd == 0)
		cout << "No Odd Numbers Exist in the Array!" << endl;
	else
	{
		cout << endl << "Odd Numbers Exist in the Array: ";
		for (int i = 0; i < n_arOdd; i++)
		{
			cout << arOdd[i] << "\t";	//or *(arOdd + 1)
		}  

	//freeing the memory resources if any allocated on heap for arEven by getEvenOdd function
	if (arEven != NULL)	//or if(n_arEven != 0)
		delete[] arEven;

	//freeing the memory resources if any allocated on heap for arOdd by getEvenOdd function
	if (arOdd != NULL)	//or if(n_arOdd != 0)
		delete[] arOdd;

	return 0;
}
