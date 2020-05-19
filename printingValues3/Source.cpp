#include "Utils.h"
#include "Algorithm3.h"
#include "Student.h"

int NaivePrint(Student arr[], int n, int k);
int PrintBySort(Student arr[], int n, int k);

int main()
{
	Student* students;
	int n;
	int k;
	Utils::getDataFromUser(n, k, students);

//	int cmps_NaivePrint = NaivePrint(students, n, k);
//	int cmps_BSTPrint = BSTPrint(arr, n, k);
	int cmps_PrintBySort = PrintBySort(students, n, k);

	delete[] students;

//	cout << "NaivePrint: " << cmps_NaivePrint << " comparisons" << endl;
//	cout << "BSTPrint: " << cmps_BSTPrint << " comparisons" << endl;
	cout << "PrintBySort: " << cmps_PrintBySort << " comparisons" << endl;
}

//int NaivePrint(Student arr[], int n, int k)
//{
//	
//}

int PrintBySort(Student arr[], int n, int k)
{
	cout << "\nIn PrintBySort Function:" << endl;
	int amount;
	Algorithm3* algo3 = new Algorithm3(arr, n, k);
	amount = algo3->getComparesCount();
	delete algo3;
	return amount;
}