#include "HashTable_Double_Probing.h"

HashTable_Double_Probing::HashTable_Double_Probing(int tableSize) : size(tableSize), count(0) {
    table.resize(size);
}

HashTable_Double_Probing::Entry::Entry() : key(""), value(0), isOccupied(false) {}

int HashTable_Double_Probing::hash1(const string& key) {
    int sum = 0;
    for (char c : key) {
        sum += static_cast<int>(c);
    }
    return sum % size;
}

bool HashTable_Double_Probing::isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}


int HashTable_Double_Probing::largestPrimeLessThan(int n) {
    for (int i = n - 1; i >= 2; i--) {
        if (isPrime(i)) return i;
    }
    return 2;
}

int HashTable_Double_Probing::hash2(const string& key) {
    int R = largestPrimeLessThan(size);
    int keyhash = hash1(key);
    return R - (keyhash % R);
}

bool HashTable_Double_Probing::insert(const std::string& key, int value) {
    int occupied = 0;
    for (int i = 0; i < size; i++) {
        if (table[i].isOccupied) occupied++;
    }
    if (occupied >= 0.7 * size) return false;

    int Index = hash1(key);
    int i = 0;
    while (i < size) {
        int index = (Index + i * hash2(key)) % size;
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

bool HashTable_Double_Probing::search(const std::string& key, int& value) {
    int Index = hash1(key);
    int i = 0;
    while (i < size) {
        int index = (Index + i * hash2(key)) % size;
        if (table[index].key == key) {
            value = table[index].value;
            return true;
        }
        else if (!table[index].isOccupied)
        {
            return false;
        }
        i++;
    }
    return false;
}

void HashTable_Double_Probing::print() {
    for (int i = 0; i < size; i++) {
        if (table[i].isOccupied) {
            cout << i << ": " << table[i].key << " -> " << table[i].value << endl;
        }
        else {
            cout << i << ": Empty" << endl;
        }
    }
}
