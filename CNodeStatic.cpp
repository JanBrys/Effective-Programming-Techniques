#include "CNodeStatic.h"

CNodeStatic::CNodeStatic()
{
    i_val = 0;
    pc_parent_node = NULL;
}

CNodeStatic::~CNodeStatic()
{
}

void CNodeStatic::vSetValue(int iNewVal)
{
    i_val = iNewVal;
}

int CNodeStatic::iGetChildrenNumber()
{
    return v_children.size();
}

void CNodeStatic::vAddNewChild()
{
    CNodeStatic child;
    child.pc_parent_node = this;
    v_children.push_back(child);
}

CNodeStatic* CNodeStatic::pcGetChild(int iChildOffset)
{
    if (iChildOffset > iGetChildrenNumber())
    {
        return NULL;
    }
    return &v_children[iChildOffset];
}

void CNodeStatic::vPrint()
{
    cout << " " << i_val;
}

void CNodeStatic::vPrintAllBelow()
{
    vPrint();
    for (int ii = 0; ii < iGetChildrenNumber(); ii++)
    {
        this->pcGetChild(ii)->vPrintAllBelow();
    }
}

void CNodeStatic::vPrintUp()
{
    vPrint();
    if (pc_parent_node != NULL)
    {
        pc_parent_node->vPrintUp();
    }
}
