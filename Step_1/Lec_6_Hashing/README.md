# Hashing

## Overview
Hashing is a technique to store and retrieve data efficiently. Instead of searching through an entire array every time (O(n)), we can use hashing to achieve O(1) lookup time by preprocessing the data.

## Concepts Covered

### 1. Basic Approach (Brute Force)
**Function:** `number_of_occurance_basic()`
- **Time Complexity:** O(n) per query
- Iterates through the entire array for each query
- Inefficient for multiple queries

### 2. Number Hashing (Array-based)
**Function:** `number_hashing()`
- **Time Complexity:** O(1) per query after O(n) preprocessing
- Uses an array to store frequency of numbers
- **Limitation:** Only works when numbers are in a limited range
- **Space Complexity:** O(max_element)

**How it works:**
```cpp
hash[arr[i]]++;  // Increment count at index arr[i]
```

### 3. Lowercase Letter Hashing
**Function:** `lowercase_letters()`
- **Time Complexity:** O(1) per query after O(n) preprocessing
- Uses an array of size 26 (for 'a' to 'z')
- Maps characters to indices: `hash[character - 'a']`
- **Use Case:** Counting frequency of lowercase letters in a string

### 4. ASCII Character Hashing
**Function:** `ascii_hashing()`
- **Time Complexity:** O(1) per query after O(n) preprocessing
- Uses an array of size 256 (for all ASCII characters)
- Handles uppercase, lowercase, digits, and special characters
- **Use Case:** Counting any ASCII character frequency

### 5. Map-based Hashing
**Function:** `number_hashing_using_maps()`
- **Time Complexity:** O(log n) per query for map, O(1) for unordered_map
- **Advantage:** Works for any range of numbers (no size limitation)
- **Space Complexity:** O(unique_elements)
- **Use Case:** When the range of numbers is very large or unknown

## Comparison: Array vs Map

| Feature        | Array Hashing     | Map Hashing                                |
|----------------|-------------------|--------------------------------------------|
| Time Complexity| O(1)              | O(log n) – map, O(1) – unordered_map       |
| Space          | O(max_value)      | O(unique_elements)                         |
| Best For       | Limited range     | Large or unknown range                     |
| Example        | Numbers 0–10⁶     | Numbers can be up to 10⁹                   |


## When to Use What?

1. **Array Hashing**: 
   - When range is small (≤ 10⁶)
   - When you need fastest lookup
   - Example: Counting characters, small numbers

2. **Map Hashing**:
   - When range is very large (> 10⁷)
   - When you don't know the range beforehand
   - When memory is a concern
   - Example: Large numbers, negative numbers

## Important Notes

⚠️ **Array Size Limitations:**
- Inside function: ~10⁶ elements
- Global array: ~10⁷ elements
- Exceeding these limits causes segmentation fault

⚠️ **Map Types:**
- `map<int, int>`: Ordered, O(log n) operations
- `unordered_map<int, int>`: Unordered, O(1) average, O(n) worst case

## Key Takeaways

1. **Preprocessing** is key to efficient hashing
2. Choose the right data structure based on constraints
3. Array hashing is faster but has size limitations
4. Map hashing is more flexible but slightly slower
5. Always consider the trade-off between time and space complexity

---

## Author

Part of Striver's A2Z DSA Course - Step 1, Lecture 6 (Hashing)
