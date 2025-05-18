#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 * Lớp HashTable_Quadratic_Probing
 * Cài đặt bảng băm sử dụng phương pháp Quadratic Probing (thăm dò bậc hai)
 * để xử lý xung đột khi xảy ra va chạm hàm băm.
 */
class HashTable_Quadratic_Probing {
private:
    /*
     * Entry đại diện cho một phần tử trong bảng băm.
     * Mỗi ô lưu trữ một khóa, giá trị, và các cờ đánh dấu trạng thái.
     */
    struct Entry {
        string key;       // Khóa
        int value;        // Giá trị tương ứng với khóa
        bool isOccupied;  // Ô này có đang được sử dụng không?
        bool isDeleted;   // Ô này có bị xóa mềm không?

        Entry();          // Hàm tạo mặc định
    };

    vector<Entry> table;  // Mảng lưu trữ các entry
    int size;             // Kích thước bảng băm
    int count;            // Số lượng phần tử hiện tại trong bảng

    // Hàm băm đơn giản: tính tổng mã ASCII và lấy modulo kích thước
    int hashFunction(const string& key);

    // Hàm băm sử dụng Fibonacci hashing để cải thiện phân phối
    int fibonacciHash(const string& key);

public:
    // Hàm khởi tạo: khởi tạo bảng băm với kích thước cho trước
    HashTable_Quadratic_Probing(int tableSize);

    // Hàm thêm phần tử (key, value) vào bảng. Nếu key đã tồn tại thì cập nhật value.
    bool insert(const string& key, int value);

    // Tìm kiếm giá trị theo key, lưu kết quả vào value nếu tìm thấy
    bool search(const string& key, int& value);

    // Xóa một phần tử theo key (xóa mềm)
    bool remove(const string& key);
    // Hàm mở rộng bảng băm
    void rehash();

    // In ra toàn bộ nội dung bảng băm
    void print();
};
