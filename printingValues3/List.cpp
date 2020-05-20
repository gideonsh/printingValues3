#include "List.h"

List::List()
{
	m_Head = nullptr;
	m_Tail = nullptr;
	m_cmpCount = 0;
}

List::~List()
{
	this->makeEmptyList();
}

void List::makeEmptyList()
{
	if (m_Head != nullptr)
	{
		ListNode* current = m_Head;
		ListNode* prev = nullptr;
		while (current != nullptr)
		{
			prev = current;
			current = current->next;
			deleteNode(prev);
		}
	}
	m_Head = nullptr;
	m_Tail = nullptr;
}

void List::insertToEmpty(ListNode* nodeToAdd)
{
	m_Tail = nodeToAdd;
	m_Head = nodeToAdd;
}

void List::insertToHead(ListNode* nodeToAdd)
{
	nodeToAdd->next = m_Head;
	m_Head->prev = nodeToAdd;
	m_Head = nodeToAdd;
}

void List::insertToInner(ListNode* nodeToAdd, ListNode* p)
{
	nodeToAdd->prev = p;
	nodeToAdd->next = p->next;
	p->next = nodeToAdd;
	nodeToAdd->next->prev = nodeToAdd;
}

void List::insertToTail(ListNode* nodeToAdd)
{
	nodeToAdd->prev = m_Tail;
	m_Tail->next = nodeToAdd;
	m_Tail = nodeToAdd;
}

void List::insert(Student* student)
{
	ListNode* prev;
	ListNode* nodeToAdd = new ListNode(student);

	if (this->isEmpty())
		insertToEmpty(nodeToAdd);

	else
	{
		bool existNode = findNode(student->getId(), prev);
		if (!existNode)
		{
			if (prev == nullptr)
				insertToHead(nodeToAdd);
			else if (prev == m_Tail)
				insertToTail(nodeToAdd);
			else
				insertToInner(nodeToAdd, prev);
		}
		else
		{
			throw invalid_argument("Student already exists");
		}
	}
}

void List::deleteNode(Student* student)
{
	ListNode* prev;

	if (this->isEmpty())
		throw invalid_argument("The List is empty.");
	else
	{
		bool existNode = findNode(student->getId(), prev);
		if (existNode)
		{
			if (prev == nullptr)
			{
				deleteFromHead();
			}
			else if (prev->next == m_Tail)
			{
				deleteFromTail();
			}
			else
			{
				deleteFromInner(prev);
			}
		}
		else
			throw invalid_argument("Student does not exsit.");
	}
}

void List::deleteFromHead()
{
	m_Head = m_Head->next;
	if (m_Head == nullptr)
	{
		deleteNode(m_Tail);
		m_Tail = nullptr;
	}
	else
	{
		deleteNode(m_Head->prev);
		m_Head->prev = nullptr;
	}
}

void List::deleteFromTail()
{
	if (m_Tail == m_Head)
	{
		deleteNode(m_Tail);
		m_Tail = m_Head = nullptr;
		return;
	}
	m_Tail = m_Tail->prev;
	deleteNode(m_Tail->next);
	m_Tail->next = nullptr;
}

void List::deleteFromInner(ListNode* prev)
{
	ListNode* nodeToDelete = prev->next;
	prev->next = nodeToDelete->next;
	nodeToDelete->next->prev = prev;
	deleteNode(nodeToDelete);
}

void List::deleteNode(ListNode* nodeToDelete)
{
	delete nodeToDelete;
}

bool List::isEmpty()
{
	return (m_Head == nullptr && m_Tail == nullptr);
}

bool List::findNode(int p_Id, ListNode*& prevNode)
{
	ListNode* curr = m_Head;
	ListNode* prev = nullptr;

	while (curr != nullptr)
	{
		m_cmpCount++;
		if (curr->m_Student->getId() >= p_Id)
		{
			prevNode = prev;
			if(curr->m_Student->getId() == p_Id)
				return true;
			return false;
		}
		prev = curr;
		curr = curr->next;
	}
	prevNode = prev;
	return false;
}

int List::getComparesCount()
{
	return m_cmpCount;
}

void List::printList()
{
	ListNode* curr = m_Head;
	while (curr != nullptr)
	{
		curr->m_Student->printStudentInfo();
		curr = curr->next;
	}
	cout << endl;
}
