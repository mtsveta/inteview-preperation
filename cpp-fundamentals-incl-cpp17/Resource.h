#pragma once
#include <string>

class Resource
{
	private:
		std::string name;

	public:
		Resource();
		Resource(std::string str);	
		~Resource();
		std::string getName() const {return name;}
};