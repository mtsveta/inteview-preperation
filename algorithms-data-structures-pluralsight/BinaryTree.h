#include <iostream>
using std::cout;
using std::endl;


struct Node{
	int data;
	Node* left;
	Node* right;
};

class BinaryTree{

	private:

		Node* head;
		int count;

	public:

		BinaryTree() : head(nullptr), count(0) {};

		int GetCount() const {return count;}
	    Node* FindWithParent(int value, Node*& parent);
		bool Contains(int value);

		void Add(int value);
		void AddTo(Node* node, int value);

		bool Remove(int value);

		// Printing and traversing the tree
		void PostOrderTraversal(Node* node) const;
		void PreOrderTraversal(Node* node) const;
		void InOrderTraversal(Node* node) const;
		void Print() const;
};

// ---------------------------------------------------------------------------------------------------------
// Searching on the BinaryTree
// ---------------------------------------------------------------------------------------------------------
// Returns the node (Node*) containing the specified value
// Returns nullptr, if the value is not found 
/*
Schematic code
Node* BinaryTree::Find(Node* curr, int value) const{
	
	if (curr == nullptr)		// condition that we will meet in the bottom leafs of the tree
		return nullptr; 		
	if (curr.data == value)		// return current element
		return curr;		    
	if (value < curr.data)		// value we are searching in the left sub-tree			
		return Find(curr.left, value); 	
	else 						// value we are searching in the right sub-tree
		return Find(curr.right, value);

}
*/

// Determins if the specified value exists in a tree
bool BinaryTree::Contains(int value) {
	// 'depends on' node-search function
	Node* parent;
	// function FindWithParent(value, parent) will return Node* and will change the pointer to the parent
	// if search is successful then the returned pointer not nullptr
	return FindWithParent(value, parent) != nullptr;
}

// Finds and returns the node (Node*) containing the specified value
// Returns nullptr, if the value is not found 
// Returns the parent of the found node (or null) used in Remove
Node* BinaryTree::FindWithParent(int value, Node*& parent){
	Node* curr = head;
	parent = nullptr; // case when the curr is the head, there is no parrent

	// Run traverse through the tree
	while(curr != nullptr){

		// value == curr->data - we've found the match
		if (value == curr->data){
			break;
		}
		// othewise there two cases: value < curr.value or value > curr.value
		else{

			// current element becomes the parent
			parent = curr;
			// case 1: if the value < then value of the curr -> move to the left-child
			if (value < curr->data)			
				curr = curr->left;
			// case 2: if the value > then value of the curr -> move to the right-child
			else {
				curr = curr->right;
			}
		}
	}
	return curr;
}
// ---------------------------------------------------------------------------------------------------------
// Adding into the BinaryTree
// ---------------------------------------------------------------------------------------------------------
void BinaryTree::Add(int value){
	// if the head is empty -> put the value there
	if (head == nullptr){
	 	head = new Node{value, nullptr, nullptr};
	}
	else	// if the head is not empty -> add to new value to this BinaryTree
		AddTo(head, value);
	count++;
}

void BinaryTree::AddTo(Node* node, int value){
	// case 1: if the value is < than the node value
	if (node != nullptr && value < node->data){ 
		// if the left-child is empty, we create there a new leaf
		if (!node->left)
			node->left = new Node{value, nullptr, nullptr};
		// otherwise, we add a value into this left-child
		else
			AddTo(node->left, value);
	}
	// case 2: if the value is >= than node value
	else {
		// if the right-child is empty, we create there a new leaf
		if (!node->right)
			node->right = new Node{value, nullptr, nullptr};
		// otherwise, we add a value into this right-child
		else
			AddTo(node->right, value);
	}
}
// ---------------------------------------------------------------------------------------------------------
// Remove element
// ---------------------------------------------------------------------------------------------------------
// Removes first occurences of the specified element 
// Returns true, if the value is removed
// Returns false, otherwise

/*
// Help function
void BinaryTree::ConnectParentWithNewCurr(Node* curr, Node* prom, Node* parent){
	// If we are deleting the head 
	if (parent == nullptr) 
		head = prom;
	else{
		// if the parent is greater then the curr => curr is its the left-child
		if (parent->data > curr->data)
			parent->left = prom;
		// if the parent is smaler then the curr => curr is its the right-child
		else if (parent->data < curr->data)
			parent->right = prom;
	}	
}
*/

		
bool BinaryTree::Remove(int value){

	Node* curr;
	Node* parent;

	// Search for the element to be removed
	curr = FindWithParent(value, parent);
	cout << "value " << curr->data << " if found!" << endl;

	// If element is not found => return false
	if (curr == nullptr)
		return false;
	// Decrease the counter of total elements
	count --;

	// Node to be removed
	Node* rem = curr;
		
	// Case 1: 
	// If the curr has NO Right Child
	// its Left Child (curr->left) replaces it 
	if (curr->right == nullptr){

		// Element to be promoted is curr->left element
		Node* prom = curr->left;

		// if we are deleting the head 
		if (parent == nullptr) 
			head = prom;
		else{
			// if the parent is greater then the curr => curr is its the left-child
			if (parent->data > curr->data)
				parent->left = prom;
			// if the parent is smaler then the curr => curr is its the right-child
			else if (parent->data < curr->data)
				parent->right = prom;
		}	
	}
		// Case 2:
	// If the curr has Right Child, which has NO Left Child
	// Right Child (curr->right) replaces it 
	else if (curr->right->left == nullptr){

		// We more the whole curr-left branch there, so that we don't lose it 
		curr->right->left = curr->left;
		
		// Element to be promoted is curr->left element
		Node* prom = curr->right;
		
		// If we are deleting the head 
		if (parent == nullptr) 
			head = prom;
		else{
			// if the parent is greater then the curr => curr is its the left-child
			if (parent->data > curr->data)
				parent->left = prom;
			// if the parent is smaler then the curr => curr is its the right-child
			else if (parent->data < curr->data)
				parent->right = prom;
		}	

	}
	// Case 3:
	// If the curr has Right Child which has Left Child 
	// the most Left Child of this Right Child replaces it
	else{
		// 1st, we have to search the node to promote - the most Left of this Right Chil
		// curr->right->left != nullptr
		Node* prom = curr->right->left; 
		Node* promParent = curr->right;

		while (prom->left != nullptr){
			promParent = prom; // prom become a new patern
			prom = prom->left; // and we are moving to the next left child
		}
		
		// 2st, if the we came to a point that prom->left == nullptr
		//                                 but prom->right != nullptr
		// => we make it as new left leaf for promPatern 
		promParent->left = prom->right;

		// 3st, reassing left and right of the prom emement 
		prom->left = curr->left;
		prom->right = curr->right;

		// 4th, making sure that we connect this prom element with parent:

		// To replace repeating code: 
		// ConnectParentWithNewCurr(curr, prom, parent);
		// If we are deleting the head 
		if (parent == nullptr) 
			head = prom;
		else{
			// if the parent is greater then the curr => curr is its the left-child
			if (parent->data > curr->data)
				parent->left = prom;
			// if the parent is smaler then the curr => curr is its the right-child
			else if (parent->data < curr->data)
				parent->right = prom;
		}	
	}
	delete rem;
	return true;
}

// ---------------------------------------------------------------------------------------------------------
// Traversals
// ---------------------------------------------------------------------------------------------------------
 
void BinaryTree::PreOrderTraversal(Node* node) const {

	if (node != nullptr){
		std::cout << node->data << " ";
		PreOrderTraversal(node->left);
		PreOrderTraversal(node->right);
	}
}
void BinaryTree::PostOrderTraversal(Node* node) const {

	if (node != nullptr){
		PostOrderTraversal(node->left);
		PostOrderTraversal(node->right);
		std::cout << node->data << " ";		
	}
}
void BinaryTree::InOrderTraversal(Node* node) const {

	if (node != nullptr){
		InOrderTraversal(node->left);
		std::cout << node->data << " ";		
		InOrderTraversal(node->right);
	}
}

void BinaryTree::Print() const{
	BinaryTree::InOrderTraversal(head);
	std::cout << std::endl;

}
