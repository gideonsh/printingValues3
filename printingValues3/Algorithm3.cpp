#include "Algorithm3.h"

Algorithm3::Algorithm3(Student* arr, int n, int k)
{
	m_cmpCount = 0;
	QuickSort(arr, 0, n-1);
	printTillK(arr, n, k);
}

void Algorithm3::QuickSort(Student* arr, int left, int right)
{
	int pivot;

	if (left < right)
	{
		pivot = Partition(arr, left, right);
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}

int Algorithm3::Partition(Student* arr, int left, int right)
{
	int pivotIndex = left;
	int indexToCompare = right;

	while (pivotIndex != indexToCompare)
	{
		if (pivotIndex < indexToCompare)
		{
			if (arr[pivotIndex].getId() > arr[indexToCompare].getId())
			{
				Student::swap(arr + pivotIndex, arr + indexToCompare);
				int temp = indexToCompare;
				indexToCompare = pivotIndex + 1;
				pivotIndex = temp;
			}
			else
			{
				indexToCompare--;
			}
		}
		else if (pivotIndex > indexToCompare)
		{
			if (arr[pivotIndex].getId() < arr[indexToCompare].getId())
			{
				Student::swap(arr + pivotIndex, arr + indexToCompare);
				int temp = indexToCompare;
				indexToCompare = pivotIndex - 1;
				pivotIndex = temp;
			}
			else
			{
				indexToCompare++;
			}
		}
		m_cmpCount++;
	}
	return pivotIndex;
}

void Algorithm3::printTillK(Student* arr, int n, int k)
{
	bool stop = false;
	for (int i = 0; i < n && stop == false; i++)
	{
		if (arr[i].getId() >= k)
		{
			stop = true;
		}
		else
		{
			cout << arr[i].getId() << " ";
		}
		m_cmpCount++;
	}
	cout << endl;
}

int Algorithm3::getComparesCount()
{
	return m_cmpCount;
}