#include "CTreeStatic.h"
//#include "CNodeStatic.h"
#include "CTreeDynamic.h"
#include "CNodeDynamic.h"
int main()
{

	//													STATIC NODE
	/*
		CNodeStatic c_root;
	CNodeStatic* c_null = c_root.pcGetChild(1);
	delete c_null;
	c_root.vAddNewChild();
	c_root.vAddNewChild();

	c_root.pcGetChild(0)->vSetValue(1);
	c_root.pcGetChild(1)->vSetValue(2);

	c_root.pcGetChild(0)->vAddNewChild();
	c_root.pcGetChild(0)->vAddNewChild();

	c_root.pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	c_root.pcGetChild(0)->pcGetChild(1)->vSetValue(12);

	c_root.pcGetChild(1)->vAddNewChild();
	c_root.pcGetChild(1)->vAddNewChild();

	c_root.pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	c_root.pcGetChild(1)->pcGetChild(1)->vSetValue(22);
	cout << "vPrint() dla kazdego wezla w drzewie" << endl;
	c_root.vPrint();
	c_root.pcGetChild(0)->vPrint();
	c_root.pcGetChild(0)->pcGetChild(0)->vPrint();
	c_root.pcGetChild(0)->pcGetChild(1)->vPrint();

	c_root.pcGetChild(1)->vPrint();
	c_root.pcGetChild(1)->pcGetChild(0)->vPrint();
	c_root.pcGetChild(1)->pcGetChild(1)->vPrint();

	cout << endl << endl << "vPrintAllBelow()" << endl;
	c_root.vPrintAllBelow();

	cout << endl << endl << "vPrintUp()" << endl;
	c_root.pcGetChild(0)->pcGetChild(1)->vPrintUp();
	*/

	//													STATIC TREE

	/*
		CTreeStatic c_tree;
	c_tree.pcGetRoot()->vAddNewChild();
	c_tree.pcGetRoot()->vAddNewChild();

	c_tree.pcGetRoot()->pcGetChild(0)->vSetValue(1);
	c_tree.pcGetRoot()->pcGetChild(1)->vSetValue(2);

	c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();

	c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);

	c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();

	c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22);
	cout << "vPrint() dla kazdego wezla w drzewie" << endl;
	c_tree.pcGetRoot()->vPrint();
	c_tree.pcGetRoot()->pcGetChild(0)->vPrint();
	c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vPrint();
	c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vPrint();

	c_tree.pcGetRoot()->pcGetChild(1)->vPrint();
	c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vPrint();
	c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vPrint();

	cout << endl << endl << "vPrintAllBelow()" << endl;
	c_tree.pcGetRoot()->vPrintAllBelow();

	cout << endl << endl << "vPrintUp()" << endl;
	c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vPrintUp();
	*/

	//													DYNAMIC NODE

	/*
	CNodeDynamic c_root;
	c_root.vAddNewChild();
	c_root.vAddNewChild();

	c_root.pcGetChild(0)->vSetValue(1);
	c_root.pcGetChild(1)->vSetValue(2);

	c_root.pcGetChild(0)->vAddNewChild();
	c_root.pcGetChild(0)->vAddNewChild();

	c_root.pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	c_root.pcGetChild(0)->pcGetChild(1)->vSetValue(12);

	c_root.pcGetChild(1)->vAddNewChild();
	c_root.pcGetChild(1)->vAddNewChild();

	c_root.pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	c_root.pcGetChild(1)->pcGetChild(1)->vSetValue(22);
	cout << "vPrint() dla kazdego wezla w drzewie" << endl;
	c_root.vPrint();
	c_root.pcGetChild(0)->vPrint();
	c_root.pcGetChild(0)->pcGetChild(0)->vPrint();
	c_root.pcGetChild(0)->pcGetChild(1)->vPrint();

	c_root.pcGetChild(1)->vPrint();
	c_root.pcGetChild(1)->pcGetChild(0)->vPrint();
	c_root.pcGetChild(1)->pcGetChild(1)->vPrint();

	cout << endl << endl << "vPrintAllBelow()" << endl;
	c_root.vPrintAllBelow();

	cout << endl << endl << "vPrintUp()" << endl;
	c_root.pcGetChild(0)->pcGetChild(1)->vPrintUp();
	*/

	//											DYNAMIC TREE

	/*
	CTreeDynamic c_tree;
	c_tree.pcGetRoot()->vAddNewChild();
	c_tree.pcGetRoot()->vAddNewChild();

	c_tree.pcGetRoot()->pcGetChild(0)->vSetValue(1);
	c_tree.pcGetRoot()->pcGetChild(1)->vSetValue(2);

	c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();

	c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);

	c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();

	c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22);
	cout << "vPrint() dla kazdego wezla w drzewie" << endl;
	c_tree.pcGetRoot()->vPrint();
	c_tree.pcGetRoot()->pcGetChild(0)->vPrint();
	c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vPrint();
	c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vPrint();

	c_tree.pcGetRoot()->pcGetChild(1)->vPrint();
	c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vPrint();
	c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vPrint();

	cout << endl << endl << "vPrintAllBelow()" << endl;
	c_tree.pcGetRoot()->vPrintAllBelow();

	cout << endl << endl << "vPrintUp()" << endl;
	c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vPrintUp();
	*/
	
	
	
}
