#pragma once

#include<iostream>
using namespace std;
#include "ListNode.h"

class List
{
private:
	ListNode* m_Head;
	ListNode* m_Tail;
	int m_cmpCount;

public:
	List();
	~List();
	void makeEmptyList();
	void insertToEmpty(ListNode* nodeToAdd);
	void insertToHead(ListNode* nodeToAdd);
	void insertToInner(ListNode* nodeToAdd, ListNode* p);
	void insertToTail(ListNode* nodeToAdd);
	void insert(Student* student);

	void deleteNode(Student* p_Student);
	void deleteFromHead();
	void deleteFromTail();
	void deleteFromInner(ListNode* prev);
	void deleteNode(ListNode* nodeToDelete);

	bool isEmpty();
	ListNode* findNode(int p_Id);

	int getComparesCount();
	void printList();
};
