/*
Your hash table implementation should include the following features :
• A parameterized constructor that allows specifying the table size(should be a power of 2)
• Methods for insertion, retrieval, and deletion
• Collision resolution using either chaining or open addressing
• A hash function that uses Fibonacci Hashing
• An alternative implementation using traditional modulo hashing for compar
*/

#include "HashTable_Separate_Chaining.h"
#include "HashTable_Linear_Probing.h"
#include "HashTable_Quadratic_Probing.h"
#include "HashTable_Double_Probing.h"


int main() {
	HashTable_Linear_Probing ht(17);

	vector<pair<string, int>> data = {
		{"apple", 5}, {"banana", 8}, {"cherry", 3}, {"date", 12},
		{"grape", 10}, {"lemon", 7}, {"orange", 9}, {"pear", 4},
		{"fig", 6}, {"kiwi", 11}, {"mango", 2}, {"peach", 15}, {"lemon", 13}, {"apple", 10}
	};

	for (const auto& item : data) {
		ht.insert(item.first, item.second);
	}

	std::cout << "Hash Table Contents :" << std::endl;
	ht.print();

	std::cout << "\nLookup Operations :" << std::endl;
	int value;
	if (ht.search("banana", value)) {
		std::cout << "Found banana with value " << value << std::endl;
	}
	else {
		cout << "Could not find banana " << std::endl;
	}

	if (ht.search("kiwi", value)) {
		cout << "Found kiwi with value " << value << endl;
	}
	else {
		cout << "Could not find kiwi " << std::endl;
	}

	return 0;
}