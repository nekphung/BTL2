#include "HashTable_Linear_Probing.h"
#include <cmath>  // Để dùng log2

// Hàm tạo: khởi tạo bảng băm với kích thước cho trước
HashTable_Linear_Probing::HashTable_Linear_Probing(int tableSize) : size(tableSize) {
    table.resize(size);  // Cấp phát bảng với số ô bằng size
}

// Constructor mặc định của Entry
HashTable_Linear_Probing::Entry::Entry() : key(""), value(0), isOccupied(false), isDeleted(false) {}

// Hàm băm đơn giản: tính tổng ASCII các ký tự trong chuỗi rồi mod với kích thước bảng
int HashTable_Linear_Probing::hashFunction(const std::string& key) {
    int sum = 0;
    for (char c : key) {
        sum += static_cast<int>(c);
    }
    if ((size & (size - 1)) == 0) return sum & (size - 1);
    else return sum % size;
}

// Hàm băm Fibonacci: sử dụng nhân với hằng số vàng để phân bố khóa đều hơn
int HashTable_Linear_Probing::fibonacciHash(const std::string& key) {
    const unsigned long long FIB_MULT = 11400714819323198485ull; // ≈ 2^64 / φ (phi)
    unsigned long long hash = 0;

    // Hash theo cách nhân với 31 mỗi ký tự (phổ biến như trong Java)
    for (char c : key) {
        hash = hash * 31 + c;
    }

    int shift = 64 - static_cast<int>(log2(size)); // Giả sử size là lũy thừa của 2
    return (hash * FIB_MULT) >> shift;
}

// Hàm chèn phần tử vào bảng băm
bool HashTable_Linear_Probing::insert(const std::string& key, int value) {
    int baseIndex = fibonacciHash(key);
    int i = 0;

    // Tìm vị trí trống (linear probing)
    while (i < size) {
        int index = (baseIndex + i) % size;
        if (!table[index].isOccupied) {
            // Ghi đè vào vị trí trống
            table[index].key = key;
            table[index].value = value;
            table[index].isOccupied = true;
            table[index].isDeleted = false;
            return true;
        }
        else if (table[index].key == key) {
            // Nếu khóa đã tồn tại, cập nhật giá trị
            table[index].value = value;
            return true;
        }
        i++;
    }

    return false; // Bảng đầy
}

// Tìm kiếm một khóa và gán giá trị nếu tìm thấy
bool HashTable_Linear_Probing::search(const std::string& key, int& value) {
    int baseIndex = fibonacciHash(key);
    int i = 0;

    while (i < size) {
        int index = (baseIndex + i) % size;

        if (table[index].isOccupied && table[index].key == key) {
            value = table[index].value;
            return true;
        }
        else if (!table[index].isOccupied && !table[index].isDeleted) {
            // Nếu gặp vị trí chưa từng được ghi, dừng tìm kiếm
            return false;
        }
        i++;
    }

    return false;
}

// Xóa phần tử khỏi bảng băm
bool HashTable_Linear_Probing::remove(const std::string& key) {
    int baseIndex = fibonacciHash(key);
    int i = 0;

    while (i < size) {
        int index = (baseIndex + i) % size;

        if (table[index].isOccupied && table[index].key == key) {
            // Đánh dấu là đã xóa nhưng không giải phóng để tránh phá vỡ chuỗi probing
            table[index].isOccupied = false;
            table[index].isDeleted = true;
            return true;
        }
        else if (!table[index].isOccupied && !table[index].isDeleted) {
            // Nếu gặp ô chưa từng được ghi, dừng
            return false;
        }

        i++;
    }

    return false;
}

// In nội dung bảng băm ra màn hình
void HashTable_Linear_Probing::print() {
    for (int i = 0; i < size; i++) {
        if (table[i].isOccupied) {
            std::cout << i << ": " << table[i].key << " -> " << table[i].value << std::endl;
        }
        else {
            std::cout << i << ": Empty" << std::endl;
        }
    }
}
