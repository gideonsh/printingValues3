#pragma once

#include<iostream>
using namespace std;
#include "ListNode.h"

class List
{
private:
	ListNode* m_Head;
	ListNode* m_Tail;

public:
	void makeEmptyList();
	void insertNode(ListNode* p_NewNode);
	void deleteNode(int p_Id);
	bool isEmpty();
	bool findNode(int p_Id, ListNode*& p_NodeToChange);

};
