#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdexcept>
using namespace std;

class Student
{
private:
	int m_Id;
	string m_Name;
public:
	Student() = default;
	Student(string name, string id);
	Student(const Student& other);
	Student(Student&& other);
	void setName(string name);
	string getName();
	int getId();
	void printStudentInfo();

	static bool isNameValid(string name)
	{
		int length = name.length();
		if (name == "")
			throw invalid_argument("Name was empty.");

		string first = name.substr(0, name.find(' '));
		if (first.length() == length)
			throw invalid_argument("Last name is missing.");

		string last = name.substr(name.find(' ') + 1, ' ');

		for (int i = 0; i < first.length(); i++)
		{
			if (isalpha(first[i]) == false)
				throw invalid_argument("First name includes not alphabetic characters.");
		}

		for (int i = 0; i < last.length(); i++)
		{
			if (isalpha(last[i]) == false)
				throw invalid_argument("Last name includes not alphabetic characters.");
		}

		return true;
	}
	
	static bool isIdValid(Student students[], int n, string id)
	{
		if (id == "")
			throw invalid_argument("ID is empty.");

		for (int i = 0; i < id.length(); i++)
		{
			if (isdigit(id[i]) == false)
				throw invalid_argument("ID includes not numeric characters.");
		}

		int studentId = stoi(id);
		for (int i = 0; i < n; i++)
		{
			if (students[i].getId() == studentId)
				throw invalid_argument("Student id already exsits.");
		}

		return true;
	}

	const Student& operator=(const Student& other)
	{
		if (this != &other)
		{
			m_Id = other.m_Id;
			m_Name = other.m_Name;
		}
		return *this;
	}

	static void swap(Student* a, Student* b)
	{
		Student temp = *a;
		*a = *b;
		*b = temp;
	}
};