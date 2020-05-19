#pragma once
#include <iostream>
using namespace std;

#include "Student.h"

class Algorithm3
{
private:
	int m_cmpCount;

public:
	Algorithm3(Student* arr, int n, int k);
	Algorithm3(const Algorithm3& other) = delete;
	void QuickSort(Student* arr, int left, int right);
	int Partition(Student* arr, int left, int right);
	int getComparesCount();
	void printTillK(Student* arr, int n, int k);
};
