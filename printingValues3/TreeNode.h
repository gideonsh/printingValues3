#pragma once

#include<iostream>
using namespace std;

#include "Person.h"

class TreeNode
{
private: 

public:
	Person m_Data;
	TreeNode* m_Left;
	TreeNode* m_Right;

	TreeNode* makeNode(int p_Id, char* p_Name);


};










