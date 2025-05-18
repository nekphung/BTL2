# Hash Table Implementations in C++

This project implements three hash table types in C++ (using Fibonacci hashing):

- Separate Chaining
- Linear Probing 
- Quadratic Probing

## How to Build and Run

### Using Visual Studio 2022

1. **Create or open a C++ project/solution**:
   - Open Visual Studio 2022.
   - Create a new C++ Console Application project, or open your existing project.

2. **Add source files**:
   - Add all `.cpp` and `.h` files of the project into your project (Right-click on project > Add > Existing Item).

3. **Build the project**:
   - Use **Build > Build Solution** or press `Ctrl + Shift + B` to compile the code.

4. **Run the program**:
   - Press `F5` to run with debugger or `Ctrl + F5` to run without debugging.

---

## Features

- **Separate Chaining:**  
  Uses linked lists to handle collisions at the same hash index.  
  Suitable for high load factors without significant performance loss.

- **Linear Probing:**  
  Uses linear probing with Fibonacci hashing for better key distribution.  
  Provides fast insert, search, and delete operations with good cache performance.

- **Quadratic Probing:**  
  Resolves collisions using quadratic probing to reduce clustering.  
  Includes a load factor check (max 70%) to maintain efficient operations.

- **Common Operations:**  
  - Insert, search, and remove supported for all three hash table types.  
  - Print function to display the hash table's contents and state.

- **Hash Functions:**  
  Combines simple modulo hash and Fibonacci hashing for improved distribution.

- **Limitations:**  
  No automatic resizing implemented; users should manage table size manually.

---

## Notes

- No automatic resizing implemented.
- You can customize or extend the hash functions as needed.

---

