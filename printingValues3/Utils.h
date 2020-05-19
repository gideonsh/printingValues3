#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;

#include "Student.h"

class Utils
{
public:
	static void getDataFromUser(int& n, int& k, Student*& students)
	{
		string input, id, name;

		getline(cin, input);
		if (isValidInputNumber(input) == false)
			throw invalid_argument("Not number entered for n value.");

		n = stoi(input);

		try {
			students = new Student[n];
			for (int i = 0; i < n; i++)
			{
				cin >> id;
				if (Student::isIdValid(id) == true)
				{
					cin.ignore();
					getline(cin, name);
					if (Student::isNameValid(name) == true)
					{
						students[i] = Student(name, id);
					}
				}
			}
		}
		catch (invalid_argument ex)
		{
			throw ex;
		}

		getline(cin, input);
		if (isValidInputNumber(input) == false)
			throw invalid_argument("Not number entered for k value.");
	}

	static bool isValidInputNumber(string input)
	{
		for (int i = 0; i < input.length(); i++)
		{
			if (isdigit(input[i]) == false)
				return false;
		}
		return true;
	}


};