#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class HashTable_Double_Probing {
private:
    struct Entry {
        string key;
        int value;
        bool isOccupied;
       // bool isDeleted;
        Entry();
    };

    vector<Entry> table;
    int size;
    int count;

    int hash1(const string& key);
    int hash2(const string& key);
    bool isPrime(int n);
    int largestPrimeLessThan(int n);

public:
    HashTable_Double_Probing(int tableSize);
    bool insert(const string& key, int value);
    bool search(const string& key, int& value);
   // bool remove(const string& key);
    void print();

};
