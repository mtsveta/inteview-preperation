#include "Utility.h"
#include <iostream>

/*
// first implementation
bool isPrime(int x)
{
	bool prime = true;

	for (int i = 2; i <= x / i; i++)
	{
		int factor = x / i;
		if(factor * i == x)
		{
			//std::cout << "factor found: " << factor << std::endl;
			prime = false;
			break;
		}
	}
	return prime;
}
*/

// alternative implementation with 
bool isPrime(int x)
{
	for (int i = 2; i < x; i++)
		if(x%i == 0)
		    return false;
	return true;
}


bool is2MorePrime(int x)
{
	return isPrime(x + 2);
}

int doubleIt(int const& x)
{
	return x*2;
}