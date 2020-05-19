#pragma once

#include<iostream>
using namespace std;

#include "Student.h"

class TreeNode
{
private: 

public:
	Student* m_Data;
	TreeNode* m_Left;
	TreeNode* m_Right;

	TreeNode* makeTreeNode(Student p_Student);
	TreeNode* findTreeNode();


};










