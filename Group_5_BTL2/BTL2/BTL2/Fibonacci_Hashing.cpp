#include "HashTable_Separate_Chaining.h"
#include "HashTable_Linear_Probing.h"
#include "HashTable_Quadratic_Probing.h"

/*
 * Chương trình minh họa cách sử dụng bảng băm (hash table) với phương pháp Separate Chaining, Linear Probing và Quadratic Probing.
 * Các phần tử sẽ được chèn vào bảng băm và sau đó thực hiện tìm kiếm, xóa nếu cần.
 */

int main() {
    //Tạo bảng băm với kích thước 17 
    //HashTable_Separate_Chaining ht(17);
    //HashTable_Linear_Probing ht(17);
      HashTable_Quadratic_Probing ht(17);

    // Danh sách các cặp (khóa, giá trị) cần chèn vào bảng băm
    std::vector<std::pair<std::string, int>> data = {
        {"apple", 5}, {"banana", 8}, {"cherry", 3}, {"date", 12},
        {"grape", 10}, {"lemon", 7}, {"orange", 9}, {"pear", 4},
        {"fig", 6}, {"kiwi", 11}, {"mango", 2}, {"peach", 15},
        {"lemon", 13}, {"apple", 10}  // Thử ghi đè giá trị với key đã tồn tại
    };

    // Chèn từng phần tử vào bảng băm
    for (const auto& item : data) {
        ht.insert(item.first, item.second);
    }

    // In nội dung bảng băm ra màn hình
    std::cout << "Hash Table Contents :" << std::endl;
    ht.print();

    // Thực hiện các phép tìm kiếm
    std::cout << "\nLookup Operations :" << std::endl;
    int value;

    if (ht.search("banana", value)) {
        std::cout << "Found banana with value " << value << std::endl;
    }
    else {
        std::cout << "Could not find banana" << std::endl;
    }

    if (ht.search("kiwi", value)) {
        std::cout << "Found kiwi with value " << value << std::endl;
    }
    else {
        std::cout << "Could not find kiwi" << std::endl;
    }

    return 0;
}
