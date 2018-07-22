// preprocessor commands // it controls, what is compiled
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

#include "Person.h"
#include "Twitter.h"
#include "Utility.h"
#include "Template.h"
#include "Accum.h"
#include "Resource.h"
#include "status.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::shared_ptr;
using std::make_shared;
// #pragma once 
// it makes sure that all the header are included just once

// list fo prototypes for the functions 
void introduction();
void variables_functional_types();
void language_basics_user_defined_types();
void language_basics_functions();
void language_basics_operators();
void templates();
void indirection();
void memory_management();
void references_inheritance();

// Person const& p - this allows to run getNumber of the derived class
// 
int Dummy(Person const& p) {return p.getNumber();}

int main ()
{

	//introduction();
	//variables_fundamental_types();
	//language_basics_user_defined_types();
	//language_basics_functions();
	//language_basics_operators();
	//templates();
	//indirection();
	//memory_management();
	references_inheritance();

	return 0;
}




void references_inheritance(){

	// Base class
	// virtual - derived version will run (polymorphism)
	// non-virtual function - base class executes
	// virtual table 

	// -----------------------------------------------------------------
	// Cannot:
	// - create derived class reference
	// - pointer of the base class CAN point to te derived class
	// - base class functions are call via pointer
	// if virtual -> derived class func executes
	// if nonvirtual -> base class func executes 

	// smart pointers follow the same behaviour

	Person Kate("Kate", "Gregory");
	Kate.setNumber(123);
	Person& rKate = Kate;
	Person* pKate = &Kate;

	Twitter KateTwitter("Kate", "Gregory", "@gregcons");
	KateTwitter.setNumber(456);

	Person* pKateTwitter = &KateTwitter;
	Person& rPersonKateTwitter = KateTwitter;

	Twitter& rKateTwitter = KateTwitter;

	cout << Kate.getName() << endl;
	cout << rKate.getName() << endl;
	cout << pKate->getName() << endl;
	cout << KateTwitter.getName() << endl; // here Person's getName() is used, the base class function is used 
	cout << pKateTwitter->getName() << endl; // here Person's getName() is used
	cout << rPersonKateTwitter.getName() << endl;
	cout << rKateTwitter.getName() << endl;

	// -----------------------------------------------------------------
	// virtual functions: 
	// if virtual is not used poniter and reference are thinking about it 

	Person* someone = new Twitter("Someone", "Anyone", "@someone");
	cout << someone->getName() << endl;
	delete someone;

	// Rule: as soon as you have one virtual function, make sure the discructor is vritual too
	// because in this case Person gets deleted, not a Twitter
	// e.g., output:
	// Twitter Someone Anyone @someone is being constructed
	// Someone Anyone
	// Person Someone Anyone is being discructed
	//
	// with vitual destructor: 
	// 
	// Twitter Someone Anyone @someone is being constructed
	// Someone Anyone @someone
	// Twitter Someone Anyone @someone is being discructed
	// Person Someone Anyone is being discructed

	// -----------------------------------------------------------------
	// Slicing (downside of inheritance)
	// - if copying the dirived object into the base-class object - some member vars might be lost
	// - cannot copy a base-obj into the derived one
	// - might occure if passing the parameters by value, not by reference -> copy is made and slicing happens
	//
	// To avoid slicing:
	// - use pointer or references
	// 
	// alternative to the code above
	shared_ptr<Person> spKate = make_shared<Twitter>("Hello", "World", "@hello_world");
	cout << spKate->getName() << endl;


	// KateTwitter = Kate; // is not supperted
	Kate = KateTwitter;

	int x;
	x = Dummy(Kate);
	cout << x << endl;
	x = Dummy(KateTwitter);
	cout << x << endl;

	// -----------------------------------------------------------------
	// Casting pointers
	// 
	// static_cast<T> (compile time)
	//
	// dynamic_cast<T> (runtime check)
	// happens only when casting a pointerto a class with 
	// a vitual table
	// returns null if the cast fails

	Twitter t("Sasha", "Petrov", "@sashapertor");
	Person* p = &t;
	Twitter* pt = static_cast<Twitter*>(p);

	Resource local("local");
	Twitter* pt2 = dynamic_cast<Twitter*>(p);
	if (pt2){
		cout << "after dynamic casting: " << pt2->getName() << endl;
	}
	
}




void memory_management()
{
	// Free store (heap) vs. 	// Local (stack)

	// for longer lived variables we use free store
	// creat new -> returs a pointer to the intance -> constuctor (to intialise it  )
	// 
	{
		// creating local resource
		Resource localResource("local");
		std::string localString = localResource.getName();
	}

	// 
	Resource* pResource = new Resource("created with new");
	std:string newString = pResource->getName();
	
	// if we have some condition
	// int j = 3;
	// if (j == 3) return 0; // if this gets executed -> we get a memory leak
	// Resource* p2 = pResource;

	delete pResource;

	// pResource = nullptr;
	// delete p2; // also bad: the memory was already deleted
	// string string3 = pResource->getName(); // bad: access to something already deleted 

	// no new 
	// no delete

	// rule of 3: 
	// --------------------------------------------------------
	// - destructor (deletes all that has been created with new)
	// - copy contructor (uses new to initialize form the existing value)
	// - copy assigment operator (if there is already a value, it deletes it and uses new to initialize)
	// ->
	// rule of 5:
	// - move constructor
	// - move assigment operator 

	// rule of 0:
	// use only stack!
	// use library pointers: smart pointers
	/*
	Person Kate("Kate", "Gregory");
	Kate.addResource();
	Kate.setName("Kate2");
	Kate.addResource();
	Person Kate2 = Kate;
	*/

	// Easy memory management 
	// 
	// unique_ptr
	// cannot be copies (std::move)

	// shared_ptr
	// reference counter

	// weak_ptr
	// 

	{
		Person Kate("Kate", "Gregory");
		Kate.addResource();
		string s1 = Kate.getResourceName();
		Kate.addResource(); 
		Person Kate2 = Kate;
		Kate = Kate2;

		int j;
		j = Dummy(Kate2);
	}
}




void indirection()
{
	// References (aleas)
	// - one can set its target (where it refers to) when declaring
	// - all that can be done to the target, can be done to the reference
	// - if the reference poins to something, it cannot be re-targeted (re-pointing to something else)
	// 

	// Pointers 
	// - pointer can point to something exisiting 
	// - it can point to null
	// - it can be repointed

	int A = 5;
	int* pA = &A;
	int& rA = A; // just an alias
	std::cout << "pA = " << pA << std::endl;
	std::cout << "*pA = " << *pA << std::endl;
	std::cout << "rA = " << rA << std::endl;
	std::cout << "&rA = " << &pA << "\n\n" << std::endl;

	// int* pA = &A; // doesn't matter // more mordern 

	*pA = 1;
	std::cout << "pA = " << pA << std::endl;
	std::cout << "*pA = " << *pA << std::endl;
	std::cout << "rA = " << rA << std::endl;
	std::cout << "&rA = " << &pA << "\n\n" << std::endl;

	rA = 3; 
	
	std::cout << "pA = " << pA << std::endl;
	std::cout << "*pA = " << *pA << std::endl;
	std::cout << "rA = " << rA << std::endl;
	std::cout << "&rA = " << &pA << "\n\n" << std::endl;

	int b = 100;
	pA = &b;

	std::cout << "pA = " << pA << std::endl;
	std::cout << "*pA = " << *pA << std::endl;
	std::cout << "rA = " << rA << std::endl;
	std::cout << "&rA = " << &pA << "\n\n" << std::endl;

	(*pA)++; // adding to the value


	std::cout << "pA = " << pA << std::endl;
	std::cout << "*pA = " << *pA << std::endl;
	std::cout << "rA = " << rA << std::endl;
	std::cout << "&rA = " << &pA << "\n\n" << std::endl;

	pA++;

	std::cout << "pA = " << pA << std::endl;
	std::cout << "*pA = " << *pA << std::endl;
	std::cout << "rA = " << rA << std::endl;
	std::cout << "&rA = " << &pA << "\n\n" << std::endl;


	Person kate("Kate", "Gregory");
	Person* pKate = &kate;
	std::cout << "name = " << (*pKate).getName() << std::endl;
	std::cout << "name = " << pKate->getName() << std::endl;


	Person& rKate = kate;
	rKate.setNumber(345);

	// Null pointer
	// nullptr


	// int& badReference; // impossible! we must initialize
	// int* badPointer;   // it points nowhere 
	// *badPointer = 3; // bad pointer 

	int* badPointer = nullptr;
	if (badPointer){
		*badPointer = 3;
		std::cout << *badPointer << std::endl;
	}

	// Const (How does it work with references and pointers)

	//int const zero = 0;
	//int foo (int const i);
	//int something(Person &const p);	// p is not allowed to be changed 
	//int GetName() const; // function does not change anything 

	// const after (way easier to understand)
	int i = 3;
	int const ci = 3;
	i = 4;
	// ci = 4; // not allowed

	int const & cri = i;
	// cri = 6; // not allowed

	int j = 10;
	int doublej = doubleIt(j);
	int doubleTen = doubleIt(10);
	/*
	int * pI = &i; // pointer to integer 
	int const * pcI = pI; // pointer to a const
	int * const cpI = pI; // const pointer 
	int const * const = pI; // const pointer to a const 
	*/
}












void templates()
{
	// Genericity is implemented by Templates

	// average, largest, smallest
	// template relies on the operator operload

	// e.g., STL: string, collections 
	Person p1("Tutti", "Saksa"), p2("Svetla", "Matculevich");
	p1.setNumber(102);
	p2.setNumber(345);
	int i = 10;

	std::string hello("hello");
	std::string world("world");

	std::cout << "max(hello, world) = " << std::max(hello, world) << std::endl;
	std::cout << "max(p1, i) = " << max(p1, p2).getName() << std::endl;
	std::cout << "max(3.0, 4) = " << max<double>(3.0, 4) << std::endl;

	// Template classes

	Accum<int> accume_int(0);
	std::vector<int> values{1, 2, 3, 4, 5};

	std::for_each(values.begin(), values.end(), [ &accume_int ](int & value){
		accume_int += value;
	});
	std::cout << "total value = " << accume_int.getTotal() << std::endl;

	Accum<std::string> accume_string("");
	std::vector<std::string> strings{"a", "b", "c", "d", "e"};

	std::for_each(begin(strings), end(strings), [ &accume_string ](std::string const& str){
		accume_string += str;
	});
	std::cout << "total string = " << accume_string.getTotal() << std::endl;


	// Template spacializtion

	// Person start("", "", 0); this is no longer nedded
	Accum<Person> accum_person(0);
	accum_person += p1;
	accum_person += p2;
	std::cout << "total persons = " << accum_person.getTotal() << std::endl;

	// Summury: 


}

void language_basics_operators()
{
	// Operators

	int i = 2;
	int j = 0;
	while (i < 101)
		j += isPrime(i++) ? 1 : 0;
	std::cout << "I found " << j << " primes" << std::endl;

	// && || - operate on bollean
	// quite often && : is used in if to break is the first thing is false, 
	// then the rest doesn't matter
	// same for || : if the first part is true then the rest doesn't matter 

	// do not mix == and =
	// sometimes it is better to write (3 == num)

	/*
	// we can do simultanously evaluate foo and write it into p
	// if will go through only if p != 0
	int p;
	if (p = foo("somthing"))
		somthing();
	*/

	std::cout << "Define two numbers" << std::endl;
	std::cin >> i;
	std::cin >> j;
 	std::cout << "i = " << i << ", j = " << j << std::endl;
	
	std::cout << j << " is";  
	if ((j != 0) && !(i%j == 0)) // first expression will prevent error dividing by zero
		std::cout << " not";
	std::cout << " a factor of " << i << std::endl;

	// bitwise operators: & | ^
	// <<, >>

	// Overloading operator (at the heart of the generic coding)
	// - function that starts with words operator
	// - usually a member function (only ocasionaly free function)

	// STL
	// string have lost of overloads 

	// All the operators can be overloaded!

	// There are two scenarions:

	// MyObject < Something
	// bool MyClass::operator<(OtherType something) 
	// as a memsber function

	// Something < MyObject
	// bool operator<(OtherType something, MyClass mc) 
	// as a free function or friend function of the Person

	Person p1, p2;
	p1.setNumber(100);
	p2.setNumber(102);

	int num = 1;

	std::cout << "p1 < p2  ? " << (p1 < p2) << std::endl;
	std::cout << "p1 < num ? " << (p1 < num) << std::endl;
	std::cout << "num < p1 ? " << (num < p1) << std::endl;

}

void language_basics_functions()
{

	// free functions
	// taking parameter by reference

	for (int i = 0; i < 20; i++)
		std::cout << "Is " << i << " a prime number? " << isPrime(i) << std::endl;

	Person p("Svetlana", "Matculevich");
	p.setNumber(20);
	std::cout << p.getName() << " has a number " << p.getNumber() << std::endl;


	// Error messages:
	// compiler: have you declared that function? in .h files (making promises)
	// something is not defined
	// linker: have you implemented that function? in .cpp file (keeping promises)
	// something is not implemented 

	// Common mistakes:
	// e.g., missing .h include  (when calling, in the main fucnton, or when implementing)
	// .cpp file is not included into the project


}

void language_basics_user_defined_types()
{

	// Building
	//	- you have to declair the class // promise the compiler
	//  - linker will insure the promise is kept // it will link the code that uses the class and the code that implements it
	// #include header file, where the declaration of the class is 
	// .cpp implements, what has been declared


	// Person.cpp (#include Person.h)
	// Example.cpp (#include Person.h)
	// Person.h (#include <string> )

	// class - keyword
	// private and public
	// Instance of the class

	// Incapsulation - making some things privite, public in order to protect direct access to the name 

	// Scope

	// allocating on the stack: 
	// creating an object (acquire the resource by initialization)
	// the object is seen till the end of the scope (releasing the resource by desctruction)

	Person p_withname("Alex", "Smith");
	{
		Twitter t("Svetlana", "Matculevich", "@mtsveta");
		Person p;	
	}
	// Struct (public by default)
	// Namespaces
	using namespace std; // but this is very general
	using std::cout;
	using std::cin;

	// in header file: always full name! no nmaespaces


	// Inheritance - key to the OOP
	// derived classes can override / add some functionality
	// multiple inheritance is allowed

	Status s = Pending;
	s = Approved;

	FileError fe = FileError::notfound;
	fe = FileError::ok;


	NetworkError ne = NetworkError::disconnected;
	ne = NetworkError::ok;

}
void variables_fundamental_types()
{

	// short num_short;
	// long num_long;
	// int num_int;

	// auto - ask from the compiler, which type it is 

	auto a1 = 1;
	auto a2 = 2.2;	// double
 	auto a3 = 'c';	// char
 	auto a4 = "s";	// const char *	== C-style string
 	// compiler indicates everything in double quote as a cont char*
	
	auto a5 = true;
	auto a6 = 3L;
	auto a7 = 1000000000000;	// ' intruduced as 
	auto a8 = 0xFF;					// 15*16^1 + 15*16^0 (F stands for 15)
	auto a9 = 0b111;

	// g++ main.cpp -std=c++11 // to specify the standard library version]
	
	unsigned char n1 = 128;
	//char n2 = 128;				// warning: implicit conversion from 'int' to 'char' changes value

	std::cout << "n1 = " << n1 << std::endl;
	//std::cout << "n2 = " << n2 << std::endl; // since char is holds values from -128 till 127


	// casting 
	// - suffixes L, D
	// - safe cast

	double num_double = 2.34;
	int num_int = static_cast<int>(2.34);	// this will supress the warning

	std::cout << "num_double = " << num_double << std::endl;
	std::cout << "num_int = " << num_int << std::endl;

}

void introduction()
{
	std::cout << "Type you name:" << std::endl;
	std::string name;
	std::cin >> name;
	std::cout << "Hello, " << name << std::endl;

	// Running from the command line
	// $ g++ main.cpp -o main
	// $ ./main
}

/*
int main(int argc, char const *argv[])
{
	return 0;
}

:: namespace 

std - standard name space
cout/cin - counsil output/input
endl - end line

*/
/*
//--------------------------------------------------------------------------------
C++ is a General purpose language:

- performance and power
- not that complicated as everyone think
- popular 
- lots of specialized librariries


Modern C++

- clean and simple 

- STL (Standard Library):

String class
Collections 
Smart poiters
...

- Memory management:
	managing mamory yourself is old school
	pointer arithmetics is done by libraries 
	C++ is like Java and C# but faster (templates are resoved on the compile time)
	

- Standartization:
	compilier for C++17 might come out a bit later than C++17 itself


https://isocpp.org/
https://en.cppreference.com/w/cpp/compiler_support
https://en.cppreference.com/w/
http://www.cplusplus.com/
https://wandbox.org/

Difference to Java and C#:
//--------------------------------------------------------------------------------
*/

/*
//--------------------------------------------------------------------------------

Tools:

	Compiler and linker
	Editor for the source code
	Debugger


Build:

.cpp (one or more) --compiling--> .obj (one or more) --linking--> .exe 

why two steps when there is one one file in the end? faster build cycle:
if you did the change in one file -> 
you recompile only this file, the rest is not changed ->
and then it is linked to the rest


Complile and link: 
	cgg
	clang

IDE (Integrated Development Enviroment) provides editor + compiler + debugger:
	Visual Studio (Windows)
	Visual Studio Code (Mac and Linux)
	Clion

Online compilers:
	for comparing compiliers
	testing new language or library
	sharing snippet when  asking for help

C++ 17 is backword compatible!

//--------------------------------------------------------------------------------
*/

/*
//--------------------------------------------------------------------------------

Kinds of Applications:
	- phone and client applications
	- console applications (are the simplest)
	- services
	- server (process requests)


Framework can be used for writing for a phone app. 

//--------------------------------------------------------------------------------
*/


/*

-DCMAKE_CXX_COMPILER="/usr/local/Cellar/gcc/7.3.0_1/bin/g++-7" 
-DCMAKE_C_COMPILER="/usr/local/Cellar/gcc/7.3.0_1/bin/gcc-7" 
-DGISMO_WITH_OPENMP=ON 
-DGISMO_WITH_SUPERLU=OFF
*/
