#include "Traditional_Hash.h"
#include <cmath>  // Để dùng log2

// Hàm tạo: khởi tạo bảng băm với kích thước cho trước
Traditional_Hash::Traditional_Hash(int tableSize) : size(tableSize) {
    table.resize(size);  // Cấp phát bảng với số ô bằng size
}

// Constructor mặc định của Entry
Traditional_Hash::Entry::Entry() : key(""), value(0), isOccupied(false), isDeleted(false) {}

// Hàm băm đơn giản: tính tổng ASCII các ký tự trong chuỗi rồi mod với kích thước bảng
int Traditional_Hash::hashFunction(const std::string& key) {
    int sum = 0;
    for (char c : key) {
        sum += static_cast<int>(c);
    }
    if ((size & (size - 1)) == 0) return sum & (size - 1);
    else return sum % size;
}

// Hàm chèn phần tử vào bảng băm
bool Traditional_Hash::insert(const std::string& key, int value) {
    int baseIndex = hashFunction(key);
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
bool Traditional_Hash::search(const std::string& key, int& value) {
    int baseIndex = hashFunction(key);
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
bool Traditional_Hash::remove(const std::string& key) {
    int baseIndex = hashFunction(key);
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
void Traditional_Hash::print() {
    if (table.size() == 0) {
		std::cout << "Hash table is empty." << std::endl;
		return;
	}
    for (int i = 0; i < size; i++) {
        if (table[i].isOccupied) {
            std::cout << i << ": " << table[i].key << " -> " << table[i].value << std::endl;
        }
        else {
            std::cout << i << ": Empty" << std::endl;
        }
    }
}
