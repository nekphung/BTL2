#include "HashTable_Linear_Probing.h"

HashTable_Linear_Probing::HashTable_Linear_Probing(int tableSize) : size(tableSize) {
	table.resize(size);
}

HashTable_Linear_Probing::Entry::Entry() : key(""), value(0), isOccupied(false), isDeleted(false) {}

int HashTable_Linear_Probing::hashFunction(const string& key) {
	int sum = 0;
	for (char c : key) {
		sum += static_cast <int>(c);
	}
	return sum % size;
}

// fibonacci hashing
int HashTable_Linear_Probing::fibonacciHash(const string& key)   {
	const unsigned long long FIB_MULT = 11400714819323198485ull; // ~2^64 / phi
	unsigned long long hash = 0;

	for (char c : key) {
		hash = hash * 31 + c;
	}
	int shift = 64 - static_cast<int>(log2(size)); // size = 2^k
	return (hash * FIB_MULT) >> shift;
}


bool HashTable_Linear_Probing::insert(const string& key, int value) {
	int Index = fibonacciHash(key);
	int i = 0;
	while (i < size) {
		int index = (Index + i) % size;
		if (!table[index].isOccupied) {
			table[index].key = key;
			table[index].value = value;
			table[index].isOccupied = true;
			return true;
		}
		else if (table[index].key == key) {
			table[index].value = value;
			return true;
		}
		i++;
	}

	return false;
}

bool HashTable_Linear_Probing::search(const string& key, int& value) {
	int Index = fibonacciHash(key);
	int i = 0;
	while (i < size) {
		int index = (Index + i) % size;

		if (table[index].key == key) {
			value = table[index].value;
			return true;
		}
		else if (!table[index].isOccupied) return false;
		i++;
	}
	return false;
}


bool HashTable_Linear_Probing::remove(const string &key) {
	int Index = fibonacciHash(key);
	int i = 0;
	while (i < size) {
		int index = (Index + i) % size;
		if (table[index].key == key && table[index].isOccupied) {
			table[index].isDeleted = true;
			table[index].isOccupied = false;
			return true;
		}
		else if (!table[index].isOccupied && !table[index].isDeleted) {
			return false;
		}
		i++;
	}
	return false;
}


void HashTable_Linear_Probing::print() {
	for (int i = 0; i < size; i++) {
		if (table[i].isOccupied) {
			cout << i << ": " << table[i].key << " -> " << table[i].value << endl;
		}
		else {
			cout << i << ": Empty " << endl;
		}
	}
}
