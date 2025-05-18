#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 * Lớp HashTable_Separate_Chaining
 * Cài đặt bảng băm sử dụng kỹ thuật Separate Chaining (xâu chuỗi) để xử lý va chạm.
 * Mỗi bucket là một danh sách liên kết các phần tử có cùng chỉ số băm.
 */
class HashTable_Separate_Chaining {
private:
    /*
     * Cấu trúc Node biểu diễn một phần tử trong danh sách liên kết tại mỗi bucket.
     */
    struct Node {
        string key;   // Khóa của phần tử
        int value;    // Giá trị tương ứng với khóa
        Node* next;   // Con trỏ đến phần tử tiếp theo trong danh sách

        Node(const string& k, int v); // Constructor
    };

    vector<Node*> table;  // Bảng băm chính (mỗi phần tử là đầu danh sách liên kết)
    int size;             // Kích thước bảng băm

    // Hàm băm đơn giản dựa trên tổng mã ASCII
    int hashFunction(const string& key);

    // Hàm băm nâng cao sử dụng kỹ thuật Fibonacci Hashing
    int fibonacciHash(const string& key);

public:
    // Constructor: khởi tạo bảng băm với số lượng bucket cho trước
    HashTable_Separate_Chaining(int tableSize);

    // Thêm hoặc cập nhật cặp (key, value) vào bảng băm
    void insert(const string& key, int value);

    // Tìm giá trị tương ứng với key. Trả về true nếu tìm thấy, false nếu không.
    bool search(const string& key, int& value);

    // Xóa phần tử có khóa tương ứng khỏi bảng băm
    bool remove(const string& key);

    // In toàn bộ bảng băm: hiển thị các bucket và danh sách liên kết tương ứng
    void print();
};
