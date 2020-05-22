#include "TreeNode.h"

TreeNode::TreeNode()
{
	m_Left = m_Right = nullptr;
	m_Data = nullptr;
}

TreeNode::TreeNode(Student* data, TreeNode* left, TreeNode* right)
{
	m_Key = data->getId();
	m_Data = data;
	m_Left = left;
	m_Right = right;
}

TreeNode::~TreeNode()
{
	if (m_Left != nullptr)
		delete m_Left;
	if (m_Right != nullptr)
		delete m_Right;
}

void TreeNode::Inorder(int k, bool& stop, int& cmpCount)
{
	if (stop == false)
	{
		if (m_Left != nullptr)
			m_Left->Inorder(k, stop, cmpCount);

		cmpCount++;
		if (m_Data->getId() >= k)
			return;
		m_Data->printStudentInfo();

		if (m_Right != nullptr)
			m_Right->Inorder(k, stop, cmpCount);
	}
}
