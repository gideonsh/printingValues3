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

void TreeNode::Inorder()
{
	if (m_Left != nullptr)
		m_Left->Inorder();

	m_Data->printStudentInfo;

	if (m_Right != nullptr)
		m_Right->Inorder();
}
