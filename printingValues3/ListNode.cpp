
#include "ListNode.h"
#include "Student.h"


ListNode::ListNode(Student* p_Student)
{
	m_Student = p_Student;
	next = nullptr;
	prev = nullptr;
}

 ListNode* ListNode::makeListNode(Student* p_Student)
{
	 ListNode* node = new ListNode(p_Student);
	 return node;
}

void ListNode::deleteListNode(int p_Id)
{
	//delete student
}
