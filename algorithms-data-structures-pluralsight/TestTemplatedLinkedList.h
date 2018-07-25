#include "LinkedListT.h"

void TestTemplatedLinkedList(){
	
	LinkedList<std::string> words;
	words.AddToHead("cat");
	words.AddToTail("dog");
	words.AddToTail("mouse");
	words.Print();

	auto result = words.SearchFor("mouse");
	std::cout << "search result: " << result->data << std::endl;

	Node<std::string>* prev;
	result = words.SearchForWithPrev("dog", prev);
	std::cout << "search result: " << result->data << std::endl;
	std::cout << "pred: " << ((prev != nullptr) ? prev->data : 0) << std::endl;
	
	words.Empty();

}