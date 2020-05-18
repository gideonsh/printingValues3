#include <iostream>
using namespace std;
#include "Algorithm3.h"

int PrintBySort(int arr[], int n, int k);

int main()
{
	int* arr = new int[10];
	arr[0] = 4;
	arr[1] = 1;
	arr[2] = 3;
	arr[3] = 2;
	arr[4] = 7;
	arr[5] = 5;
	arr[6] = 6;
	arr[7] = 8;
	arr[8] = 9;
	arr[9] = 10;

	int k = 7;
	int n = 10;

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	

//	int cmps_NaivePrint = NaivePrint(Student arr[], n, k);
//	int cmps_BSTPrint = BSTPrint(arr, n, k);
	int cmps_PrintBySort = PrintBySort(arr, n, k);

	cout << "PrintBySort: " << cmps_PrintBySort << " comparisons" << endl;
}

int PrintBySort(int arr[], int n, int k)
{
	cout << "\nIn PrintBySort Function:" << endl;
	int amount;
	Algorithm3* algo3 = new Algorithm3(arr, n, k);
	amount = algo3->getComparesCount();
	delete algo3;
	return amount;
}