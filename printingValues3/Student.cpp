#include "Student.h"

Student::Student(string name, string id)
{
	m_Name = name;
	m_Id = stoi(id);
}

void Student::setName(string name)
{
	try 
	{
		if (isNameValid(name))
		{
			m_Name = name;
		}
	}
	catch(exception ex)
	{
		throw ex;
	}
}

void Student::setId(string id)
{
	try
	{
		if (isIdValid(id))
		{
			m_Id = stoi(id);
		}
	}
	catch (exception ex)
	{
		throw ex;
	}
}

string Student::getName()
{
	return m_Name;
}

int Student::getId()
{
	return m_Id;
}

void Student::printStudentInfo()
{
	cout << "Student name: " << m_Name << " ID: " << m_Id << endl;
}