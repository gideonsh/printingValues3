//
//
//#include "BST.h"
//
//
//
//void BST::insertNode(TreeNode* p_NewNode)
//{
//	TreeNode* currentNode;
//	if (m_Head == nullptr)
//	{
//		m_Head = p_NewNode;
//	}
//	else
//	{
//		if (findeNode(p_NewNode->m_Data.getId(), currentNode))
//		{
//			cout << "Node Id already exist!\n";
//		}
//		else
//		{
//			if (currentNode != nullptr)
//			{
//				if (currentNode->m_Data.getId() > p_NewNode->m_Data.getId())
//				{
//					currentNode->m_Left = p_NewNode;
//				}
//				else
//				{
//					currentNode->m_Right = p_NewNode;
//				}
//			}
//		}
//	}
//}
//
//
//
//void BST::deleteNode(int p_Id)
//{
//
//}
//
//bool BST::findeNode(int p_Id, TreeNode*& p_NodeToChange)
//{
//	if (m_Head != nullptr)
//	{
//		p_NodeToChange = findeNodeReq(p_Id, m_Head);
//		if (p_NodeToChange->m_Data.getId() == p_Id)
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//	else
//	{
//		p_NodeToChange = nullptr;
//		return false;
//	}
//}
//
//TreeNode* BST::findeNodeReq(int p_Id, TreeNode* p_Node)
//{
//	if (p_Node->m_Data.getId() == p_Id)
//	{
//		return p_Node;
//	}
//	else
//	{
//		if (p_Node->m_Data.getId() > p_Id)
//		{
//			if (p_Node->m_Left != nullptr)
//			{
//				return findeNodeReq(p_Id, p_Node->m_Left);
//			}
//			else
//			{
//				return p_Node;
//			}
//			
//		}
//		else
//		{
//			if (p_Node->m_Right != nullptr)
//			{
//				return findeNodeReq(p_Id, p_Node->m_Right);
//			}
//			else
//			{
//				return p_Node;
//			}
//		}
//	}
//}
//
//void BST::makeEmpty()
//{
//	m_Head = nullptr;
//}
//
//bool BST::isEmpty(TreeNode* p_Head)
//{
//	if (m_Head == nullptr)
//	{
//		return true;
//	}
//	return false;
//}
//
//
