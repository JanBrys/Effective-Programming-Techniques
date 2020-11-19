#include "CNodeDynamic.h"

CNodeDynamic::CNodeDynamic()
{
	i_val = 0;
	pc_parent_node = NULL;
}

CNodeDynamic::~CNodeDynamic()
{
	for (int ii = 0; ii < iGetChildrenNumber(); ii++)
	{
		delete pcGetChild(ii);
	}
}

void CNodeDynamic::vSetValue(int iNewVal)
{
	i_val = iNewVal;
}

int CNodeDynamic::iGetChildrenNumber()
{
	return v_children.size();
}

void CNodeDynamic::vAddNewChild()
{
	CNodeDynamic* c_child = new CNodeDynamic();
	c_child->pc_parent_node = this;
	v_children.push_back(c_child);
}

CNodeDynamic* CNodeDynamic::pcGetChild(int iChildOffset)
{
	if (iChildOffset > iGetChildrenNumber())
	{
		return NULL;
	}
	return v_children[iChildOffset];
}

void CNodeDynamic::vPrint()
{
	cout << " " << i_val;
}

void CNodeDynamic::vPrintAllBelow()
{
	vPrint();
	for (int ii = 0; ii < iGetChildrenNumber(); ii++)
	{
		this->pcGetChild(ii)->vPrintAllBelow();
	}
}

void CNodeDynamic::vPrintUp()
{
	vPrint();
	if (pc_parent_node != NULL)
	{
		pc_parent_node->vPrintUp();
	}
}
