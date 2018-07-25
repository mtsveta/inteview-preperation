#pragma once
#include <iostream>


std::ostream& operator<<(std::ostream& os, const std::pair<int,std::string>& rhs){ 
	os << "<" << rhs.first << ", " << rhs.second << ">";
	return os; 
}

template <class TKey, class TValue>
bool equal(const std::pair<TKey,TValue>& lhs, const std::pair<TKey,TValue>& rhs){ 
	return lhs.first==rhs.first; 
}

template <class T>
struct Node{
	T data;
	Node* next;
};
// single chain of nodes(lists)
template <class T>
class LinkedList{
	Node<T>* head;
	Node<T>* tail;
	int count;

	public:
		LinkedList<T>():head(nullptr), tail(nullptr), count(0){};
		//LinkedList<T>(Node<T>* h, Node<T>* t) : head(h), tail(t) {count++;};

		void Print() const;
		int GetCount() const {return count;}
		Node<T>* GetHead() const {return head;};
		Node<T>* GetTail() const {return tail;};
		
		void AddToHead(T value); // 0(1)
		void AddToTail(T value); // 0(1)
		Node<T>* SearchFor(T value); // 0(n)
		Node<T>* SearchForWithPrev(T value, Node<T>*& prev); // 0(n)
		void RemoveAfter(Node<T>* p); // 0(1)
		void RemoveLast(); // 0(1)
		void RemoveFirst(); // 0(1)
		void AddAfter(Node<T>* p, T value); // 0(1)
		void AddBefore(Node<T>* p, T value); // 0(1)

		void Empty();
		bool IsEmpty() const { return (count == 0);}

};

template <class T>
void SwapData(Node<T>* elem1, Node<T>* elem2){
	T tmp_val = elem1->data;
	elem1->data = elem2->data;
	elem2->data = tmp_val;
}
// O()
template <class T>
void LinkedList<T>::Print() const {
	std::cout << "list with " << GetCount() << " elements:\t";
	for (Node<T>* p = head; p != nullptr; p = p->next){
		std::cout << p->data << " -> ";
	}
	std::cout << "null" << std::endl;
}
// O()
template <class T>
void LinkedList<T>::Empty() {
	for (Node<T>* p = head; p != nullptr; p = p->next){
		delete p;
		count --;
	}
	std::cout << "the list is emptied!" << std::endl;
}
// O(1)
template <class T>
void LinkedList<T>::AddToHead(T value){
	Node<T>* new_elem = new Node<T>{value, nullptr};
	new_elem->next = head;
	head = new_elem;
	count++;

	// if the list was empty then head and tail are poiting to the same element
	if (count == 1)
		tail = head;

}
// O(1)
template <class T>
void LinkedList<T>::AddToTail(T value){
	Node<T>* new_elem = new Node<T>{value, nullptr};
	if (tail){
		tail->next = new_elem;
	}
	tail = new_elem;
	count++;

	// if the list was empty then head and tail are poiting to the same element
	if (count == 1)
		head = tail;
}

template <class T>
Node<T>* LinkedList<T>::SearchFor(T value){
	for (Node<T>* p = head; p != nullptr; p = p->next){
		//if (p->data == value)
		if (equal(p->data, value))
			return p;
	}
	return nullptr;
}
template <class T>
Node<T>* LinkedList<T>::SearchForWithPrev(T value, Node<T>*& prev){
	prev = nullptr;

	for (Node<T>* p = head; p != nullptr; p = p->next){
		//if (p->data == value)
		if (equal(p->data, value))
			return p;
		prev = p;
	}
	return nullptr;
}

template <class T>
void LinkedList<T>::RemoveAfter(Node<T>* p){
	// limit case: p is the last element
	if (p->next == nullptr)
		std::cout << p->data << " is the last element => nothing to remove" << std::endl;
	else{
		Node<T>* rem_elem = p->next;		
		Node<T>* new_next = p->next->next;
		p->next = new_next;
		delete rem_elem;
		count--;
	}
}

template <class T>
void LinkedList<T>::RemoveFirst(){
	if (count){
		Node<T>* rem_elem = head;
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

template <class T>
void LinkedList<T>::RemoveLast(){
	if (count){
		if (count == 1){
			head = nullptr;
			tail = nullptr;
		}
		else{
			Node<T>* curr_elem = head;
			while (curr_elem->next != tail)
				curr_elem = curr_elem->next;
			
			delete tail;
			
			curr_elem->next = nullptr;
			tail = curr_elem;
		}

		count--;
	}
}

template <class T>
void LinkedList<T>::AddAfter(Node<T>* p, T value){

	Node<T>* new_elem = new Node<T>{value, nullptr};		
	Node<T>* second_elem = p->next;
	new_elem->next = second_elem;
	p->next = new_elem;	

	// if we are adding to the tail, we have to update the tail
	if (p == tail)
		tail = new_elem; 
	
	count++;
}

template <class T>
void LinkedList<T>::AddBefore(Node<T>* p, T value){
	// limit case: p is the last element
	Node<T>* new_elem = new Node<T>{value, nullptr};		
	Node<T>* second_elem = p->next;
	new_elem->next = second_elem;
	p->next = new_elem;	

	swapData(p, new_elem);
	count++;
}