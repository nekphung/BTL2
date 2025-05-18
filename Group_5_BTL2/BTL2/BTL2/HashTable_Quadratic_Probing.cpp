#include "HashTable_Quadratic_Probing.h"
#include <cmath>  // Để sử dụng log2

// Constructor: khởi tạo bảng băm với kích thước cho trước, gán số phần tử ban đầu là 0
HashTable_Quadratic_Probing::HashTable_Quadratic_Probing(int tableSize) : size(tableSize), count(0) {
    table.resize(size);
}

// Constructor mặc định của một entry trong bảng băm
HashTable_Quadratic_Probing::Entry::Entry() : key(""), value(0), isOccupied(false), isDeleted(false) {}

// Hàm băm đơn giản: tính tổng mã ASCII các ký tự trong chuỗi rồi lấy mod kích thước bảng
int HashTable_Quadratic_Probing::hashFunction(const std::string& key) {
    int sum = 0;
    for (char c : key) {
        sum += static_cast<int>(c);
    }
    if ((size & (size - 1)) == 0) return sum & (size - 1);
    else return sum % size;
}

// Hàm băm Fibonacci: sử dụng hằng số vàng để phân bố khóa tốt hơn trong bảng
int HashTable_Quadratic_Probing::fibonacciHash(const std::string& key) {
    const unsigned long long FIB_MULT = 11400714819323198485ull; // ≈ 2^64 / phi
    unsigned long long hash = 0;

    for (char c : key) {
        hash = hash * 31 + c;  // Tương tự cách hash trong Java
    }

    int shift = 64 - static_cast<int>(log2(size));  // Giả định size là 2^k
    return (hash * FIB_MULT) >> shift;
}

// Hàm chèn phần tử vào bảng băm bằng phương pháp Quadratic Probing
bool HashTable_Quadratic_Probing::insert(const std::string& key, int value) {
    // Kiểm tra ngưỡng tải: nếu vượt quá 70% thì từ chối chèn để tránh quá tải
    int occupied = 0;
    for (int i = 0; i < size; i++) {
        if (table[i].isOccupied) occupied++;
    }
    if (occupied >= 0.7 * size) {
        rehash(); // mở rộng bảng băm
    }

    int baseIndex = fibonacciHash(key);  // Có thể thay bằng fibonacciHash(key) nếu muốn
    int i = 0;

    while (i < size) {
        int index = (baseIndex + i * i) % size;

        if (!table[index].isOccupied || table[index].isDeleted) {
            // Ghi đè vào ô trống hoặc đã xóa
            table[index].key = key;
            table[index].value = value;
            table[index].isOccupied = true;
            table[index].isDeleted = false;
            return true;
        }
        else if (table[index].key == key) {
            // Cập nhật giá trị nếu khóa đã tồn tại
            table[index].value = value;
            return true;
        }

        i++;
    }

    return false; // Bảng đầy, không thể chèn
}

void HashTable_Quadratic_Probing::rehash() {
    int oldSize = size; // gán lại giá trị cũ
    size *= 2; // cập nhật giá trị mới cho size 
    vector<Entry> oldTable = table; // gán bảng cũ cho oldTable

    table.clear(); // Xóa table cũ
    table.resize(size); // Constructor: khởi tạo bảng băm với kích thước cho trước, gán số phần tử ban đầu là 0

    count = 0; // gán lại count ban đầu = 0

    for (const Entry x : oldTable) {
        if (x.isOccupied && !x.isDeleted) {
            insert(x.key, x.value); // chèn các phần tử ở bảng cũ qua bảng mới
        }
    }
}


// Tìm kiếm phần tử trong bảng băm
bool HashTable_Quadratic_Probing::search(const std::string& key, int& value) {
    int baseIndex = fibonacciHash(key);
    int i = 0;

    while (i < size) {
        int index = (baseIndex + i * i) % size;

        if (table[index].isOccupied && table[index].key == key) {
            value = table[index].value;
            return true;
        }

        // Nếu gặp ô chưa từng được ghi, dừng tìm kiếm
        if (!table[index].isOccupied && !table[index].isDeleted) {
            return false;
        }

        i++;
    }

    return false;
}

// Xóa phần tử khỏi bảng băm
bool HashTable_Quadratic_Probing::remove(const std::string& key) {
    int baseIndex = fibonacciHash(key);
    int i = 0;

    while (i < size) {
        int index = (baseIndex + i * i) % size;

        if (table[index].isOccupied && table[index].key == key) {
            // Đánh dấu ô là đã xóa
            table[index].isOccupied = false;
            table[index].isDeleted = true;
            return true;
        }

        if (!table[index].isOccupied && !table[index].isDeleted) {
            return false;  // Không tồn tại trong bảng
        }

        i++;
    }

    return false;
}

// In nội dung của bảng băm
void HashTable_Quadratic_Probing::print() {
    for (int i = 0; i < size; i++) {
        if (table[i].isOccupied && !table[i].isDeleted) {
            std::cout << i << ": " << table[i].key << " -> " << table[i].value << std::endl;
        }
        else if (table[i].isDeleted) {
            std::cout << i << ": Deleted" << std::endl;
        }
        else {
            std::cout << i << ": Empty" << std::endl;
        }
    }
}
