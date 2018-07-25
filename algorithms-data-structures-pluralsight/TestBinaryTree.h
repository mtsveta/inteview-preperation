#include "BinaryTree.h"

void TestBinaryTree(){
	
	BinaryTree tree;
	/*
	// test of the Case 1 for the removing
	tree.Add(4);
	tree.Add(2);
	tree.Add(1);
	tree.Add(3);
	tree.Add(8);
	tree.Add(6);
	tree.Add(7);
	tree.Add(5);
	 */

	/*
	// test of the Case 2 for the removing
	tree.Add(4);
	tree.Add(2);
	tree.Add(1);
	tree.Add(3);
	tree.Add(6);
	tree.Add(7);
	tree.Add(5);
	tree.Add(8);
 	*/
 	// test of the Case 3 for the removing
	tree.Add(4);
	tree.Add(2);
	tree.Add(1);
	tree.Add(3);
	tree.Add(6);
	tree.Add(5);
	tree.Add(8);
	tree.Add(7);
	
	//std::cout << "Does tree constains 8? " << tree.Contains(8) << endl;
	if (tree.Remove(8))
		std::cout << "8 was removed" << endl;
		
	tree.Print();
	
}