#pragma once

#include<iostream>
using namespace std;
#include "TreeNode.h"
#include <stdexcept>

#define Left 1
#define Right 2

class BST
{
private:
	TreeNode* m_Root;
	int m_cmpCount;
public:
	BST();
	~BST();
	void Insert(Student* studentToAdd);

	void Delete(int studentIdToDelete);
	TreeNode* Find_ToDelete(int key, TreeNode*& prev);
	void DeleteNodeWithNoChildren(TreeNode* nodeToDelete, TreeNode* prev, int side);
	void DeleteNodeWithOneChild(TreeNode* nodeToDelete, TreeNode* prev, int side);
	void DeleteNodeWithTwoChildren(TreeNode* nodeToDelete, TreeNode* prev, int side);
	bool isOnlyOneChild(TreeNode* nodeToDelete);
	TreeNode* findMaxRightChild(TreeNode* nodeToDeleteLeftChild, TreeNode*& prev);

	void MakeEmpty();
	bool IsEmpty();
	TreeNode* Find(int key);
	void PrintInorderTillK(int k);
	int getComparesCount();

	static int whichSide(TreeNode* prev, TreeNode* node)
	{
		if (prev->m_Right == node)
			return Right;
		return Left;
	}
};







