#include "QueueOnArray.h"
#include "Queue.h"

template<typename T> 
void print_queue(T& q) {
    while(!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';
}

void TestQueue(){
	Queue queue;
	queue.Enqueue(1);
	queue.Print();
	queue.Enqueue(10);
	queue.Print();
	queue.Enqueue(5);
	queue.Print();

	queue.Dequeue();
	queue.Print();
	
	queue.Enqueue(8);
	queue.Print();
	queue.Enqueue(34);
	queue.Print();
	queue.Dequeue();
	queue.Print();
	queue.Dequeue();
	queue.Print();
	queue.Dequeue();
	queue.Print();
	queue.Dequeue();
	queue.Print();
	//queue.Dequeue();
	
	// --------------------------------------------------------------
	// STL implementation of the queue
	// 
	std::queue<int> stlQueue;
	stlQueue.push(10);
	stlQueue.push(20);
	stlQueue.push(30);
	
	cout << stlQueue.front() << endl;
	cout << stlQueue.front() << endl;
	stlQueue.pop();
	cout << stlQueue.front() << endl << endl;


	// --------------------------------------------------------------
	// STL implementation of the queue
	// 
	QueueOnArray<int> arrayqueue;
	arrayqueue.Enqueue(10);
	arrayqueue.Enqueue(8);
	arrayqueue.Enqueue(5);
	arrayqueue.Print();
	arrayqueue.Dequeue();
	arrayqueue.Print();
	arrayqueue.Dequeue();
	arrayqueue.Print();
	arrayqueue.Dequeue();
	arrayqueue.Print();


	// --------------------------------------------------------------
	// STL implementation of the queue
	// 
	std::priority_queue<int> stlPrioriryQueue;
	stlPrioriryQueue.push(10);
	stlPrioriryQueue.push(1);
	stlPrioriryQueue.push(20);
	print_queue(stlPrioriryQueue);

	// Example from https://en.cppreference.com/w/cpp/container/priority_queue
	std::priority_queue<int> q;
 	for(int n : {1,8,5,6,3,4,0,9,7,2})
        q.push(n);
	print_queue(q);
 
    std::priority_queue<int, std::vector<int>, std::greater<int> > q2;
 	for(int n : {1,8,5,6,3,4,0,9,7,2})
        q2.push(n);
	print_queue(q2);
 
    // Using lambda to compare elements.
    auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1);};
    std::priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp);
 	for(int n : {1,8,5,6,3,4,0,9,7,2})
        q3.push(n);
	print_queue(q3);
	
}