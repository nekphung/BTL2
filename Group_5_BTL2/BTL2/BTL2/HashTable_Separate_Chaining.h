#pragma once
#include <iostream>
#include <vector>
#include <string>


using namespace std;

class HashTable_Separate_Chaining {
private:
    struct Node {
        string key;
        int value;
        Node* next;

        Node(const string& k, int v);
    };

    vector<Node*> table;
    int size;

    int hashFunction(const string& key);
    int fibonacciHash(const string& key);

public:
    HashTable_Separate_Chaining(int tableSize); 
    void insert(const string& key, int value);
    bool search(const string& key, int& value);
    bool remove(const string& key);
    void print();
};

