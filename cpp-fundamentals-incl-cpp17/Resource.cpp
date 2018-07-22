#include "Resource.h"
#include <iostream>

Resource::Resource(std::string str) : name(str){
	std::cout << "resource " << name << " is constructed" << std::endl;
}
Resource::~Resource(){
	std::cout << "resource " << Resource::getName() << " is disctructed" << std::endl; 
}