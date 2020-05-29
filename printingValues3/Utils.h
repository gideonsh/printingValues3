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

		cin >> input;
		if (isValidInputNumber(input) == false)
		{
			cout << "invalid input" << endl;
			exit(1);
		}

		n = stoi(input);

		try {
			students = new Student[n];
			for (int i = 0; i < n; i++)
			{
				cin >> id;
				if (Student::isIdValid(students, n, id) == true)
				{
					cin.ignore();
					getline(cin, name);
					if (Student::isNameValid(name) == true)
						students[i] = Student(name, id);
				}
			}
		}
		catch (invalid_argument ex)
		{
			delete[] students;
			cout << "invalid input" << endl;
			exit(1);
		}

		getline(cin, input);
		if (isValidInputNumber(input) == false)
		{
			cout << "invalid input" << endl;
			exit(1);
		}
		k = stoi(input);
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