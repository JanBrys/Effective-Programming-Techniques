#pragma once
#include <vector>
#include <iostream>
using namespace std;

class CNodeStatic
{
public:
	CNodeStatic();
	~CNodeStatic();

	void vSetValue(int iNewVal);

	int iGetChildrenNumber();
	void vAddNewChild();
	CNodeStatic* pcGetChild(int iChildOffset);

	void vPrint();
	void vPrintAllBelow();
	void vPrintUp();

private:

	vector <CNodeStatic> v_children;
	CNodeStatic* pc_parent_node;
	int i_val;
};

