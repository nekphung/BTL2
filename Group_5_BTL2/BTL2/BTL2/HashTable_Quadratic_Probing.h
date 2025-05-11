#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class HashTable_Quadratic_Probing {
private:
    struct Entry {
        string key;
        int value;
        bool isOccupied;
        bool isDeleted;
        Entry();
    };

    vector <Entry> table;
    int size;
    int count;

    int hashFunction(const string& key);
    int fibonacciHash(const string& key);

public:
    HashTable_Quadratic_Probing(int tableSize);
    bool insert(const string& key, int value);
    bool search(const string& key, int& value);
    bool remove(const string& key);
    void print();
};

