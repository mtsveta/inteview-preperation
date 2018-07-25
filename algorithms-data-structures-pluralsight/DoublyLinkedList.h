#pragma once
#include <iostream>


struct DNode{
	int data;
	DNode* next;
	DNode* prev;
};
// single chain of nodes(lists)
class DoublyLinkedList{
	DNode* head;
	DNode* tail;
	int count;

	public:
		DoublyLinkedList():head(nullptr), tail(nullptr), count(0){};
		DoublyLinkedList(DNode* h, DNode* t) : head(h), tail(t) {
			count++;
		};

		void printList() const;
		int getCount() const {return count;}
		DNode* getHead() const {return head;};
		DNode* getTail() const {return tail;};
		
		void addToHead(int value); // 0(1)
		void addToTail(int value); // 0(1)
		DNode* searchFor(int value); // 0(n)
		void removeAfter(DNode* p); // 0(1)
		void removeLast(); // 0(1)
		void removeFirst(); // 0(1)
		void addAfter(DNode* p, int value); // 0(1)
		void addBefore(DNode* p, int value); // 0(1)
};


// O()
void DoublyLinkedList::printList() const {
	std::cout << "list with " << getCount() << " elements:\t";
	for (DNode* p = head; p != nullptr; p = p->next){
		std::cout << p->data << " -> ";
	}
	std::cout << "null" << std::endl;
}
// O(1)
void DoublyLinkedList::addToHead(int value){
	DNode* new_elem = new DNode{value, nullptr, nullptr};
	new_elem->next = head;
	head->prev = new_elem;
	head = new_elem;
	count++;

	// if the list was empty then head and tail are poiting to the same element
	if (count == 1)
		tail = head;

}
// O(1)
void DoublyLinkedList::addToTail(int value){
	DNode* new_elem = new DNode{value, nullptr, nullptr};
	if (tail){
		tail->next = new_elem;
		new_elem->prev = tail;
	}
	tail = new_elem;
	count++;

	// if the list was empty then head and tail are poiting to the same element
	if (count == 1)
		head = tail;
}

DNode* DoublyLinkedList::searchFor(int value){
	for (DNode* p = head; p != nullptr; p = p->next){
		if (p->data == value)
			return p;
	}
	return nullptr;
}

void DoublyLinkedList::removeAfter(DNode* p){
	// limit case: p is the last element
	if (p->next == nullptr)
		std::cout << p->data << " is the last element => nothing to remove" << std::endl;
	else{
		DNode* rem_elem = p->next;		
		DNode* new_next = p->next->next;
		p->next = new_next;
		new_next->prev = p;
		delete rem_elem;
		count--;
	}
}

void DoublyLinkedList::removeFirst(){
	if (count){
		DNode* rem_elem = head;
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

void DoublyLinkedList::removeLast(){
	if (count){
		DNode* rem_elem = tail;
		if (count == 1){
			head = nullptr;
			tail = nullptr;
		}
		else{
			tail = rem_elem->prev;
		}
		delete rem_elem;

		count--;
	}
}

void DoublyLinkedList::addAfter(DNode* p, int value){

	DNode* new_elem = new DNode{value, nullptr, nullptr};

	DNode* second_elem = p->next;
	
	new_elem->next = second_elem;
	second_elem->prev = new_elem;

	p->next = new_elem;	
	new_elem = p->prev;

	// if we are adding to the tail, we have to update the tail
	if (p == tail)
		tail = new_elem; 
	
	count++;
}

void DoublyLinkedList::addBefore(DNode* p, int value){
	// limit case: p is the last element
	DNode* new_elem = new DNode{value, nullptr, nullptr};		
	DNode* prev_elem = p->prev;
	
	prev_elem->next = new_elem;
	new_elem->prev = prev_elem;

	new_elem->next = p;
	p->prev = new_elem;	

	count++;
}