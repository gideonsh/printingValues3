#include "Utils.h"
#include "Algorithm3.h"
#include "List.h"

int NaivePrint(Student arr[], int n, int k);
int PrintBySort(Student arr[], int n, int k);

int main()
{
	Student* students;
	int n;
	int k;
	Utils::getDataFromUser(n, k, students);

	int cmps_NaivePrint = NaivePrint(students, n, k);
//	int cmps_BSTPrint = BSTPrint(arr, n, k);
	int cmps_PrintBySort = PrintBySort(students, n, k);

	delete[] students;

	cout << "NaivePrint: " << cmps_NaivePrint << " comparisons" << endl;
//	cout << "BSTPrint: " << cmps_BSTPrint << " comparisons" << endl;
	cout << "PrintBySort: " << cmps_PrintBySort << " comparisons" << endl;
}

int NaivePrint(Student arr[], int n, int k)
{
	cout << "\nIn NaivePrint Function:" << endl;
	int amount = 0;
	List list;
	ListNode* node;
	for (int i = 0; i < n; i++)
	{
		amount++;
		if (arr[i].getId() < k)
			list.insert(arr + i);
	}
	amount += list.getComparesCount();
	list.printList();
	return amount;
}

int PrintBySort(Student arr[], int n, int k)
{
	cout << "In PrintBySort Function:" << endl;
	int amount;
	Algorithm3* algo3 = new Algorithm3(arr, n, k);
	amount = algo3->getComparesCount();
	delete algo3;
	return amount;
}