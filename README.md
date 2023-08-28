# Doubly Linked List (DLList) Implementation

This project provides an implementation of a doubly linked list (DLList) in C++. The DLList class allows you to create, manipulate, and manage a list of elements with constant-time insertions and deletions at both the beginning and end.

## Table of Contents

- [Features](#features)
- [Usage](#usage)
- [API](#api)
- [Building and Running](#building-and-running)
- [Contributing](#contributing)

## Features

- Efficient doubly linked list implementation.
- Supports constant-time insertions and deletions at both ends of the list.
- Provides copy constructor, move constructor, copy assignment, and move assignment operations.
- Handles memory management for added and removed elements.

## Usage

1. Include the `DLList.h` header in your C++ project.
2. Create an instance of the `DLList` class using appropriate data types.
3. Use the provided member functions to manipulate the list.
4. Compile and run your program.

## API

- `DLList()`: Constructor to initialize an empty doubly linked list.
- `DLList(const DLList& other)`: Copy constructor to create a copy of another list.
- `DLList(DLList&& other) noexcept`: Move constructor to take ownership of another list's resources.
- `DLList& operator=(const DLList& other)`: Copy assignment operator to copy elements from another list.
- `DLList& operator=(DLList&& other) noexcept`: Move assignment operator to take ownership of another list's resources.
- `~DLList()`: Destructor to clean up allocated memory.
- `void insert(int pos, const T& item)`: Insert an element at a specified position.
- `void erase(int pos)`: Erase an element at a specified position.
- `bool empty() const`: Check if the list is empty.
- `T get_value(int pos)`: Get the value of an element at a specified position.
- `int size() const`: Get the number of elements in the list.
- `void clear() noexcept`: Clear the list and free memory.
- `DLLNode<T>* move_to_pos(int i)`: Move to the node at a specified position.

## Building and Running

Compile your C++ code along with the `DLList.cpp` and `DLLNode.cpp` files:

```bash
g++ -o main main.cpp DLList.cpp DLLNode.cpp
```

Run the compiled executable:

```bash
./main
```

## Contributing

Contributions to this project are welcome! Feel free to submit issues and pull requests.
