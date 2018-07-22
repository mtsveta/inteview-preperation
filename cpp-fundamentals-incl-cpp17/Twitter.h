#pragma once
#include <string>
#include <iostream>
#include "Person.h"

class Twitter : public Person
{

	std::string twitterhandle;
	
	public:
		Twitter(std::string firstname, std::string lastname, std::string handle);	
		~Twitter();
		std::string getName() const;
		int getNumber() const {return 0;}
};
