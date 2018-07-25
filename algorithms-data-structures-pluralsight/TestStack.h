#include "Stack.h"
#include "StackOnArray.h"

void TestStack(){
	Stack stack;
	stack.push(1);
	stack.printStack();
	stack.push(10);
	stack.printStack();
	stack.push(5);
	stack.printStack();
	stack.pop();
	stack.printStack();
	stack.push(8);
	stack.printStack();
	stack.push(34);
	stack.printStack();
	stack.pop();
	stack.printStack();
	stack.pop();
	stack.printStack();
	stack.pop();
	stack.printStack();
	stack.pop();
	stack.printStack();
	//stack.pop();
	
	// --------------------------------------------------------------
	// STL implementation of the stack
	// 
	std::stack<int> stlStack;
	stlStack.push(10);
	stlStack.push(20);
	stlStack.push(30);
	
	cout << stlStack.top() << endl;
	cout << stlStack.top() << endl;
	stlStack.pop();
	cout << stlStack.top() << endl;

	// Printing the stack is equal to emptying it first
	
	// --------------------------------------------------------------
	// STL implementation of the stack
	// 
	StackOnArray<int> arrayStack;

	arrayStack.push(10);
	arrayStack.push(8);
	arrayStack.push(5);
	arrayStack.print();
	arrayStack.top();
	arrayStack.print();
	arrayStack.top();
	arrayStack.pop();
}