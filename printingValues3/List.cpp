
#include "List.h"



void List::makeEmptyList()
{
	m_Head = nullptr;
	m_Tail = nullptr;
}

void List::insertNode(ListNode* p_NewNode)
{
	ListNode* currentNode;
	if (!findNode(p_NewNode->m_Person.m_Id, currentNode))
	{
		if (currentNode->m_Person.m_Id == m_Head->m_Person.m_Id)
		{
			m_Head->prev = p_NewNode;
			p_NewNode = m_Head;
			m_Head = p_NewNode;
		}
		else if (currentNode->m_Person.m_Id == m_Tail->m_Person.m_Id)
		{
			m_Tail->next = p_NewNode;
			p_NewNode->prev = m_Tail;
			m_Tail = p_NewNode;
		}
		else
		{
			p_NewNode->next = currentNode->next;
			currentNode = p_NewNode;
			p_NewNode->prev = currentNode;
			p_NewNode->next->prev = p_NewNode;
		}
	}
}

void List::deleteNode(int p_Id)
{
	//////////option one////////////
	//if (m_Head != nullptr)
	//{
	//	ListNode* currentNode = m_Head;
	//	ListNode* nextNode = m_Head->next;
	//	if (currentNode.person.m_Id == p_Id)
	//	{
	//		m_Head = nextNode;
	//		//delete person
	//		delete currentNode;
	//	}
	//	while (nextNode != nullptr)
	//	{
	//		if (currentNode.person.m_Id == p_Id)
	//		{
	//			//deleter person func
	//			currentNode = currentNode->prev;
	//			delete nextNode->prev;
	//			nextNode->prev = currentNode;
	//		}
	//		currentNode = nextNode;
	//		nextNode = nextNode->next;
	//	}
	//	if (currentNode.person.m_Id == p_Id)
	//	{
	//		m_Tail = currentNode->prev;
	//		currentNode->prev->next = nullptr;
	//		//delete person
	//		delete currentNode;
	//	}
	//}
	///// end option one/////////////

	/////option two///////////
	ListNode* currentNode;
	ListNode* nextNode;
	if (findNode(p_Id, currentNode))
	{
		if (currentNode->prev == nullptr)
		{
			m_Head = currentNode->next;
			//delete m_Person
			delete currentNode;
		}
		else if (currentNode->next == nullptr)
		{
			m_Tail = currentNode->prev;
			//delete person
			delete currentNode;
		}
		else
		{
			nextNode = currentNode->next;
			currentNode = currentNode->prev;
			//delete m_Person
			delete nextNode->prev;
			nextNode->prev = currentNode;
		}
	}
	////end option two////////
}

bool List::isEmpty()
{
	if (m_Head == nullptr && m_Tail == nullptr)
		return true;
	return false;
}

bool List::findNode(int p_Id, ListNode*& p_NodeToChange)
{
	ListNode* currentNode = m_Head;

	if (currentNode->m_Person.m_Id > p_Id)
	{
		p_NodeToChange = currentNode;
		return false;
	}

	while (currentNode->next != nullptr)
	{
		if (currentNode->m_Person.m_Id == p_Id)
		{
			p_NodeToChange = currentNode;
			return true;
		}
		if (currentNode->m_Person.m_Id < p_Id && currentNode->next->m_Person.m_Id > p_Id)
		{
			p_NodeToChange = currentNode;
			return false;
		}
		currentNode = currentNode->next;
	}
	if (currentNode->m_Person.m_Id == p_Id)
	{
		p_NodeToChange = currentNode;
		return true;
	}
	else
	{
		p_NodeToChange = currentNode;
		return false;
	}
}