#include "HashTable_Separate_Chaining.h"
#include <cmath> // log2

// Constructor của Node, lưu trữ key-value và con trỏ next
HashTable_Separate_Chaining::Node::Node(const std::string& k, int v)
    : key(k), value(v), next(nullptr) {}

// Hàm băm đơn giản: tính tổng mã ASCII các ký tự rồi mod với kích thước bảng
int HashTable_Separate_Chaining::hashFunction(const std::string& key) {
    int sum = 0;
    for (char c : key) {
        sum += static_cast<int>(c);
    }
    if ((size & (size - 1)) == 0) return sum & (size - 1);
    else return sum % size;
}

// Hàm băm Fibonacci (tùy chọn, bạn có thể thay thế hàm băm đơn giản bằng hàm này)
int HashTable_Separate_Chaining::fibonacciHash(const std::string& key) {
    const unsigned long long FIB_MULT = 11400714819323198485ull; // ~2^64 / phi
    unsigned long long hash = 0;

    for (char c : key) {
        hash = hash * 31 + c;
    }

    int shift = 64 - static_cast<int>(log2(size)); // size giả định là 2^k
    return (hash * FIB_MULT) >> shift;
}

// Khởi tạo bảng băm với số bucket bằng tableSize
HashTable_Separate_Chaining::HashTable_Separate_Chaining(int tableSize) : size(tableSize) {
    table.resize(size, nullptr);  // Khởi tạo mỗi bucket là con trỏ null
}

// Hàm chèn key-value vào bảng băm
void HashTable_Separate_Chaining::insert(const std::string& key, int value) {
    int index = fibonacciHash(key);
    Node* current = table[index];
    Node* newnode = new Node(key, value);

    // Nếu bucket trống, gán node mới
    if (current == nullptr) {
        table[index] = newnode;
    }
    else {
        Node* temp = current;
        bool isNew = true;

        // Duyệt danh sách liên kết để kiểm tra trùng key
        while (temp != nullptr) {
            if (temp->key == key) {
                temp->value = value; // Ghi đè nếu key trùng
                isNew = false;
                break;
            }
            if (temp->next == nullptr) break;
            temp = temp->next;
        }

        if (isNew) temp->next = newnode; // Thêm node vào cuối nếu key chưa tồn tại
    }
}

// Hàm tìm kiếm key trong bảng
bool HashTable_Separate_Chaining::search(const std::string& key, int& value) {
    int index = fibonacciHash(key);
    Node* current = table[index];

    while (current != nullptr) {
        if (current->key == key) {
            value = current->value;
            return true;
        }
        current = current->next;
    }

    return false;
}

// Hàm xóa một key khỏi bảng
bool HashTable_Separate_Chaining::remove(const std::string& key) {
    int index = fibonacciHash(key);
    Node* current = table[index];
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->key == key) {
            if (prev == nullptr) {
                table[index] = current->next;  // Xóa node đầu danh sách
            }
            else {
                prev->next = current->next;    // Xóa node ở giữa hoặc cuối
            }
            delete current;
            return true;
        }
        prev = current;
        current = current->next;
    }

    return false;
}

// Hàm in toàn bộ nội dung của bảng
void HashTable_Separate_Chaining::print() {
    for (int i = 0; i < size; i++) {
        std::cout << "Bucket " << i << ": ";
        Node* current = table[i];
        if (!current) {
            std::cout << "Empty";
        }
        while (current) {
            std::cout << "(" << current->key << ", " << current->value << ") ";
            current = current->next;
        }
        std::cout << std::endl;
    }
}
