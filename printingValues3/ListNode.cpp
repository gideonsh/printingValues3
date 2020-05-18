
#include "ListNode.h"


ListNode* ListNode::makeListNode(int p_Id, char* p_Name)
{
	//create person
	m_Person = new Person(p_Id, p_Name);
}

void ListNode::deleteListNode(int p_Id)
{
	//delete person
}
