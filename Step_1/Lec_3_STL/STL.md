# C++ STL (Standard Template Library) Guide

A comprehensive guide covering the most commonly used C++ STL containers, data structures, and utility functions. This code demonstrates practical usage of various STL components.

## Table of Contents

1. [Pairs](#pairs)
2. [Vectors](#vectors)
3. [Lists](#lists)
4. [Deques](#deques)
5. [Stacks](#stacks)
6. [Queues](#queues)
7. [Priority Queues](#priority-queues)
8. [Sets](#sets)
9. [Multisets](#multisets)
10. [Unordered Sets](#unordered-sets)
11. [Maps](#maps)
12. [Multimaps](#multimaps)
13. [Unordered Maps](#unordered-maps)
14. [Algorithms & Functions](#algorithms--functions)

## Data Structures Overview

### Pairs
Store two values together as a single unit.
```cpp
pair<int, int> p = {1, 3};
pair<int, pair<int, int>> nested = {1, {3, 4}};
```

### Vectors
Dynamic arrays that can grow or shrink in size.
- **Time Complexity**: 
  - Access: O(1)
  - Insert/Delete at end: O(1) amortized
  - Insert/Delete at middle: O(n)
- **Common Operations**: `push_back()`, `pop_back()`, `size()`, `clear()`, `erase()`, `insert()`

### Lists
Doubly linked list implementation.
- **Time Complexity**: 
  - Insert/Delete: O(1) at known position
  - Access: O(n)
- **Common Operations**: `push_front()`, `push_back()`, `pop_front()`, `pop_back()`

### Deques
Double-ended queue allowing insertion/deletion at both ends.
- **Time Complexity**: 
  - Insert/Delete at ends: O(1)
  - Access: O(1)
- **Common Operations**: `push_front()`, `push_back()`, `pop_front()`, `pop_back()`, `front()`, `back()`

### Stacks
LIFO (Last In First Out) data structure.
- **Time Complexity**: All operations O(1)
- **Common Operations**: `push()`, `pop()`, `top()`, `empty()`, `size()`

### Queues
FIFO (First In First Out) data structure.
- **Time Complexity**: All operations O(1)
- **Common Operations**: `push()`, `pop()`, `front()`, `back()`, `empty()`, `size()`

### Priority Queues
Heap-based structure where elements are ordered by priority.
- **Max Heap** (default): Largest element at top
- **Min Heap**: Smallest element at top
- **Time Complexity**: 
  - Insert: O(log n)
  - Delete: O(log n)
  - Access top: O(1)

### Sets
Ordered collection of unique elements.
- **Time Complexity**: 
  - Insert/Delete/Find: O(log n)
- **Features**: Automatically sorted, no duplicates
- **Common Operations**: `insert()`, `erase()`, `find()`, `count()`, `lower_bound()`, `upper_bound()`

### Multisets
Ordered collection allowing duplicate elements.
- **Time Complexity**: Same as sets
- **Features**: Sorted, allows duplicates
- **Note**: `erase(value)` removes all occurrences, `erase(iterator)` removes one

### Unordered Sets
Hash-based unique element collection.
- **Time Complexity**: 
  - Average: O(1) for insert/delete/find
  - Worst case: O(n)
- **Features**: No ordering, no duplicates, faster than set

### Maps
Key-value pairs with unique keys, ordered by key.
- **Time Complexity**: O(log n) for operations
- **Features**: Automatically sorted by keys
- **Common Operations**: `insert()`, `erase()`, `find()`, `[]` operator

### Multimaps
Key-value pairs allowing duplicate keys.
- **Time Complexity**: Same as maps
- **Features**: Sorted by keys, allows duplicate keys
- **Note**: Cannot use `[]` operator

### Unordered Maps
Hash-based key-value pairs.
- **Time Complexity**: 
  - Average: O(1)
  - Worst case: O(n)
- **Features**: No ordering, faster than map

## Algorithms & Functions

### Sorting
```cpp
sort(v.begin(), v.end());              // Ascending
sort(v.begin(), v.end(), greater<int>()); // Descending
sort(arr, arr+n, comp);                // Custom comparator
```

### Reversing
```cpp
reverse(v.begin(), v.end());
```

### Permutations
```cpp
next_permutation(s.begin(), s.end()); // Returns next permutation
```

### Min/Max
```cpp
min(a, b);
max(a, b);
*max_element(arr, arr+n);
*min_element(arr, arr+n);
```

### Bit Manipulation
```cpp
__builtin_popcount(n);    // Count set bits (int)
__builtin_popcountll(n);  // Count set bits (long long)
```

## How to Compile and Run

### Basic compilation:
```powershell
g++ STL.cpp -o STL.exe
.\STL.exe
```

### Quick compile and run:
```powershell
g++ STL.cpp -o STL.exe; if ($?) { .\STL.exe }
```

## Code Structure

Each STL component is implemented in a separate function:
- `pairs()` - Pair demonstrations
- `vectors()` - Vector operations
- `lists()` - List operations
- `Deques()` - Deque operations
- `stacks()` - Stack operations
- `queues()` - Queue operations
- `priority_queues()` - Priority queue (heap) operations
- `sets()` - Set operations
- `multisets()` - Multiset operations
- `unorderedsets()` - Unordered set operations
- `maps()` - Map operations
- `multimaps()` - Multimap operations
- `unorderedmaps()` - Unordered map operations
- `functions1()` - STL algorithms and utility functions

Uncomment the desired function calls in `main()` to see examples.

## Quick Reference

| Container       | Ordering        | Duplicates | Time Complexity (Insert/Find) | Use Case                  |
|-----------------|-----------------|------------|-------------------------------|---------------------------|
| Vector          | No              | Yes        | O(1) / O(n)                   | Dynamic array             |
| List            | No              | Yes        | O(1) / O(n)                   | Frequent insert/delete    |
| Deque           | No              | Yes        | O(1) / O(1)                   | Insert/delete at ends     |
| Set             | Yes             | No         | O(log n) / O(log n)           | Unique sorted elements    |
| Multiset        | Yes             | Yes        | O(log n) / O(log n)           | Sorted with duplicates    |
| Unordered Set   | No              | No         | O(1) avg / O(1) avg           | Fast unique lookup        |
| Map             | Yes (by key)    | No         | O(log n) / O(log n)           | Sorted key-value storage  |
| Multimap        | Yes (by key)    | Yes        | O(log n) / O(log n)           | Multiple values per key   |
| Unordered Map   | No              | No         | O(1) avg / O(1) avg           | Fast key-value lookup     |

## Notes

- Use `#include <bits/stdc++.h>` for quick access to all STL components (not recommended for production)
- Iterators are used extensively for traversing containers
- Use `auto` keyword for cleaner iterator declarations
- Remember: `end()` points to one position **after** the last element

## Learning Objectives

This code helps understand:
- STL container characteristics and use cases
- Iterator usage and manipulation
- Common STL algorithms
- Time complexity trade-offs
- When to use which data structure

## Author

Part of Striver's A2Z DSA Course - Step 1, Lecture 3 (STL)
