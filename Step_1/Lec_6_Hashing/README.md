# Hashing

A comprehensive guide to hashing techniques in C++. These implementations demonstrate various approaches to efficiently count and retrieve element frequencies using different data structures.

## Table of Contents

1. [Brute Force Approach](#1-brute-force-approach)
2. [Number Hashing (Array-based)](#2-number-hashing-array-based)
3. [Lowercase Letter Hashing](#3-lowercase-letter-hashing)
4. [ASCII Character Hashing](#4-ascii-character-hashing)
5. [Map-based Hashing](#5-map-based-hashing)
6. [Sorted Hashing with Custom Comparator](#6-sorted-hashing-with-custom-comparator)

---

## What is Hashing?

Hashing is a data structure technique that allows us to store and retrieve data in constant time O(1). Instead of searching through an entire array for each query (O(n)), we preprocess the data once and then answer queries instantly.

### Key Benefits:
1. **Fast Retrieval:** O(1) lookup time (array) or O(log n) (map)
2. **Frequency Counting:** Efficiently count occurrences of elements
3. **Space-Time Tradeoff:** Use extra memory to gain speed

### The Two-Phase Process:
1. **Precompute Phase:** Build the hash table/array from input data
2. **Query Phase:** Answer multiple queries in O(1) or O(log n) time

---

## Problems Overview

### 1. Brute Force Approach

**Function:** `number_of_occurance_basic(int arr[])`

Counts occurrences of elements by iterating through the entire array for each query.

**Algorithm:**
- For each query, traverse the entire array
- Count matches with the target element
- No preprocessing involved

**Working Example:**
```cpp
arr[] = {1, 2, 3, 4, 5, 2, 5, 2, 5, 2, 4, 5, 2}
Query: Find frequency of 2

Iteration:
i=0: arr[0]=1 ≠ 2
i=1: arr[1]=2 = 2 → count=1
i=2: arr[2]=3 ≠ 2
i=3: arr[3]=4 ≠ 2
i=4: arr[4]=5 ≠ 2
i=5: arr[5]=2 = 2 → count=2
...
Result: 2 appears 5 times
```

**Time Complexity:** O(n) per query, O(n × q) total (q = number of queries)  
**Space Complexity:** O(1) - no extra space

**Example:**
```
Input: arr[] = {1,2,3,4,5,2,5,2,5,2,4,5,2}, queries = 3
Query 1: Find 2 → Output: 5 times
Query 2: Find 5 → Output: 4 times
Query 3: Find 1 → Output: 1 time
```

**Drawback:** Inefficient for multiple queries as we scan the array repeatedly.

---

### 2. Number Hashing (Array-based)

**Function:** `number_hashing(int arr[])`

Uses an array to store frequency of numbers, enabling O(1) query time.

**Algorithm:**
1. **Precompute Phase:**
   - Create hash array initialized to 0
   - For each element in input array, increment `hash[arr[i]]`
2. **Query Phase:**
   - Directly access `hash[element]` to get frequency

**Visualization:**
```cpp
Input: arr[] = {1, 2, 3, 4, 5, 2, 5, 2, 5, 2, 4, 5, 2}

Precompute:
hash[0] = 0
hash[1] = 1  (1 appears once)
hash[2] = 5  (2 appears 5 times)
hash[3] = 1  (3 appears once)
hash[4] = 2  (4 appears twice)
hash[5] = 4  (5 appears 4 times)
hash[6] = 0
...

Query: hash[2] → Instant result: 5
```

**Code Breakdown:**
```cpp
// Precompute
int hash[13] = {0};           // Initialize array with zeros
for(int i=0; i<13; i++) {
    hash[arr[i]]++;           // Use array element as index
}

// Fetch
cout << hash[j] << " times";  // O(1) lookup
```

**Time Complexity:** 
- Precompute: O(n)
- Per Query: O(1)
- Total: O(n + q) where q = queries

**Space Complexity:** O(max_element) - depends on largest number

**Example:**
```
Input: arr[] = {1,2,3,4,5,2,5,2,5,2,4,5,2}
Precompute: Build hash array in O(n)
Query 1: Find 2 → hash[2] = 5 (instant)
Query 2: Find 5 → hash[5] = 4 (instant)
Query 3: Find 7 → hash[7] = 0 (instant)
```

**Limitations:**
- Only works when numbers are in limited range (0 to max_size)
- Cannot handle negative numbers directly
- Wastes space if numbers are sparse (e.g., {1, 1000000})

---

### 3. Lowercase Letter Hashing

**Function:** `lowercase_letters(string lower)`

Efficiently counts frequency of lowercase letters (a-z) using character mapping.

**Algorithm:**
1. Create hash array of size 26 (for 'a' to 'z')
2. Map each character to index: `character - 'a'`
   - 'a' → 0, 'b' → 1, 'c' → 2, ..., 'z' → 25
3. Increment count at mapped index
4. Query by converting character to index

**Character Mapping:**
```
'a' - 'a' = 0  → hash[0]
'b' - 'a' = 1  → hash[1]
'c' - 'a' = 2  → hash[2]
...
'z' - 'a' = 25 → hash[25]
```

**Working Example:**
```cpp
Input: "abcdecbadefc"

Character frequency:
a: 2, b: 2, c: 3, d: 2, e: 2, f: 1

Hash array visualization:
hash[0] = 2  ('a')
hash[1] = 2  ('b')
hash[2] = 3  ('c')
hash[3] = 2  ('d')
hash[4] = 2  ('e')
hash[5] = 1  ('f')
hash[6-25] = 0
```

**Code Breakdown:**
```cpp
int hash[26] = {0};                    // 26 lowercase letters
for(int i=0; i<lower.size(); i++) {
    hash[lower[i] - 'a']++;            // Map char to index
}

// Query
cout << hash[j - 'a'] << " times";     // Convert char to index
```

**Time Complexity:** O(n) precompute + O(1) per query  
**Space Complexity:** O(26) = O(1) - constant space

**Example:**
```
Input: "abcdecbadefc"
Query 'c' → hash['c'-'a'] = hash[2] = 3 times
Query 'a' → hash['a'-'a'] = hash[0] = 2 times
Query 'z' → hash['z'-'a'] = hash[25] = 0 times
```

**Use Cases:**
- Anagram detection
- Character frequency in strings
- Finding missing/extra characters

---

### 4. ASCII Character Hashing

**Function:** `ascii_hashing(string s)`

Handles all ASCII characters including uppercase, lowercase, digits, and special characters.

**Algorithm:**
1. Create hash array of size 256 (total ASCII characters)
2. Use character's ASCII value as index directly
3. Works for any printable character

**ASCII Range:**
```
0-31:   Control characters
32-47:  Special characters (!, @, #, etc.)
48-57:  Digits (0-9)
65-90:  Uppercase letters (A-Z)
97-122: Lowercase letters (a-z)
123-126: More special characters
```

**Working Example:**
```cpp
Input: "agjv356165!@#$%^atudgq3@#$%266tys1b651yt@#"

Character types handled:
- Lowercase: a, g, j, v, t, u, d, q, s, y, b
- Digits: 3, 5, 6, 1, 2
- Special: !, @, #, $, %, ^

Hash array:
hash[33] = 1  ('!')
hash[35] = 3  ('#')
hash[49] = 3  ('1')
hash[50] = 3  ('2')
hash[97] = 3  ('a')
hash[103] = 2 ('g')
...
```

**Code Breakdown:**
```cpp
int hash[256] = {0};              // All ASCII characters
for(int i=0; i<s.size(); i++) {
    hash[s[i]]++;                 // Direct ASCII indexing
}

// Query
cout << hash[j] << " times";      // Use ASCII value as index
```

**Time Complexity:** O(n) precompute + O(1) per query  
**Space Complexity:** O(256) = O(1) - constant space

**Example:**
```
Input: "Hello123!@#"
Query 'l' → hash[108] = 2 times
Query '1' → hash[49] = 1 time
Query '@' → hash[64] = 1 time
Query 'z' → hash[122] = 0 times
```

**Advantages over Lowercase Hashing:**
- Handles mixed case strings
- Works with numbers and symbols
- Universal solution for any ASCII character

---

### 5. Map-based Hashing

**Function:** `number_hashing_using_maps(int arr[], int n)`

Uses C++ STL map/unordered_map to handle any range of numbers without size limitations.

**Algorithm:**
1. Create map where key = element, value = frequency
2. Iterate through array and increment `map[element]`
3. Map automatically handles any integer value
4. Query by accessing `map[element]`

**Map vs Unordered Map:**

| Feature            | map<int, int>       | unordered_map<int, int>  |
|--------------------|---------------------|--------------------------|
| Internal Structure | Red-Black Tree      | Hash Table               |
| Ordering           | Sorted by key       | No order                 |
| Insertion          | O(log n)            | O(1) average             |
| Search             | O(log n)            | O(1) average             |
| Worst Case         | O(log n)            | O(n)                     |
| Memory             | More overhead       | Less overhead            |


**Working Example:**
```cpp
Input: arr[] = {1, 2, 3, 4, 5, 2, 1, 5, 7, 4, 2, 3, 6, 5, 3, 2, 5, 4, 2, 4, 6, 4, 2, 3, 5, 2, 5, 12, 12, 12, 12, 134, 35, 2, 24}

After preprocessing:
map = {
    1: 2,
    2: 9,
    3: 4,
    4: 6,
    5: 7,
    6: 2,
    7: 1,
    12: 4,
    24: 1,
    35: 1,
    134: 1
}

Query: map[2] → 9 times
Query: map[12] → 4 times
Query: map[999] → 0 times (auto-returns 0 for missing keys)
```

**Code Breakdown:**
```cpp
// Using unordered_map for O(1) average
unordered_map<int, int> mpp;
for(int i=0; i<n; i++) {
    mpp[arr[i]]++;              // Automatically creates/updates key
}

// Query
cout << mpp[i] << " times";     // Returns 0 if key doesn't exist
```

**Time Complexity:**
- Using `map`: O(n log n) precompute + O(log n) per query
- Using `unordered_map`: O(n) precompute + O(1) average per query

**Space Complexity:** O(k) where k = unique elements

**Example:**
```
Input: arr[] = {1000000, 5, 1000000, -50, 5, 1000000}
Map: {-50: 1, 5: 2, 1000000: 3}

Query 1000000 → 3 times
Query -50 → 1 time
Query 99999 → 0 times
```

**When to Use Map:**
- Numbers with very large range (up to 10⁹)
- Negative numbers present
- Sparse data (few unique elements)
- Unknown range of numbers
- Need to iterate in sorted order (use `map`)

**Advantages:**
- No size limitation
- Handles negative numbers
- Space efficient for sparse data
- Flexible and dynamic

---

## Comparison: Array vs Map Hashing

| Feature | Array Hashing | Map Hashing | Unordered Map |
|---------|---------------|-------------|---------------|
| Time Complexity | O(1) | O(log n) | O(1) average |
| Space Complexity | O(max_value) | O(unique_elements) | O(unique_elements) |
| Range Limitation | Yes (≤ 10⁶) | No | No |
| Negative Numbers | No (without offset) | Yes | Yes |
| Ordered Output | No | Yes | No |
| Best For | Small range, dense data | Any range, sorted output | Any range, speed |
| Memory Efficiency | Low (if sparse) | High | High |
| Example Range | 0-10⁶ | -10⁹ to 10⁹ | -10⁹ to 10⁹ |

---

## Decision Tree: Which Hashing to Use?

```
Is the data characters?
│
├─ Yes → Are only lowercase letters?
│         ├─ Yes → Use Lowercase Letter Hashing (size 26)
│         └─ No → Use ASCII Hashing (size 256)
│
└─ No → Are numbers in limited range (0 to 10⁶)?
          ├─ Yes → Use Array Hashing
          │         └─ Inside function: max 10⁶
          │         └─ Global array: max 10⁷
          │
          └─ No → Use Map Hashing
                    ├─ Need sorted order? → map<int, int>
                    └─ Need max speed? → unordered_map<int, int>
```

---

## Complexity Summary

| Function | Precompute | Per Query | Total (q queries) | Space |
|----------|------------|-----------|-------------------|-------|
| Brute Force | O(1) | O(n) | O(n × q) | O(1) |
| Number Hashing | O(n) | O(1) | O(n + q) | O(max_value) |
| Lowercase Hashing | O(n) | O(1) | O(n + q) | O(26) |
| ASCII Hashing | O(n) | O(1) | O(n + q) | O(256) |
| Map Hashing | O(n log n) | O(log n) | O(n log n + q log n) | O(unique) |
| Unordered Map | O(n) | O(1) avg | O(n + q) avg | O(unique) |

---

## Array Size Limitations

### Stack Memory Limits:

**Inside Functions (Local Variables):**
```cpp
void function() {
    int hash[1000000];  // ✓ OK - ~10⁶ elements (4 MB)
    int hash[10000000]; // ✗ Stack Overflow
}
```

**Global Scope:**
```cpp
int hash[10000000];  // ✓ OK - ~10⁷ elements (40 MB)
int hash[100000000]; // ✗ Compilation Error

void function() {
    // Use global hash array
}
```

**Why the Difference?**
- Local variables use **stack memory** (limited ~1-8 MB)
- Global variables use **heap/data segment** (much larger)

**Solutions for Larger Arrays:**
1. Declare array globally
2. Use dynamic allocation: `int* hash = new int[size]`
3. Use `vector<int> hash(size)` (heap allocation)
4. Switch to map-based hashing

---

## Common Use Cases

### 1. Frequency Counting
**Problem:** Count frequency of each element in array
```cpp
// Array approach (when elements ≤ 10⁶)
int hash[1000001] = {0};
for(int x : arr) hash[x]++;

// Map approach (any range)
unordered_map<int, int> freq;
for(int x : arr) freq[x]++;
```

### 2. Finding Duplicates
**Problem:** Check if array has duplicates
```cpp
unordered_map<int, int> seen;
for(int x : arr) {
    if(seen[x] > 0) return true;  // Duplicate found
    seen[x]++;
}
return false;
```

### 3. Two Sum Problem
**Problem:** Find if two numbers add up to target
```cpp
unordered_map<int, int> mp;
for(int x : arr) {
    if(mp.find(target - x) != mp.end()) return true;
    mp[x] = 1;
}
return false;
```

### 4. Anagram Detection
**Problem:** Check if two strings are anagrams
```cpp
int hash1[26] = {0}, hash2[26] = {0};
for(char c : s1) hash1[c - 'a']++;
for(char c : s2) hash2[c - 'a']++;
// Compare both hash arrays
```

### 5. Character Replacement Cost
**Problem:** Count operations to make strings equal
```cpp
int hash[26] = {0};
for(char c : s1) hash[c - 'a']++;
for(char c : s2) hash[c - 'a']--;
// Count non-zero values
```

---

## Hashing Patterns

### 1. **Precompute-Query Pattern**
Most common hashing pattern:
```cpp
// Phase 1: Precompute
hash_structure[arr[i]]++;

// Phase 2: Answer multiple queries
return hash_structure[query];
```

### 2. **Character Mapping Pattern**
For character-based problems:
```cpp
// Lowercase: 'a' to 'z'
hash[char - 'a']

// Uppercase: 'A' to 'Z'
hash[char - 'A']

// Any ASCII
hash[char]
```

### 3. **Map Auto-initialization**
Maps return 0 for missing keys:
```cpp
map<int, int> mp;
cout << mp[999];  // Returns 0 (not found)
mp[999]++;        // Creates key and sets to 1
```

### 4. **Checking Existence**
```cpp
// Array: Check if count > 0
if(hash[x] > 0) { /* exists */ }

// Map: Use find()
if(mp.find(x) != mp.end()) { /* exists */ }

// Or simply check value
if(mp[x] > 0) { /* exists */ }
```

---

## Important Concepts

### Why Hashing is Efficient?

**Without Hashing:**
```
Query 1: Search array → O(n)
Query 2: Search array → O(n)
Query 3: Search array → O(n)
Total: O(3n) = O(qn) where q = queries
```

**With Hashing:**
```
Precompute: Build hash → O(n)
Query 1: Check hash → O(1)
Query 2: Check hash → O(1)
Query 3: Check hash → O(1)
Total: O(n + 3) = O(n + q)
```

**Benefit:** When q is large, O(n + q) << O(nq)

### Trade-offs

1. **Time vs Space:**
   - Hashing uses extra memory for speed
   - Array hashing: More space, faster queries
   - No hashing: No extra space, slower queries

2. **Array vs Map:**
   - Array: Faster but limited range
   - Map: Slower but unlimited range

3. **Map vs Unordered Map:**
   - Map: Ordered, predictable O(log n)
   - Unordered Map: Faster average, but O(n) worst case

---

## Common Mistakes

### 1. **Array Index Out of Bounds**
```cpp
// ✗ Wrong: If arr[i] > 100, crashes
int hash[100];
hash[arr[i]]++;

// ✓ Correct: Ensure array size matches max value
int hash[MAX_VALUE + 1];
```

### 2. **Forgetting to Initialize**
```cpp
// ✗ Wrong: Garbage values
int hash[1000];

// ✓ Correct: Initialize to 0
int hash[1000] = {0};
```

### 3. **Using Array for Large Range**
```cpp
// ✗ Wrong: Numbers can be 10⁹
int hash[1000000001];  // Stack overflow!

// ✓ Correct: Use map for large ranges
unordered_map<int, int> hash;
```

### 4. **Not Passing Array Size**
```cpp
// ✗ Wrong: sizeof(arr) gives pointer size in functions
void func(int arr[]) {
    int n = sizeof(arr) / sizeof(arr[0]);  // Wrong!
}

// ✓ Correct: Pass size as parameter
void func(int arr[], int n) {
    // Use n for size
}
```

### 5. **Character Mapping Error**
```cpp
// ✗ Wrong: 'A' - 'a' = -32 (negative index!)
hash['A' - 'a']++;

// ✓ Correct: Use uppercase mapping
hash['A' - 'A']++;  // For uppercase
hash[char];         // Or use ASCII directly
```

---

## Performance Comparison

### Example: Find frequency of 10⁶ queries in array of 10⁶ elements

| Method | Precompute Time | Query Time (10⁶ queries) | Total Time |
|--------|----------------|-------------------------|------------|
| Brute Force | 0 | 10⁶ × 10⁶ = 10¹² ops | ~1000 seconds |
| Array Hash | 10⁶ ops | 10⁶ × 1 = 10⁶ ops | ~0.001 seconds |
| Map Hash | 10⁶ log 10⁶ ≈ 2×10⁷ | 10⁶ log 10⁶ ≈ 2×10⁷ | ~0.04 seconds |
| Unordered Map | 10⁶ ops | 10⁶ ops | ~0.002 seconds |

**Speedup:** Hashing is **100,000x - 1,000,000x faster!**

---

## 6. Sorted Hashing with Custom Comparator

**Function:** `number_hashing_sorted(int arr[], int n)`

Demonstrates how to sort hash map entries using custom sorting criteria. This approach combines hashing for frequency counting with vector sorting for flexible ordering.

**Algorithm:**
1. Build frequency map using `unordered_map<int, int>`
2. Convert map to `vector<pair<int, int>>` for sortability
3. Sort by default (ascending by key)
4. Sort using custom comparator for advanced ordering

**Custom Comparator Logic:**
```cpp
bool comp(pair<int,int> a, pair<int,int> b) {
    // Primary: Sort by frequency (descending)
    if(a.second > b.second) return true;
    else if(a.second < b.second) return false;
    // Secondary: If frequencies equal, sort by value (ascending)
    else {
        if(a.first < b.first) return true;
        else return false;
    }
}
```

**Working Example:**
```cpp
arr[] = {1, 2, 3, 4, 5, 2, 5, 2, 5, 2, 4, 5, 2}

Step 1: Build frequency map
Map: {1:1, 2:5, 3:1, 4:2, 5:4}

Step 2: Convert to vector
Vector: [(1,1), (2,5), (3,1), (4,2), (5,4)]

Step 3: Default sort (by key ascending)
Result: [(1,1), (2,5), (3,1), (4,2), (5,4)]
Output:
1 : 1
2 : 5
3 : 1
4 : 2
5 : 4

Step 4: Custom sort (by frequency desc, then key asc)
Result: [(2,5), (5,4), (4,2), (1,1), (3,1)]
Output:
2 : 5  ← Highest frequency
5 : 4
4 : 2
1 : 1  ← Same frequency as 3, but smaller key
3 : 1

Highest frequency element: 2 with frequency 5
Lowest frequency, highest value: 3 with frequency 1
```

**Time Complexity:**
- Building map: O(n)
- Converting to vector: O(m) where m = unique elements
- Sorting: O(m log m)
- **Total: O(n + m log m)**

**Space Complexity:**
- Map storage: O(m)
- Vector storage: O(m)
- **Total: O(m)**

**Key Concepts:**

1. **Unordered Map to Vector Conversion:**
   ```cpp
   unordered_map<int, int> mapp;
   vector<pair<int,int>> hashh(mapp.begin(), mapp.end());
   ```
   This allows sorting since `unordered_map` doesn't support `sort()` directly.

2. **Default vs Custom Sorting:**
   - `sort(hashh.begin(), hashh.end())` → Sorts by first element (key) ascending
   - `sort(hashh.begin(), hashh.end(), comp)` → Custom sorting logic

3. **Multi-Level Sorting:**
   The custom comparator implements a two-tier sorting strategy:
   - **Primary criterion:** Frequency (higher frequencies first)
   - **Secondary criterion:** Value (smaller values first when frequencies match)

**Use Cases:**
- Finding most/least frequent elements
- Sorting elements by custom criteria
- Ranking elements based on multiple factors
- Analytics requiring ordered frequency data

**Code Implementation:**
```cpp
void number_hashing_sorted(int arr[], int n) {
    // Step 1: Build frequency map
    unordered_map<int, int> mapp;
    for(int i = 0; i < n; i++) {
        mapp[arr[i]]++;
    }
    
    // Step 2: Convert to vector for sorting
    vector<pair<int,int>> hashh(mapp.begin(), mapp.end());

    // Step 3: Default sort (by key)
    sort(hashh.begin(), hashh.end());
    for(auto it: hashh) {
        cout << it.first << " : " << it.second << endl;
    }
    cout << endl;
    
    // Step 4: Custom sort (by frequency desc, then key asc)
    sort(hashh.begin(), hashh.end(), comp);
    for(auto it: hashh) {
        cout << it.first << " : " << it.second << endl;
    }
    cout << endl;

    // Find extremes
    cout << "Element with the highest frequency is " 
         << hashh[0].first << " with frequency " << hashh[0].second << endl;
    cout << "Element with the lowest frequency and highest value is " 
         << hashh[hashh.size()-1].first << " with frequency " 
         << hashh[hashh.size()-1].second << endl;
}
```

**Advantages:**
- ✅ Flexible sorting criteria
- ✅ Fast frequency counting with unordered_map
- ✅ Can find min/max frequency elements easily
- ✅ Supports complex multi-level sorting

**Disadvantages:**
- ❌ Extra O(m) space for vector conversion
- ❌ O(m log m) sorting overhead
- ❌ More complex than simple map iteration

---

## Key Takeaways

1. **Preprocessing is Power:** Spend O(n) once to answer queries in O(1)
2. **Choose Wisely:** Array for small range, map for large/unknown range
3. **Memory Matters:** Consider stack limits for array size
4. **Trade-offs Exist:** Speed vs space, simplicity vs flexibility
5. **Know Your Data:** Range, density, and query count determine best approach
6. **Unordered is Faster:** Prefer `unordered_map` unless you need sorted keys
7. **Initialize Arrays:** Always set hash arrays to 0
8. **Character Tricks:** Use `char - 'a'` for lowercase, direct ASCII for mixed

---

## Learning Objectives

These hashing implementations teach:
- Understanding time-space tradeoffs
- When to use arrays vs maps
- Character encoding and mapping techniques
- Preprocessing strategies for optimization
- Choosing appropriate data structures
- Handling different input ranges and constraints

---

## Author

Part of Striver's A2Z DSA Course - Step 1, Lecture 6 (Hashing)
