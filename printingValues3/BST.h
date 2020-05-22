#pragma once

#include<iostream>
using namespace std;
#include "TreeNode.h"

class BST
{
private:
	TreeNode* m_Root;
	int m_cmpCount;
public:
	static enum eSide { Left, Right };
	BST();
	~BST();
	void Insert(Student* studentToAdd);

	void Delete(int studentIdToDelete);
	TreeNode* Find_ToDelete(int key, TreeNode*& prev);
	void DeleteNodeWithOneChild(TreeNode* nodeChild, TreeNode* prev, eSide side);
	bool isOnlyOneChild(TreeNode* nodeToDelete);
	TreeNode* findMaxRightChild(TreeNode* nodeToDeleteLeftChild, TreeNode*& prev);

	void MakeEmpty();
	bool IsEmpty();
	TreeNode* Find(int key);
	void PrintInorder();

	static eSide whichSide(TreeNode* prev, TreeNode* node)
	{
		if (prev->m_Right == node)
			return Right;
		return Left;
	}
};







