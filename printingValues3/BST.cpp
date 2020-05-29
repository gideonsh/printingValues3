#include "BST.h"

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

void BST::Insert(Student* studentToAdd)		//Inserts a node to the tree with Student object.
//-We do not check if the id of the student we want to add exists in our tree already-
//-because we have checked it when we got the students array in the main program.-----
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
	if (parent == nullptr)
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

void BST::Delete(int studentIdToDelete)		//Deletes requested node with the inputted student id to delete.
{
	TreeNode* prev;
	TreeNode* nodeToDelete = Find_ToDelete(studentIdToDelete, prev);
	int side = whichSide(prev, nodeToDelete);
	
	if (nodeToDelete == nullptr)		//Case we did not find the student we want to delete.
	{
		cout << "invalid input" << endl;
		exit(1);
	}
	else
	{
		if (nodeToDelete->m_Left == nullptr && nodeToDelete->m_Right == nullptr)  //Case the node we want to delete has no children.
			DeleteNodeWithNoChildren(nodeToDelete, prev, side);

		else if (isOnlyOneChild(nodeToDelete) == true)	//Case the node we want to delete has one child.
			DeleteNodeWithOneChild(nodeToDelete, prev, side);

		else	//Case the node we want to delete has two children.
			DeleteNodeWithTwoChildren(nodeToDelete, prev, side);
	}
}

TreeNode* BST::Find_ToDelete(int key, TreeNode*& prev)	//Returns the node to delete and by-ref the parent of this node.
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
			m_cmpCount++; // if current is a leaf then we do m_cmpCount++ with no necessery check
		}
	}
	return nullptr;
}

void BST::DeleteNodeWithNoChildren(TreeNode* nodeToDelete, TreeNode* prev, int side)	//Deletes node with no children.
{
	switch (side)
	{
	case Right:
		prev->m_Right = nullptr;
		break;
	case Left:
		prev->m_Left = nullptr;
		break;
	}
	delete nodeToDelete;
}

void BST::DeleteNodeWithOneChild(TreeNode* nodeToDelete, TreeNode* prev, int side) //Deletes a node with single child.
{
	TreeNode* nodeChild;
	if (nodeToDelete->m_Left == nullptr)
	{
		nodeChild = nodeToDelete->m_Right;
		nodeToDelete->m_Right = nullptr;
	}
	else
	{
		nodeChild = nodeToDelete->m_Left;
		nodeToDelete->m_Left = nullptr;
	}

	switch (side)
	{
	case Left:
		prev->m_Left = nodeChild;
		break;

	case Right:
		prev->m_Right = nodeChild;
		break;
	}

	delete nodeToDelete;
}

void BST::DeleteNodeWithTwoChildren(TreeNode* nodeToDelete, TreeNode* prev, int side)	//Deletes node with two children.
{
	TreeNode* MaxRightInLeftSubTree = findMaxRightChild(nodeToDelete, prev);//Find max right child.
	TreeNode::swap(MaxRightInLeftSubTree, nodeToDelete);					//Swap v and r.
	side = whichSide(prev, MaxRightInLeftSubTree);							//Find side.

	if (MaxRightInLeftSubTree->m_Left == nullptr && MaxRightInLeftSubTree->m_Right == nullptr)
		DeleteNodeWithNoChildren(MaxRightInLeftSubTree, prev, side);	//Case r node has no children.
	else
		DeleteNodeWithOneChild(MaxRightInLeftSubTree, prev, side);		//Case r node has one child.
}

bool BST::isOnlyOneChild(TreeNode* nodeToDelete)	//Checks if the requested node to delete has single child.
{
	if ((nodeToDelete->m_Left == nullptr && nodeToDelete->m_Right != nullptr) ||
		(nodeToDelete->m_Left != nullptr && nodeToDelete->m_Right == nullptr))
		return true;
	return false;
}

TreeNode* BST::findMaxRightChild(TreeNode* nodeToDelete, TreeNode*& prev)	//Returns biggest right child in left sub-tree.
{
	TreeNode* p = nullptr;
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

void BST::MakeEmpty()	//Makes an empty tree.
{
	if (m_Root != nullptr)
		delete m_Root;
	m_Root = nullptr;
}

bool BST::IsEmpty()		//Checks if the tree is empty.
{
	return (m_Root == nullptr);
}

TreeNode* BST::Find(int key)	//Finds the requested treenode with the requested key if exsits.
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
		m_cmpCount++; // if current is a leaf then we do m_cmpCount++ with no necessery check
	}
	return nullptr;
}

void BST::PrintInorderTillK(int k)	//Prints the tree inorder till gets to k.
{
	bool stop = false;
	if (m_Root != nullptr)
		m_Root->Inorder(k, stop, m_cmpCount);
}

int BST::getComparesCount()
{
	return m_cmpCount;
}
