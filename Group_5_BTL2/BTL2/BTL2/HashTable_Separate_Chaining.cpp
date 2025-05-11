#include "HashTable_Separate_Chaining.h"

HashTable_Separate_Chaining::Node::Node(const string& k, int v) : key(k), value(v), next(nullptr) {}

int HashTable_Separate_Chaining::hashFunction(const string& key) {
    int sum = 0;
    for (char c : key) {
        sum += static_cast<int>(c);
    }
    return sum % size;
}

int HashTable_Separate_Chaining::fibonacciHash(const string& key) {
    const unsigned long long FIB_MULT = 11400714819323198485ull; // ~2^64 / phi
    unsigned long long hash = 0;

    for (char c : key) {
        hash = hash * 31 + c;
    }
    int shift = 64 - static_cast<int>(log2(size)); // size = 2^k
    return (hash * FIB_MULT) >> shift;
}

HashTable_Separate_Chaining::HashTable_Separate_Chaining(int tableSize) : size(tableSize) {
    table.resize(size, nullptr);
}

void HashTable_Separate_Chaining::insert(const string& key, int value) {
    int index = hashFunction(key);
    Node* current = table[index];
    Node* newnode = new Node(key, value);
    if (current == NULL) {
        table[index] = newnode;
    }
    else
    {
        Node* temp = current;
        bool check = true;
        while (temp != NULL) {
            if (temp->key == key) {
                temp->value = value;
                check = false;
                break;
            }
            if (temp->next == NULL) break;
            temp = temp->next;
        }
        if (check) temp->next = newnode;
    }
}

bool HashTable_Separate_Chaining::search(const string& key, int& value) {
    int index = hashFunction(key);
    Node* current = table[index];
    while (current != NULL) {
        if (current->key == key) {
            value = current->value;
            return true;
        }
        current = current->next;
    }
    return false; 
}

bool HashTable_Separate_Chaining::remove(const string& key) {
    int index = hashFunction(key);
    Node* current = table[index];
    Node* prev = NULL;
    while (current != NULL) {
        if (current->key == key) {
            if (prev == NULL) {
                table[index] = current->next;
            }
            else {
                prev->next = current->next;
            }
            delete current;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

void HashTable_Separate_Chaining::print() {
    for (int i = 0; i < size; i++) {
        cout << "Bucket " << i << ": ";
        Node* current = table[i];
        if (!current) {
            cout << "Empty";
        }
        while (current) {
            cout << "(" << current->key << ", " << current->value << ") ";
            current = current->next;
        }
        cout << endl;
    }
}
