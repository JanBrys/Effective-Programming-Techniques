#pragma once
#include <vector>
#include <iostream>

using namespace std;

class CTreeDynamic
{
private:
	class CNodeDynamic
	{
	public:
		CNodeDynamic();
		~CNodeDynamic();

		void vSetValue(int iNewVal);

		int iGetChildrenNumber();
		void vAddNewChild();
		CNodeDynamic* pcGetChild(int iChildOffset);

		void vPrint();
		void vPrintAllBelow();
		void vPrintUp();
		void addSpecifiedChild(CNodeDynamic* newChild);
		void untrackChild();
	private:

		vector<CNodeDynamic*> v_children;
		CNodeDynamic* pc_parent_node;
		int i_val;
	};
public:
	CTreeDynamic();
	~CTreeDynamic();
	CNodeDynamic* pcGetRoot();
	void vPrintTree();
	bool bMoveSubtree(CNodeDynamic *pcParentNode,CNodeDynamic *pcNewChildNote);
private:
	CNodeDynamic* c_root;
};

