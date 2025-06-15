## Hash Table Implementation in C++ (Linear Probing with Fibonacci Hashing)
### This project implements a hash table in C++ using:

- Linear Probing for collision resolution
- Fibonacci Hashing for better key distribution

----------------------------

**Overview** 

- This program demonstrates the difference between traditional hashing 
and Fibonacci hashing when handling key collisions using linear probing.
- You can:
 + Create a hash table with custom size
 + Insert key-value pairs manually or from a file
 + Search and delete keys in both hash tables
 + Compare performance of two hashing strategies

----------------------------

**Features** 

*Linear Probing*

- Uses open addressing for collision resolution
- Simple and efficient for insertion, searching, and deletion
- Works well when combined with better hash functions

*Fibonacci Hashing*

- Uses the golden ratio to spread keys more uniformly
- Reduces clustering and improves collision handling

*Supported Operations*

- Insert key-value pairs (manually or via file)
- Search for a specific key
- Delete a key
- Display the internal state of both hash tables

----------------------------

**How to Build and Run** 

Using Visual Studio 2022:

- Open Visual Studio 2022 and create a new C++ Console Application.
- Add the following source files to your project:
   + main.cpp
   + Traditional_Hash.h, Traditional_Hash.cpp
   + Fibonacci_Hash.h, Fibonacci_Hash.cpp
- Add Data.txt to the project directory if using file input.
- Build the solution (Ctrl + Shift + B).
- Run the program (F5 or Ctrl + F5).

----------------------------

**File Structure** 

📁 ProjectRoot
├── main.cpp                   // Program with menu and interaction
├── Traditional_Hash.h/.cpp    // Traditional modulo-based hashing
├── Fibonacci_Hash.h/.cpp      // Fibonacci hashing logic
├── Data.txt                   // Optional file input

----------------------------

**Input File Format (Data.txt)** 

 - First line number of entries (n)
 - Next n lines each line contains a key and value separated by space
 - Example: 
        ---------------
        | 6           |
        | apple 5     |
        | lemon 7     |
        | cherry 3    |
        | date 12     |
        | grape 10    |
        | banana 8    |
        ---------------
----------------------------

**Future Improvements** 

- Added support for advanced collision resolution techniques such as **double hashing** or **quadratic probing** to reduce clustering.
- Added functionality to **record collision counts**, probe length, and hash table performance statistics.
- Integrated **hash table visualization** functionality for learning or algorithm illustration purposes.

----------------------------

**Notes** 

- The hash table will automatically resize when the load factor exceeds 70% (doubles the size) 
  or decreases to below 30% (halves), helping to maintain stable performance.
- With the Fibonacci hash function, the table size is always maintained as a power of 2 
  (eg: 32, 64, 128, ...), so that the bitwise multiplication and shifting work efficiently 
  and ensure even distribution.
- The hash function can be customized or optimized to suit the input data characteristics 
  and usage purposes.
- Avoid using keys with periodicity or repeating patterns (eg: evenly divisible keys, 
  steadily increasing keys) because it can cause clustering (elements are concentrated in the same memory area), reducing performance.
- Choosing diverse and well-distributed input data will help the hash table work more 
  effectively, especially when using collision resolution techniques such as linear and other techniques.

----------------------------



