#include <iostream>
#include "Person.h"



std::string Person::getName() const 
{
	return firstname + " " + lastname;
}

Person::Person() : firstname(""), lastname("")
{
	std::cout << "A person is being created" << std::endl; 
}
Person::Person(std::string firstname, std::string lastname) : // here : - construction intializer
	firstname(firstname), lastname(lastname), pResource(nullptr)
{
	std::cout << "A person " << Person::getName() << " is being constructed" << std::endl; 
}

Person::~Person()
{
	std::cout << "Person " << Person::getName() << " is being discructed"  << std::endl;
}

bool Person::operator<(Person const& p) const
{
	return arbitrarynumber < p.arbitrarynumber;
}

bool Person::operator<(int i) const 
{
	return arbitrarynumber < i;
}

void Person::addResource(){
	pResource.reset(); // takes care of deleting
	pResource = std::make_shared<Resource>("Resource for " + getName());
}	

bool operator<(int i, Person const& p)
{
	return i < p.getNumber();
	// return i < p.arbitrarynumber; // to make it work
}



/*
// first version of the constructor
Person::Person(std::string firstname, std::string lastname) : // here : - construction intializer
	firstname(firstname), lastname(lastname)
{
	std::cout << "A person " << Person::getName() << " is being created" << std::endl; 
}*/
/*
// implementation with a classic memeory management
std::string Person::getName() const 
{
	return firstname + " " + lastname;
}

Person::Person() : firstname(""), lastname("")
{
	std::cout << "A person is being created" << std::endl; 
}
Person::Person(std::string firstname, std::string lastname) : // here : - construction intializer
	firstname(firstname), lastname(lastname), pResource(nullptr)
{
	std::cout << "A person " << Person::getName() << " is being created" << std::endl; 
}

Person::~Person()
{
	std::cout << "A person "<< Person::getName() << " is being discructed" << std::endl; 
	delete pResource;
}

Person::Person(Person const& p){
	// the name of the resource we can get from p
	// p.Resource is accesable since we are in Rerson scope
	pResource = new Resource(p.pResource->getName());
}

Person& Person::operator=(const Person& p){
	delete pResource;
	pResource = new Resource(p.pResource->getName());
	return *this;

}

bool Person::operator<(Person const& p) const
{
	return arbitrarynumber < p.arbitrarynumber;
}

bool Person::operator<(int i) const 
{
	return arbitrarynumber < i;
}


void Person::addResource(){
	pResource = new Resource("Resource for " + Person::getName());
}	

*/