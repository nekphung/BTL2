#include "Fibonacci_Hash.h"
#include "Traditional_Hash.h"

/*
 * Chương trình minh họa cách sử dụng bảng băm (hash table) với cách xử lý đụng độ tuyến tính.
 * Sử dụng hai hàm băm truyền thống và fibonacci hashing để cải thiện đụng độ có thể xảy ra.
 * Các phần tử sẽ được chèn vào bảng băm và sau đó thực hiện tìm kiếm, xóa nếu cần.
 */

void veMenu() {
    cout << "-------------------------Menu------------------------" << endl;
	cout << "1. Input size of hash table" << endl;
	cout << "2. Insert key-value pair" << endl;
	cout << "3. Search key" << endl;
	cout << "4. Remove key" << endl;
	cout << "5. Exit" << endl;
	cout << "-----------------------------------------------------" << endl;
}

int main() {
    int option = 0;
	int size = 0;
    Traditional_Hash tradiHash(0);
    Fibonacci_Hash fiboHash(0);
	while (true) {
		system("cls");
		cout << "*Table of Traditional Hash*" << endl;
		tradiHash.print();
		cout << "*Table of Fibonacci Hash*" << endl;
		fiboHash.print();
		veMenu();
		cout << "Please enter your option: ";
		cin >> option;
		switch (option) {
		case 1: {
			cout << "Enter the size of the hash table: ";
			cin >> size;
			// Khởi tạo bảng băm với kích thước cho trước
			tradiHash = Traditional_Hash(size);
			fiboHash = Fibonacci_Hash(size);
			cout << "Hash tables created with size " << size << endl;
			system("pause");
			break;
		}
		case 2: {
			if (size == 0) {
				cout << "Please create a hash table first!" << endl;
				break;
			}
			cout << "How many key-value pairs do you want to insert? ";
			int n;
			cin >> n;
			for (int i = 0; i < n; i++) {
				pair<string, int> kv;
				cout << i + 1 << "." << "Enter key and value: ";
				cin >> kv.first;
				cin >> kv.second;
				// Chèn vào bảng băm
				tradiHash.insert(kv.first, kv.second);
				fiboHash.insert(kv.first, kv.second);
			}
			cout << "Inserted " << n << " key-value pairs into both hash tables." << endl;
			system("pause");
			break;
		}
		case 3: {
			if (size == 0) {
				cout << "Please create a hash table first!" << endl;
				break;
			}
			string key;
			cout << "Enter the key to search: ";
			cin >> key;
			int value;
			// Tìm kiếm trong bảng băm truyền thống
			if (tradiHash.search(key, value)) {
				cout << "Found key " << key << " with value " << value << endl;
			}
			else {
				cout << "Key " << key << " not found in traditional hash table." << endl;
			}
			// Tìm kiếm trong bảng băm Fibonacci
			if (fiboHash.search(key, value)) {
				cout << "Found key " << key << " with value " << value << endl;
			}
			else {
				cout << "Key " << key << " not found in fibonacci hash table." << endl;
			}
			system("pause");
			break;
		}
		case 4: {
			if (size == 0) {
				cout << "Please create a hash table first!" << endl;
				break;
			}
			string key;
			cout << "Enter the key to remove: ";
			cin >> key;
			// Xóa trong bảng băm truyền thống
			if (tradiHash.remove(key)) {
				cout << "Key " << key << " removed from traditional hash table." << endl;
			}
			else {
				cout << "Key " << key << " not found in traditional hash table." << endl;
			}
			// Xóa trong bảng băm Fibonacci
			if (fiboHash.remove(key)) {
				cout << "Key " << key << " removed from fibonacci hash table." << endl;
			}
			else {
				cout << "Key " << key << " not found in fibonacci hash table." << endl;
			}
			cout << "Press any key to continue..." << endl;
			system("pause");
			break;
		}
		case 5: {
			cout << "Exiting program..." << endl;
			return 0;
		}
		}
	}
    return 0;
}
