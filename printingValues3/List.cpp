
#include "List.h"

List::List()
{
	m_Head = nullptr;
	m_Tail = nullptr;
}

void List::makeEmptyList()
{
	if (m_Head == nullptr)
	{
		return;
	}
	else
	{
		ListNode* current = m_Head;
		ListNode* prev = nullptr;
		while (current != nullptr)
		{
			prev = current;
			current = current->next;
			delete prev->m_Student;
			delete prev;
		}
	}
	m_Head = nullptr;
	m_Tail = nullptr;
}

void List::insertToEmpty(ListNode* p_NewNode)
{
	m_Head = p_NewNode;
	m_Tail = p_NewNode;
}

void List::insertToHead(ListNode* p_NewNode)
{
	p_NewNode->next = m_Head;
	m_Head->prev = p_NewNode;
	m_Head = p_NewNode;
}

void List::insertToInner(ListNode* p_NewNode, ListNode* p_PrevNode)
{
	p_NewNode->next = p_PrevNode->next;
	p_NewNode->prev = p_PrevNode;
	p_PrevNode->next->prev = p_NewNode;
	p_PrevNode->next = p_NewNode;
}

void List::insertToTail(ListNode* p_NewNode)
{
	m_Tail->next = p_NewNode;
	p_NewNode->prev = m_Tail;
	m_Tail = p_NewNode;
}

void List::insert(ListNode* p_NewNode)
{
	ListNode* current;
	if (m_Head == m_Tail)
	{
		insertToEmpty(p_NewNode);
		return;
	}
	bool existNode = findNode(p_NewNode->m_Student->getId, current);
	if (!existNode)
	{
		if (current == m_Head)
		{
			m_Head->prev = p_NewNode;
			p_NewNode->next = m_Head;
			m_Head = p_NewNode;
		}
		else if (current == m_Tail)
		{
			m_Tail->next = p_NewNode;
			p_NewNode->prev = m_Tail;
			m_Tail = p_NewNode;
		}
		else
		{
			insertToInner(p_NewNode, current);
		}
	}
	else
	{
		cout << "student already exist\n";
	}
}

void List::deleteSingleNode()
{
	ListNode* current = m_Head;
	m_Head = nullptr;
	m_Tail = nullptr;
	delete current->m_Student;
	delete current;
}

void List::deleteNode(Student* p_Student)
{
	ListNode* current;
	bool existNode = findNode(p_Student->getId, current);
	if (existNode)
	{
		if (current == m_Head && current->next == nullptr)
		{
			deleteSingleNode();
		}
		else if (current == m_Head)
		{
			deleteFromHead();
		}
		else if (current == m_Tail)
		{
			deleteFromTail();
		}
		else
		{
			deleteFromInner(current);
		}
	}
}

void List::deleteFromHead()
{
	ListNode* current = m_Head;
	m_Head = m_Head->next;
	m_Head->prev = nullptr;
	delete current->m_Student;
	delete current;
}

void List::deleteFromTail()
{
	ListNode* current = m_Tail;
	m_Tail = m_Tail->prev;
	m_Tail->next = nullptr;
	delete current->m_Student;
	delete current;
}

void List::deleteFromInner(ListNode* p_NodeToDelete)
{
	ListNode* prev = p_NodeToDelete->prev;
	prev->next = p_NodeToDelete->next;
	p_NodeToDelete->next = prev;
	delete p_NodeToDelete->m_Student;
	delete p_NodeToDelete;
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

	if (currentNode->m_Student->getId() > p_Id)
	{
		p_NodeToChange = currentNode;
		return false;
	}

	while (currentNode->next != nullptr)
	{
		if (currentNode->m_Student->getId() == p_Id)
		{
			p_NodeToChange = currentNode;
			return true;
		}
		if (currentNode->m_Student->getId() < p_Id && currentNode->next->m_Student->getId() > p_Id)
		{
			p_NodeToChange = currentNode;
			return false;
		}
		currentNode = currentNode->next;
	}
	if (currentNode->m_Student->getId() == p_Id)
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