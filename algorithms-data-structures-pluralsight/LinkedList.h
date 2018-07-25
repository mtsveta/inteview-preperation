#pragma once
#include <iostream>


struct Node{
	int data;
	Node* next;
};
// single chain of nodes(lists)
class LinkedList{
	Node* head;
	Node* tail;
	int count;

	public:
		LinkedList():head(nullptr), tail(nullptr), count(0){};
		LinkedList(Node* h, Node* t) : head(h), tail(t) {count++;};

		void printList() const;
		int getCount() const {return count;}
		Node* getHead() const {return head;};
		Node* getTail() const {return tail;};
		
		void addToHead(int value); // 0(1)
		void addToTail(int value); // 0(1)
		Node* searchFor(int value); // 0(n)
		void removeAfter(Node* p); // 0(1)
		void removeLast(); // 0(1)
		void removeFirst(); // 0(1)
		void addAfter(Node* p, int val); // 0(1)
		void addBefore(Node* p, int val); // 0(1)
};

void swapData(Node* elem1, Node* elem2){
	int tmp_val = elem1->data;
	elem1->data = elem2->data;
	elem2->data = tmp_val;
}
// O()
void LinkedList::printList() const {
	std::cout << "list with " << getCount() << " elements:\t";
	for (Node* p = head; p != nullptr; p = p->next){
		std::cout << p->data << " -> ";
	}
	std::cout << "null" << std::endl;
}
// O(1)
void LinkedList::addToHead(int value){
	Node* new_elem = new Node{value, nullptr};
	new_elem->next = head;
	head = new_elem;
	count++;

	// if the list was empty then head and tail are poiting to the same element
	if (count == 1)
		tail = head;

}
// O(1)
void LinkedList::addToTail(int value){
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

Node* LinkedList::searchFor(int value){
	for (Node* p = head; p != nullptr; p = p->next){
		if (p->data == value)
			return p;
	}
	return nullptr;
}

void LinkedList::removeAfter(Node* p){
	// limit case: p is the last element
	if (p->next == nullptr)
		std::cout << p->data << " is the last element => nothing to remove" << std::endl;
	else{
		Node* rem_elem = p->next;		
		Node* new_next = p->next->next;
		p->next = new_next;
		delete rem_elem;
		count--;
	}
}

void LinkedList::removeFirst(){
	if (count){
		Node* rem_elem = head;
		if (count == 1){
			head = nullptr;
			tail = nullptr;
		}
		else{
			head = rem_elem->next;
		}
		delete rem_elem;

		count--;
	}
}

void LinkedList::removeLast(){
	if (count){
		if (count == 1){
			head = nullptr;
			tail = nullptr;
		}
		else{
			Node* curr_elem = head;
			while (curr_elem->next != tail)
				curr_elem = curr_elem->next;
			
			delete tail;
			
			curr_elem->next = nullptr;
			tail = curr_elem;
		}

		count--;
	}
}

void LinkedList::addAfter(Node* p, int val){

	Node* new_elem = new Node{val, nullptr};		
	Node* second_elem = p->next;
	new_elem->next = second_elem;
	p->next = new_elem;	

	// if we are adding to the tail, we have to update the tail
	if (p == tail)
		tail = new_elem; 
	
	count++;
}

void LinkedList::addBefore(Node* p, int val){
	// limit case: p is the last element
	Node* new_elem = new Node{val, nullptr};		
	Node* second_elem = p->next;
	new_elem->next = second_elem;
	p->next = new_elem;	

	swapData(p, new_elem);
	count++;
}