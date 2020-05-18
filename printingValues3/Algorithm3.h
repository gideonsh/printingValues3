#pragma once
#include <iostream>
using namespace std;

class Algorithm3
{
private:
	int m_cmpCount;

public:
	Algorithm3(int* arr, int n, int k);
	void QuickSort(int* arr, int left, int right);
	int Partition(int* arr, int left, int right);
	int getComparesCount();
	void printTillK(int* arr, int n, int k);

	static void swap(int* a, int* b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}
};
