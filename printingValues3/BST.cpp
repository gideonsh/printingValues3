#include "BST.h"
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

BST::BST()
{
	m_Root = nullptr;
	m_cmpCount = 0;
}

BST::~BST()
{
	delete m_Root;
	m_Root = nullptr;
}

void BST::Insert(Student* studentToAdd)
//We do not check if the id of the student we want to add exists in our tree already
//because we have checked it when we got the students array in the main program.
{
	TreeNode* temp = m_Root;
	TreeNode* parent = nullptr;
	TreeNode* newNode;

	while (temp != nullptr)
	{
		m_cmpCount++;
		parent = temp;
		if (studentToAdd->getId() < temp->m_Key)
			temp = temp->m_Left;
		else
			temp = temp->m_Right;
	}

	newNode = new TreeNode(studentToAdd, nullptr, nullptr);
	if (parent = nullptr)
		m_Root = newNode;
	else
	{
		m_cmpCount++;
		if (studentToAdd->getId() < parent->m_Key)
			parent->m_Left = newNode;
		else
			parent->m_Right = newNode;
	}
}

void BST::Delete(int studentIdToDelete)
{
	TreeNode* prev;
	TreeNode* nodeToDelete = Find_ToDelete(studentIdToDelete, prev);
	eSide side = whichSide(prev, nodeToDelete);
	
	if (nodeToDelete == nullptr)		//Case we did not find the student we want to delete.
	{
		cout << "invalid input" << endl;
		exit(1);
	}
	else
	{
		if (isOnlyOneChild(nodeToDelete) == true)
		{
			if (nodeToDelete->m_Left == nullptr)	//Sends right child for connections.
				DeleteNodeWithOneChild(nodeToDelete->m_Right, prev, side);

			else									//Sends left child for connections.
				DeleteNodeWithOneChild(nodeToDelete->m_Left, prev, side);
		}
		else
		{
			//Case the node we want to delete has two children.
			TreeNode* MaxRightInLeftSubTree = findMaxRightChild(nodeToDelete->m_Left, prev);//Find max right child.
			TreeNode::swap(MaxRightInLeftSubTree, nodeToDelete);							//Swap v and r.
			side = whichSide(prev, MaxRightInLeftSubTree);									//Find side.
			DeleteNodeWithOneChild(MaxRightInLeftSubTree->m_Left, prev, side);				//Delete r node.
		}
	}
}

void BST::MakeEmpty()
{
	if (m_Root != nullptr)
		delete m_Root;
	m_Root = nullptr;
}

bool BST::IsEmpty()
{
	return (m_Root == nullptr);
}

TreeNode* BST::Find(int key)
{
	TreeNode* current = m_Root;
	while (current != nullptr)
	{
		m_cmpCount++;
		if (key == current->m_Key)
			return current;
		else if (key < current->m_Key)
			current = current->m_Left;
		else
			current = current->m_Right;
		m_cmpCount++;
	}
	return nullptr;
}

TreeNode* BST::Find_ToDelete(int key, TreeNode*& prev)
{
	TreeNode* current = m_Root;
	TreeNode* p = nullptr;

	while (current != nullptr)
	{
		m_cmpCount++;
		if (current->m_Key == key)
		{
			prev = p;
			return current;
		}
		else
		{
			p = current;
			if (key < current->m_Key)
				current = current->m_Left;
			else
				current = current->m_Right;
			m_cmpCount++;
		}
	}
	return nullptr;
}

void BST::DeleteNodeWithOneChild(TreeNode* nodeChild, TreeNode* prev, eSide side)
{
	switch(side)
	{
		case Left:
			prev->m_Left = nodeChild;
			delete prev->m_Left;
			break;

		case Right:
			prev->m_Right = nodeChild;
			delete prev->m_Right;
			break;
	}
}

bool BST::isOnlyOneChild(TreeNode* nodeToDelete)
{
	if ((nodeToDelete->m_Left == nullptr && nodeToDelete->m_Right != nullptr) ||
		(nodeToDelete->m_Left != nullptr && nodeToDelete->m_Right == nullptr))
		return true;
	return false;
}

TreeNode* BST::findMaxRightChild(TreeNode* nodeToDelete, TreeNode*& prev)
{
	TreeNode* p;
	TreeNode* current = nodeToDelete->m_Left;
	if (current->m_Right == nullptr)
		prev = nodeToDelete;
	else
	{
		while (current->m_Right != nullptr)
		{
			p = current;
			current = current->m_Right;
		}
		prev = p;
	}
	return current;
}

void BST::PrintInorder()
{
	if (m_Root != nullptr)
		m_Root->Inorder();
}
