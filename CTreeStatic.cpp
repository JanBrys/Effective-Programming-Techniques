#include "CTreeStatic.h"

CTreeStatic::CNodeStatic::CNodeStatic()
{
    i_val = 0;
    pc_parent_node = NULL;
}

CTreeStatic::CNodeStatic::~CNodeStatic()
{
    if (iGetChildrenNumber() != 0)
    {
        for (int ii = 0; ii < iGetChildrenNumber(); ii++)
        {
            pcGetChild(ii)->pc_parent_node = NULL;
        }
    }
}

void CTreeStatic::CNodeStatic::vSetValue(int iNewVal)
{
    i_val = iNewVal;
}

int CTreeStatic::CNodeStatic::iGetChildrenNumber()
{
    return v_children.size();
}

void CTreeStatic::CNodeStatic::vAddNewChild()
{
    CNodeStatic c_child;
    c_child.pc_parent_node = this;
    v_children.push_back(c_child);
}

CTreeStatic::CNodeStatic* CTreeStatic::CNodeStatic::pcGetChild(int iChildOffset)
{
    if (iChildOffset > iGetChildrenNumber())
    {
        return NULL;
    }
    return &v_children[iChildOffset];
}

void CTreeStatic::CNodeStatic::vPrint()
{
    cout << " " << i_val;
}

void CTreeStatic::CNodeStatic::vPrintAllBelow()
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

void CTreeStatic::CNodeStatic::vPrintUp()
{
    vPrint();
    if (pc_parent_node != NULL)
    {
        pc_parent_node->vPrintUp();
    }
}

CTreeStatic::CTreeStatic()
{
}

CTreeStatic::~CTreeStatic()
{
}

CTreeStatic::CNodeStatic* CTreeStatic::pcGetRoot()
{
    return &c_root;
}

void CTreeStatic::vPrintTree()
{
    pcGetRoot()->vPrintAllBelow();
}
