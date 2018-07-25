#include "LinkedListT.h"
#include "Hashing.h"

using std::cout;
using std::endl;
using std::vector;
using std::string;

void TestHashing(){

	Hashing hashing;
	string inputStr = "foo";
	cout << "Hashing for '" << inputStr << "': \n"; 
	cout << "Additive: " << hashing.Additive(inputStr) << "\n";
	cout << "Folding: " << 0 << "\n";						// TODO	
	cout << "DJB2: " << 0 << endl;							// TODO

	vector<string> words{"foo", "hello", "world", "planet", "name", 
						 "television", "friendship", "peace", "fire", "family"};
	
	for (auto word : words){
		// hashing.Add(pair<int, string>(hashCode, word))
		hashing.AddToHashTable(word);
		hashing.PrintHashTable();
		cout << "count = " << hashing.GetCount() << endl;
		cout << "numberFilled = " << hashing.GetNumOfFilled() << endl << endl;
	
	}
	hashing.PrintHashTable();

	auto result = hashing.FindInHashTable("world");
	hashing.RemoveFromHashTable("world");
	
	hashing.PrintHashTable();
	cout << "count = " << hashing.GetCount() << endl;
	cout << "numberFilled = " << hashing.GetNumOfFilled() << endl << endl;
	
	hashing.RemoveFromHashTable("name");
	hashing.PrintHashTable();
	cout << "count = " << hashing.GetCount() << endl;
	cout << "numberFilled = " << hashing.GetNumOfFilled() << endl << endl;
	
}
