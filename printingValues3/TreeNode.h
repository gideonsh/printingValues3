#pragma once
#include<iostream>
using namespace std;

#include "Student.h"

class TreeNode
{
private:
	int m_Key;
	Student* m_Data;
	TreeNode* m_Left;
	TreeNode* m_Right;
public:
	TreeNode();
	TreeNode(Student* data, TreeNode* left, TreeNode* right);
	TreeNode(const TreeNode& other) = delete;
	~TreeNode();

	void Inorder(int k, bool& stop, int& cmpCount);
	const TreeNode& operator=(const TreeNode& other)
	{
		if (this != &other)
		{
			m_Data = other.m_Data;
			m_Key = other.m_Key;
		}
		return *this;
	}
	static void swap(TreeNode* a, TreeNode* b)
	{
		TreeNode temp;
		temp = *a;
		*a = *b;
		*b = temp;
	}

	friend class BST;
};










