# Sorting Techniques

A comprehensive guide to sorting algorithms in C++. These implementations demonstrate various approaches to arrange elements in ascending or descending order efficiently.

## Table of Contents

1. [Selection Sort](#1-selection-sort)
2. [Bubble Sort](#2-bubble-sort)
3. [Insertion Sort](#3-insertion-sort)

---

## What is Sorting?

Sorting is the process of arranging elements in a specific order (ascending or descending). It's one of the fundamental operations in computer science and is used as a preprocessing step for many algorithms.

### Key Benefits:
1. **Efficient Searching:** Sorted data enables binary search O(log n)
2. **Data Organization:** Makes data easier to understand and analyze
3. **Algorithm Optimization:** Many algorithms work better with sorted data

### Sorting Classification:
- **Comparison-based:** Elements are compared to determine order
- **In-place:** Uses constant O(1) extra space
- **Stable:** Maintains relative order of equal elements

---

## Problems Overview

### 1. Selection Sort

**Function:** `selection_sort(int arr[], int n)`

Sorts an array by repeatedly finding the minimum element from the unsorted portion and placing it at the beginning.

**Algorithm:**
1. Find the minimum element in unsorted array
2. Swap it with the element at the beginning of unsorted portion
3. Move the boundary of sorted portion one element to the right
4. Repeat until entire array is sorted

**Working Example:**
```cpp
arr[] = {12, 3, 34, 45, 76}

Pass 1: Find min in [12,3,34,45,76] → min=3
        Swap 12 ↔ 3 → [3, 12, 34, 45, 76]

Pass 2: Find min in [12,34,45,76] → min=12
        No swap → [3, 12, 34, 45, 76]

Pass 3: Find min in [34,45,76] → min=34
        No swap → [3, 12, 34, 45, 76]

Pass 4: Find min in [45,76] → min=45
        No swap → [3, 12, 34, 45, 76]

Result: [3, 12, 34, 45, 76]
```

**Step-by-Step Visualization:**
```
Initial:  [12, 3, 34, 45, 76]
           ↓   ↓
Step 1:   [3, 12, 34, 45, 76]  (swap 12 and 3)
              ↓
Step 2:   [3, 12, 34, 45, 76]  (12 is already minimum)
                  ↓
Step 3:   [3, 12, 34, 45, 76]  (34 is already minimum)
                      ↓
Step 4:   [3, 12, 34, 45, 76]  (45 is already minimum)
Sorted:   [3, 12, 34, 45, 76]
```

**Time Complexity:** 
- Best Case: O(n²)
- Average Case: O(n²)
- Worst Case: O(n²)

**Space Complexity:** O(1) - in-place sorting

**Characteristics:**
- ✅ In-place sorting (no extra space needed)
- ❌ Not stable (can change relative order of equal elements)
- ✅ Makes minimum number of swaps O(n)
- ❌ Not adaptive (always takes O(n²) time even if array is sorted)

**Example:**
```
Input: arr[] = {12, 3, 34, 45, 76, 78, 90, 0, 13, 46, 35}
Output: 0 3 12 13 34 35 45 46 76 78 90
```

---

### 2. Bubble Sort

**Function:** `bubble_sort(int arr[], int n)`

Sorts an array by repeatedly swapping adjacent elements if they are in wrong order. Optimized with early termination when no swaps occur.

**Algorithm:**
1. Compare adjacent elements
2. Swap them if they are in wrong order
3. After each pass, largest element bubbles to the end
4. Repeat for remaining elements
5. Stop early if no swaps occur (array is sorted)

**Working Example:**
```cpp
arr[] = {67, 89, 34, 56, 80}

Pass 1:
  67, 89 → No swap [67, 89, 34, 56, 80]
  89, 34 → Swap    [67, 34, 89, 56, 80]
  89, 56 → Swap    [67, 34, 56, 89, 80]
  89, 80 → Swap    [67, 34, 56, 80, 89] ✓ 89 in place

Pass 2:
  67, 34 → Swap    [34, 67, 56, 80, 89]
  67, 56 → Swap    [34, 56, 67, 80, 89]
  67, 80 → No swap [34, 56, 67, 80, 89] ✓ 80 in place

Pass 3:
  34, 56 → No swap [34, 56, 67, 80, 89]
  56, 67 → No swap [34, 56, 67, 80, 89] ✓ 67 in place

Pass 4:
  34, 56 → No swap [34, 56, 67, 80, 89] ✓ No swaps → Stop

Result: [34, 56, 67, 80, 89]
```

**Optimization Visualization:**
```
Pass 1: [67, 89, 34, 56, 80] → swaps=1 (3 swaps made)
Pass 2: [34, 67, 56, 80, 89] → swaps=1 (2 swaps made)
Pass 3: [34, 56, 67, 80, 89] → swaps=0 (no swaps made)
        ↑ Array is sorted, break early!
```

**Time Complexity:**
- Best Case: O(n) - when array is already sorted (with optimization)
- Average Case: O(n²)
- Worst Case: O(n²) - when array is reverse sorted

**Space Complexity:** O(1) - in-place sorting

**Characteristics:**
- ✅ In-place sorting
- ✅ Stable (maintains relative order of equal elements)
- ✅ Adaptive (faster for nearly sorted arrays)
- ✅ Easy to implement and understand
- ❌ Inefficient for large datasets

**Example:**
```
Input: arr[] = {67, 89, 34, 56, 80, 13, 3, 5, 12, 45, 1, 0}
Output: 0 1 3 5 12 13 34 45 56 67 80 89
```

**Optimized vs Basic Bubble Sort:**
- **Basic:** Always runs n-1 passes regardless of whether array is sorted
- **Optimized:** Uses `swaps` flag to detect if array is already sorted and exits early
- For sorted array: Basic takes O(n²), Optimized takes O(n)

---

### 3. Insertion Sort

**Function:** `Insertion_sort(int arr[], int n)`

Sorts an array by building a sorted portion one element at a time, similar to how you sort playing cards in your hands.

**Algorithm:**
1. Start from the second element (consider first element as sorted)
2. Pick the current element as key
3. Compare key with elements in the sorted portion (left side)
4. Shift all elements greater than key one position right
5. Insert key at its correct position
6. Repeat until entire array is sorted

**Working Example:**
```cpp
arr[] = {12, 11, 13, 5, 6}

Pass 1: key=11, sorted=[12]
        11 < 12 → shift 12
        [11, 12, 13, 5, 6]

Pass 2: key=13, sorted=[11, 12]
        13 > 12 → no shift
        [11, 12, 13, 5, 6]

Pass 3: key=5, sorted=[11, 12, 13]
        5 < 13 → shift 13
        5 < 12 → shift 12
        5 < 11 → shift 11
        [5, 11, 12, 13, 6]

Pass 4: key=6, sorted=[5, 11, 12, 13]
        6 < 13 → shift 13
        6 < 12 → shift 12
        6 < 11 → shift 11
        6 > 5 → insert at position 1
        [5, 6, 11, 12, 13]

Result: [5, 6, 11, 12, 13]
```

**Step-by-Step Visualization:**
```
Initial:  [12, 11, 13, 5, 6]
          [12] | 11, 13, 5, 6    (12 is sorted)
           
Step 1:   [11, 12] | 13, 5, 6    (insert 11 before 12)
                   ↑
Step 2:   [11, 12, 13] | 5, 6    (insert 13 after 12)
                      ↑
Step 3:   [5, 11, 12, 13] | 6    (insert 5 at beginning)
          ↑
Step 4:   [5, 6, 11, 12, 13]     (insert 6 after 5)
             ↑
Sorted:   [5, 6, 11, 12, 13]
```

**Time Complexity:**
- Best Case: O(n) - when array is already sorted
- Average Case: O(n²)
- Worst Case: O(n²) - when array is reverse sorted

**Space Complexity:** O(1) - in-place sorting

**Characteristics:**
- ✅ In-place sorting (no extra space needed)
- ✅ Stable (maintains relative order of equal elements)
- ✅ Adaptive (efficient for nearly sorted data)
- ✅ Online (can sort data as it arrives)
- ✅ Simple and easy to implement
- ❌ Inefficient for large datasets

**Example:**
```
Input: arr[] = {78, 45, 12, 67, 89, 2, 12, 35, 57, 23, 1, 57, 78, 23, 23, 34, 98}
Output: 1 2 12 12 23 23 23 34 35 45 57 57 67 78 78 89 98
```

**Why It's Like Sorting Cards:**
- You start with one card (considered sorted)
- Pick the next card from unsorted pile
- Find its correct position in your sorted hand
- Shift cards to make space and insert
- Repeat until all cards are sorted

---

## Comparison Table

| Algorithm | Best Case | Average Case | Worst Case | Space | Stable | Adaptive |
|-----------|-----------|--------------|------------|-------|--------|----------|
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) | ❌ | ❌ |
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) | ✅ | ✅ |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) | ✅ | ✅ |

---

## When to Use?

### Selection Sort:
- When memory writes are costly (makes minimum swaps)
- When simplicity is preferred over efficiency
- For small datasets (n < 20)

### Bubble Sort:
- When data is nearly sorted
- When you need a stable sort with O(1) space
- For educational purposes or small datasets

### Insertion Sort:
- When data is nearly sorted or partially sorted
- For small datasets (performs better than other O(n²) algorithms)
- When you need an online sorting algorithm (data arrives in real-time)
- As a subroutine in more complex algorithms like Shell Sort or Timsort
- When stability is required with minimal space

---

## Key Takeaways

1. **In-Place Sorting:** Both algorithms use O(1) extra space
2. **Comparison-Based:** Elements are ordered through comparisons
3. **Understand Trade-offs:** Selection Sort minimizes swaps, Bubble Sort is adaptive
4. **Time Complexity Matters:** O(n²) makes these unsuitable for large datasets
5. **Stability Consideration:** Choose Bubble Sort when order of equal elements matters
6. **Optimization Helps:** Early termination can significantly improve performance
7. **Algorithm Selection:** Choose based on data characteristics and constraints

---

## Learning Objectives

These sorting implementations teach:
- Understanding comparison-based sorting algorithms
- Analyzing time and space complexity
- Recognizing stable vs unstable sorts
- Identifying adaptive algorithm behavior
- Optimizing algorithms with early termination
- Choosing appropriate sorting techniques for different scenarios

---

## Author

Part of Striver's A2Z DSA Course - Step 2 (Sorting Techniques)
