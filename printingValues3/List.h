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
	List() = default;
	void makeEmptyList();
	void insertToEmpty(ListNode* p_NewNode);
	void insertToHead(ListNode* p_NewNode);
	void insertToInner(ListNode* p_NewNode, ListNode* p_PrevNode);
	void insertToTail(ListNode* p_NewNode);
	void insert(ListNode* p_NewNode);

	//void deleteFromEmpty(int p_Id);
	void deleteNode(Student* p_Student);
	void deleteSingleNode();
	void deleteFromHead();
	void deleteFromTail();
	void deleteFromInner(ListNode* p_NodeToDelete);

	bool isEmpty();
	bool findNode(int p_Id, ListNode*& p_NodeToChange);

};
