#include "Fibonacci_Hash.h"
#include "Traditional_Hash.h"

/*
 * Chương trình minh họa cách sử dụng bảng băm (hash table) với cách xử lý đụng độ tuyến tính.
 * Sử dụng hai hàm băm truyền thống và fibonacci hashing để cải thiện đụng độ có thể xảy ra.
 * Các phần tử sẽ được chèn vào bảng băm và sau đó thực hiện tìm kiếm, xóa nếu cần.
 */
//dhwuohdowhdou
int main() {
    //Tạo bảng băm với kích thước 17 
    Traditional_Hash th(17); // Sử dụng hàm băm truyền thống
    Fibonacci_Hash fh(17); // Sử dụng hàm băm fibonacci

    // Danh sách các cặp (khóa, giá trị) cần chèn vào bảng băm
    vector<pair<string, int>> data = {
        {"apple", 5}, {"banana", 8}, {"cherry", 3}, {"date", 12},
        {"grape", 10}, {"lemon", 7}, {"orange", 9}, {"pear", 4},
        {"fig", 6}, {"kiwi", 11}, {"mango", 2}, {"peach", 15},
        {"lemon", 13}, {"apple", 10}  // Thử ghi đè giá trị với key đã tồn tại
    };

    // Chèn từng phần tử vào bảng băm
    for (const auto& item : data) {
        th.insert(item.first, item.second);
        fh.insert(item.first, item.second);
    }

    // In nội dung bảng băm ra màn hình
    cout << " ------ Hash table with traditional hash function ------ " << endl;
    th.print();
    cout << " ------ Hash table with fibonacci hash function ------ " << endl;
    fh.print();
    cout << " ---------------- Lookup Operations -------------------- " << endl;
    // Thực hiện các phép tìm kiếm
    int value;

    if (th.search("banana", value)) {
        cout << "Found banana with value " << value << std::endl;
    }
    else {
        cout << "Could not find banana" << std::endl;
    }

    if (th.search("kiwi", value)) {
        cout << "Found kiwi with value " << value << std::endl;
    }
    else {
        cout << "Could not find kiwi" << std::endl;
    }
    return 0;
}
