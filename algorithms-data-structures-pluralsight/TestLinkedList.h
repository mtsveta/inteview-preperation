#include "LinkedList.h"
#include "DoublyLinkedList.h"

// example how to return changed head
void addToHead(Node* & head, Node elem){
	Node* new_elem = new Node{elem.data, nullptr};
	new_elem->next = head;
	head = new_elem;
}
// 
void printList(Node* & head){
	for (auto p = head; p != nullptr; p = p->next)
		std::cout << p->data << " -> ";
	std::cout << "null" << std::endl;
}
void TestLinkedList()
{
	// Single linked list
	// -------------------------------------------------------------------------------
	// Advantages over an array:
	// - dynamic size
	// - useful for implementing stack and queue, since insertion and deletion is 0(1)
	// - insertion O(1) 
	// - deletion of the current element 0(1) vs. array 0(n)
	// - deletion after/before an element 0(1)

	// Drawbacks:
	// - no random access, only sequentially (binary search is impossible)
	// - extra memory for the pointer on the element is requires

	// chain of the elements
	Node elem1{3, nullptr};
	Node elem2{5, nullptr};
	Node elem3{7, nullptr};
	Node elem4{21, nullptr};

	Node* list{};
	addToHead(list, elem2);
    printList(list);

	addToHead(list, elem3);
    printList(list);

	addToHead(list, elem3);
	printList(list);


	// -------------------------------------------------------------------------------
	// Initialising and filling out the list
	LinkedList linkedlist;
	linkedlist.addToHead(4);
	linkedlist.printList();
	linkedlist.addToHead(5);
	linkedlist.printList();
	linkedlist.addToTail(16);
	linkedlist.printList();
	linkedlist.addToTail(21);
	linkedlist.printList();

	// -------------------------------------------------------------------------------
	// Searching for the target element

	int target = 6;
	Node* result = linkedlist.searchFor(target);
	if (result) std::cout << "element " << target << " is found" << std::endl;
	else std::cout << "element " << target << "is not found" << std::endl;

	// -------------------------------------------------------------------------------
	// Searching for the target element and removing element after it
	
	target = 5;
	result = linkedlist.searchFor(target);
	if (result){
		linkedlist.removeAfter(result);
		std::cout << "after removing " << target << std::endl; 
		linkedlist.printList();
	}
	else std::cout << "element " << target << "is not found" << std::endl;

	// -------------------------------------------------------------------------------
	// Searching for the target element and adding element after it

	target = 21;
	result = linkedlist.searchFor(target);
	if (result){
		linkedlist.addAfter(result, 100);
		std::cout << "after adding " << target << std::endl; 
		linkedlist.printList();
	}
	else std::cout << "element " << target << "is not found" << std::endl;

	// -------------------------------------------------------------------------------
	// Getting the value in the head 
	std::cout << "head of the list " << linkedlist.getHead()->data << std::endl;
	
	// -------------------------------------------------------------------------------
	// Getting the value in the tail 
	std::cout << "tail of the list " << linkedlist.getTail()->data << std::endl;
	
	// -------------------------------------------------------------------------------
	// Removing last element
	linkedlist.removeLast();
	std::cout << "after removing last element " << std::endl; 
	linkedlist.printList();

	// -------------------------------------------------------------------------------
	// Removing first element
	linkedlist.removeFirst();
	std::cout << "after removing first element " << std::endl; 
	linkedlist.printList();
}