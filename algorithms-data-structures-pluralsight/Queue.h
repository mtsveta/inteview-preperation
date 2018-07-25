#pragma once
#include <iostream>

struct Node{
	int data;
	Node* next;
};
// using linked list
class Queue
{	
	Node* head;
	Node* tail;
	int count;
	
public:
		Queue():head(nullptr), tail(nullptr), count(0){};
		
		void Print() const;
		int GetCount() const {return count;}

		void Enqueue(int value); // 0(1)
		void Dequeue(); 	// 0(1)
};

// O()
void Queue::Print() const {
	std::cout << "list with " << GetCount() << " elements:\t";
	for (Node* p = head; p != nullptr; p = p->next){
		std::cout << p->data << " -> ";
	}
	std::cout << "null" << std::endl;
}

// O(1)
void Queue::Enqueue(int value){
	Node* new_elem = new Node{value, nullptr};
	if (tail){
		tail->next = new_elem;
	}
	tail = new_elem;
	count++;

	// if the list was empty then head and tail are poiting to the same element
	if (count == 1)
		head = tail;
}

void Queue::Dequeue(){
	if (count){
		// limit case: p is the last element
		Node* rem_elem = head;	
		Node* next_elem = rem_elem->next;	
		head = next_elem;
		
		delete rem_elem;
		count--;
	}else{
		std::cout << "Queque is empty" << std::endl;
	}
}