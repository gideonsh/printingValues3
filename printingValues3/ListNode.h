#pragma once

#include<iostream>
using namespace std;
#include "Student.h"

class ListNode
{
private:
	// person cell;

public:
	Student m_Student;

	ListNode* next;
	ListNode* prev;


	ListNode* makeListNode(int p_Id, char* p_Name);
	void deleteListNode(int p_Id);

};