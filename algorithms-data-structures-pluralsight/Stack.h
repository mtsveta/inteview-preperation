struct Node{
	int data;
	Node* next;
};
// using linked list
class Stack
{	
	Node* head;
	int count;
	
public:
		Stack():head(nullptr), count(0){};
		
		void printStack() const;
		int getCount() const {return count;}

		void push(int value); // 0(1)
		void pop(); // 0(1)
};


class EmptyStack : public std::exception {

	virtual const char* what() const throw ()
	{
		return "The stack is empty";
	}

};
// O()
void Stack::printStack() const {
	std::cout << "list with " << getCount() << " elements:\t";
	for (Node* p = head; p != nullptr; p = p->next){
		std::cout << p->data << " -> ";
	}
	std::cout << "null" << std::endl;
}
// O(1)
// adding elemnt to the head of the list
void Stack::push(int value){
	Node* new_elem = new Node{value, nullptr};
	new_elem->next = head;
	head = new_elem;
	count++;
}
// 0(1)
// removing elemnt from the head of the list
void Stack::pop(){
	if (count){
		Node* rem_elem = head;
		if (count == 1){
			head = nullptr;
		}
		else{
			head = rem_elem->next;
		}
		delete rem_elem;

		count--;
	}else{
		throw std::out_of_range("Stack<>::top(): empty stack");
		// std::cout << "Error in poping the value from: stack is empty!" << std::endl;
	}
}