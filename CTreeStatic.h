#pragma once
#include <vector>
#include <iostream>
using namespace std;
class CTreeStatic
{
private:
	class CNodeStatic
	{
	public:
		CNodeStatic();
		~CNodeStatic();

		void vSetValue(int iNewVal);

		int iGetChildrenNumber();
		void vAddNewChild();
		CTreeStatic::CNodeStatic* pcGetChild(int iChildOffset);

		void vPrint();
		void vPrintAllBelow();
		void vPrintUp();

	private:

		vector <CNodeStatic> v_children;
		CNodeStatic* pc_parent_node;
		int i_val;
	};
public:
	CTreeStatic();
	~CTreeStatic();
	CNodeStatic* pcGetRoot();
	void vPrintTree();
	bool moveSubtree(CNodeStatic* pcParentNode, CNodeStatic* pcNewChildNote);
	
private:

	CNodeStatic c_root;
	
};

