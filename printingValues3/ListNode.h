#pragma once

#include<iostream>
using namespace std;
#include "Person.h"

class ListNode
{
private:
	// person cell;

public:
	Person m_Person;

	ListNode* next;
	ListNode* prev;


	ListNode* makeListNode(int p_Id, char* p_Name);
	void deleteListNode(int p_Id);

};