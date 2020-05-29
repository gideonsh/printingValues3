#pragma once

#include<iostream>
using namespace std;
#include "Student.h"

class ListNode
{
private:
	

public:
	Student* m_Student;
	ListNode* next;
	ListNode* prev;

	ListNode() = delete;
	ListNode(Student* p_Student);
	ListNode* makeListNode(Student* p_Student);
	void deleteListNode(int p_Id);
};