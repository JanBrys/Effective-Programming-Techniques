#include "CTreeDynamic.h"

CTreeDynamic::CNodeDynamic::CNodeDynamic()
{
	i_val = 0;
	pc_parent_node = NULL;
}

CTreeDynamic::CNodeDynamic::~CNodeDynamic()
{
	if (iGetChildrenNumber() != 0)
	{
		for (int ii = 0; ii < iGetChildrenNumber(); ii++)
		{
			pcGetChild(ii)->pc_parent_node = NULL;
			delete pcGetChild(ii);
		}
	}
	else
	{
		pc_parent_node = NULL;
	}
}



void CTreeDynamic::CNodeDynamic::vSetValue(int iNewVal)
{
	i_val = iNewVal;
}

int CTreeDynamic::CNodeDynamic::iGetChildrenNumber()
{
	return v_children.size();
}

void CTreeDynamic::CNodeDynamic::vAddNewChild()
{
	CNodeDynamic* c_child = new CNodeDynamic();
	c_child->pc_parent_node = this;
	v_children.push_back(c_child);
}

CTreeDynamic::CNodeDynamic* CTreeDynamic::CNodeDynamic::pcGetChild(int iChildOffset)
{
	if (iChildOffset > iGetChildrenNumber())
	{
		return NULL;
	}
	return v_children[iChildOffset];
}

void CTreeDynamic::CNodeDynamic::vPrint()
{
	cout << " " << i_val;
}

void CTreeDynamic::CNodeDynamic::vPrintAllBelow()
{
	if (iGetChildrenNumber() == 0)
	{
		vPrint();
	}
	else
	{
		this->vPrint();
		for (int ii = 0; ii < iGetChildrenNumber(); ii++)
		{
			this->pcGetChild(ii)->vPrintAllBelow();
		}
	}
}
void CTreeDynamic::CNodeDynamic::vPrintUp()
{
	vPrint();
	if (pc_parent_node != NULL)
	{
		pc_parent_node->vPrintUp();
	}
}

void CTreeDynamic::CNodeDynamic::addSpecifiedChild(CNodeDynamic* newChild)
{
	v_children.push_back(newChild);
}

void CTreeDynamic::CNodeDynamic::untrackChild()
{
	for (int ii = 0; ii < pc_parent_node->iGetChildrenNumber(); ii++)
	{
		if (pc_parent_node->pcGetChild(ii) == this)
		{
			pc_parent_node->v_children.erase(pc_parent_node->v_children.begin()+ii);
		}
	}
}

CTreeDynamic::CTreeDynamic()
{
	c_root = new CNodeDynamic();
}

CTreeDynamic::~CTreeDynamic()
{
	delete c_root;
}

CTreeDynamic::CNodeDynamic* CTreeDynamic::pcGetRoot()
{
	return c_root;
}

void CTreeDynamic::vPrintTree()
{
	pcGetRoot()->vPrintAllBelow();
}

bool CTreeDynamic::bMoveSubtree(CNodeDynamic* pcParentNode, CNodeDynamic* pcNewChildNote)
{
	pcParentNode->addSpecifiedChild(pcNewChildNote);
	pcNewChildNote->untrackChild();
	return true;
}
