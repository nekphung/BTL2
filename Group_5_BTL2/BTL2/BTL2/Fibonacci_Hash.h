#pragma once
#include "Standard Library.h"

using namespace std;

/*
 * Lớp HashTable_Linear_Probing
 * Cài đặt bảng băm sử dụng kỹ thuật Linear Probing (thăm dò tuyến tính)
 * để giải quyết xung đột.
 */
class Fibonacci_Hash {
private:
    /*
     * Cấu trúc đại diện cho một entry trong bảng băm.
     * Bao gồm key, value, và trạng thái của ô (đã dùng hay bị xóa hay chưa).
     */
    struct Entry {
        string key;       // Khóa
        int value;        // Giá trị
        bool isOccupied;  // Cờ đánh dấu đã được sử dụng
        bool isDeleted;   // Cờ đánh dấu đã bị xóa (dùng trong xóa mềm)

        Entry();          // Hàm khởi tạo mặc định
    };

    vector<Entry> table;  // Bảng băm chính
    int size;             // Kích thước bảng băm


    // Hàm băm Fibonacci để phân phối đều hơn
    int fibonacciHash(const string& key);

public:
    // Khởi tạo bảng băm với kích thước cho trước
    Fibonacci_Hash(int tableSize);

    // Thêm hoặc cập nhật giá trị theo key
    bool insert(const string& key, int value);

    // Tìm kiếm key, lưu kết quả vào biến value nếu tìm thấy
    bool search(const string& key, int& value);

    // Xóa key khỏi bảng băm
    bool remove(const string& key);

    // In toàn bộ nội dung bảng băm
    void print();
};
