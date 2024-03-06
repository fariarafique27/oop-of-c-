//Lab 04 - Task 01

#include "iostream"

using namespace std;

int main()
{
	//creating two pointers 
	float* ptrX = NULL, * ptrY = NULL;

	//allocating memory on heap
	ptrX = new float(4.5f);
	ptrY = new float(9.3f);

	//displaying the required information
	cout << "&ptrX = " << &ptrX << " ptrX = " << ptrX << " *ptrX = " << *ptrX << endl;
	cout << "&ptrY = " << &ptrY << " ptrY = " << ptrY << " *ptrY = " << *ptrY << endl;

	//freeing the memory resources occupied on heap
	delete ptrX, ptrY;

	return 0;
}
