#pragma once
#include <string>
#include "Resource.h"
#include <memory>

class Person
{

private:

	std::string firstname;
	std::string lastname;
	int arbitrarynumber;
	std::shared_ptr<Resource> pResource;

	// friend bool operator<(int i, Person const& p);]
	// this says that there is a function that can access privite members

public:

	Person(); // is the constructor won't do anything Person()=default;
	Person(std::string firstname, std::string lastname);
	virtual ~Person();
	// virtual discuctor 
	// allows to run proper discutructor
	// if Twitter is created 

	// virtual allows later to use overwritten functions by calling
	// Person::getName()
	virtual std::string getName() const;
	void setName(std::string str){firstname = str;}

	virtual int getNumber() const {return arbitrarynumber;} // function doesn't change anything
	void setNumber(int number) {arbitrarynumber = number;} // function changes arbitrarynumber

	// Overloaded operators
	bool operator<(Person const& p) const;
	bool operator<(int i) const;

	void addResource();
	std::string getResourceName() const {
		return pResource ? pResource->getName() : ""; // test of nullptr before calling something from pointer
	}
};

bool operator<(int i, Person const&  p);

/*
// implementation with copy contructor and copy assigment operator
class Person
{

private:

	std::string firstname;
	std::string lastname;

	int arbitrarynumber;
	Resource* pResource;

	// friend bool operator<(int i, Person const& p);]
	// this says that there is a function that can access privite members

public:

	Person(); // is the constructor won't do anything Person()=default;
	Person(std::string firstname, std::string lastname);
	~Person();
	// If you write a distructor -> you need to write a copy aasigment operator 
	// Copy constructor
	Person(Person const& p);


	std::string getName() const;
	void setName(std::string str){firstname = str;}

	int getNumber() const {return arbitrarynumber;} // function doesn't change anything
	void setNumber(int number) {arbitrarynumber = number;} // function changes arbitrarynumber

	// Overloaded operators
	bool operator<(Person const& p) const;
	bool operator<(int i) const;


	// Copy assigment operator
	Person& operator=(const Person& p);

	void addResource();
};

*/