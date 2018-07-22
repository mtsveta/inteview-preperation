#include "Twitter.h"

Twitter::Twitter(std::string firstname, std::string lastname, std::string handle) : 
	Person(firstname, lastname), twitterhandle(handle)
{
	std::cout << "Twitter " << Twitter::getName() << " is being constructed" << std::endl;
}

Twitter::~Twitter()
{
	std::cout << "Twitter " << Twitter::getName() << " is being discructed"  << std::endl;
}
// the getName function is overwritten
std::string Twitter::getName() const
{	
	//return firstname + " " + lastname + " " + twitterhandle;
	// however firstname and lastname are privite in Person
	// the solution: 
	return Person::getName() + " "+ twitterhandle;
}