#include "ReversePolishNotation.h"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

#include <stdexcept>

using std::string;
using std::vector;
using std::copy;
using std::istream_iterator;
using std::istringstream;
using std::stack;

// My function splitting the string into tokens such that ' ' is  delimiter
/*
void inputStringToTokens(const string& inputString, const string& delim, vector<string>& tokens){
	
	std::string newToken("");
	std::string currChar("");
    for (auto it = begin(inputString); it != end(inputString); it++){
    	
    	copy(it, it+1, currChar);
    	cout << currChar << endl;
    	if(currChar != delim){ // not correc
    		newToken = newToken + currChar;
    	}
    	else{
    		tokens.emplace_back(newToken);
    		newToken.empty(); // or new_token = ""
    	}
    }
}
*/
bool isNumber(const string& str){

	auto it = str.begin();
    while (it != str.end() && std::isdigit(*it)) 
    	++it;
    // if the string is empty -> false 

    // if the string is not empty -> true
    // if we reached the end of the str -> true
    return !str.empty() && it == str.end();

    //shorter version: C++11
    /*
    return !str.empty() && 
    	   std::find_if(str.begin(), str.end(), 
    	   	[](char c) { return !std::isdigit(c); }) == str.end();
    */
}

int execOperation(const int& rhs, const int& lhs, const string& token){

	if (token == "+")      return lhs + rhs;
	else if (token == "-") return lhs - rhs;
	else if (token == "*") return lhs * rhs;
	else if (token == "/") return lhs / rhs;
	else if (token == "%") return lhs % rhs;
	else {
		// otherwise: if non of the matches worked
		throw std::invalid_argument("Operation" + token + "is not recongnised!");
		return 0;
	}

}

int reversePolishNotation(const vector<string>& tokens){

	stack<int> values;
	int rhs, lhs;
	int oper_result;

	for (auto token : tokens)
	{
		cout << "getting a token " << token << endl;
		if (isNumber(token)){
			cout << "pushin a token " << std::stoi(token) << " to stack" << endl;
			values.push(std::stoi(token));
		}else{
			// get rhs from the stack
			rhs = values.top();
			cout << "poping a token " << rhs << " into rhs" << endl;
			values.pop();

			// get lhs from the stack
			lhs = values.top();
			cout << "poping a token " << lhs << " into lhs" << endl;
			values.pop();

			cout << "runnigng an operation: " << lhs << " " << token << " " << rhs <<  endl;
			oper_result = execOperation(rhs, lhs, token);
			cout << "result =  " << oper_result << endl;
			// push result to the stack
			values.push(oper_result);
			cout << "push " << oper_result << " to stack" << endl << endl;
			
		}
	}
	int result = values.top();
	values.pop();
	return result;
}

void testReversePolishNotation(){

	// Process the input data into tokens

    string str = "5 6 7 * + 1 -";
    vector<std::string> tokens;
	
	// inputStringToTokens(str, delim, tokens);
	
	// https://stackoverflow.com/questions/236129/the-most-elegant-way-to-iterate-the-words-of-a-string
	// string stream
	istringstream iss(str);
	// istream_iterator<T> reads successive objects of type T 
	// from the std::istringstream object
    copy(istream_iterator<string>(iss), 
    	 istream_iterator<string>(), 
    	 back_inserter(tokens));
	
	for(auto& s: tokens)
        std::cout << s << " " << '\n';
    int result = reversePolishNotation(tokens);
    cout << "results of ReversePolishNotation = " << result << endl;

    // boost library
	/*
	#include <boost/algorithm/string/split.hpp>
	#include <boost/algorithm/string/classification.hpp>

	string delim = " "
    split(tokens, str, is_any_of(delim)); // here it is

    for(auto& s: tokens)
        std::cout << '"' << s << '"' << '\n';
    */

}