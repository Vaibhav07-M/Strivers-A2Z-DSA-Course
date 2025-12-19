# Sorting Techniques

A comprehensive guide to sorting algorithms in C++. These implementations demonstrate various approaches to arrange elements in ascending or descending order efficiently.

## Table of Contents

1. [Selection Sort](#1-selection-sort)
2. [Bubble Sort](#2-bubble-sort)
3. [Insertion Sort](#3-insertion-sort)
4. [Merge Sort](#4-merge-sort)
5. [Quick Sort](#5-quick-sort)

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

### 4. Merge Sort

**Function:** `Merge_sort(vector<int> &arr, int n)`

A divide-and-conquer algorithm that divides the array into two halves, recursively sorts them, and then merges the sorted halves.

**Algorithm:**
1. Divide the array into two halves at the middle
2. Recursively sort the left half
3. Recursively sort the right half
4. Merge the two sorted halves into one sorted array

**Working Example:**
```cpp
arr[] = {38, 27, 43, 3, 9, 82, 10}

Divide Phase:
[38, 27, 43, 3, 9, 82, 10]
       ↙            ↘
[38, 27, 43]    [3, 9, 82, 10]
   ↙     ↘         ↙       ↘
[38]  [27, 43]  [3, 9]  [82, 10]
       ↙   ↘     ↙  ↘    ↙   ↘
      [27] [43] [3] [9] [82] [10]

Merge Phase:
      [27] [43] [3] [9] [82] [10]
       ↘   ↙     ↘  ↙    ↘   ↙
     [27, 43]   [3, 9]  [10, 82]
        ↘         ↙        ↙
      [3, 9, 27, 43]  [10, 82]
             ↘           ↙
        [3, 9, 10, 27, 43, 82]
```

**Merge Process Example:**
```
Merging [27, 43] and [3, 9]:

Left:  [27, 43]  Right: [3, 9]
        ↑                ↑
Compare 27 vs 3 → 3 is smaller → temp = [3]

Left:  [27, 43]  Right: [3, 9]
        ↑                   ↑
Compare 27 vs 9 → 9 is smaller → temp = [3, 9]

Left:  [27, 43]  Right: [3, 9] (exhausted)
        ↑
Remaining: 27 → temp = [3, 9, 27]

Left:  [27, 43]
            ↑
Remaining: 43 → temp = [3, 9, 27, 43]

Result: [3, 9, 27, 43]
```

**Step-by-Step Visualization:**
```
Level 0:  [38, 27, 43, 3, 9, 82, 10]         (Original)
          
Level 1:  [38, 27, 43] | [3, 9, 82, 10]     (Divide)
          
Level 2:  [38] | [27, 43] | [3, 9] | [82, 10]  (Divide further)
          
Level 3:  [27] | [43] | [3] | [9] | [82] | [10]  (Base cases)
          
Level 2:  [27, 43] | [3, 9] | [10, 82]      (Merge pairs)
          
Level 1:  [3, 9, 27, 43] | [10, 82]         (Merge)
          
Level 0:  [3, 9, 10, 27, 43, 82]            (Final merge)
```

**Time Complexity:**
- Best Case: O(n log n)
- Average Case: O(n log n)
- Worst Case: O(n log n)

**Space Complexity:** O(n) - requires extra space for temporary arrays

**Characteristics:**
- ❌ Not in-place (requires O(n) extra space)
- ✅ Stable (maintains relative order of equal elements)
- ❌ Not adaptive (always takes O(n log n) time)
- ✅ Consistent performance across all cases
- ✅ Efficient for large datasets
- ✅ Parallelizable (divide-and-conquer nature)

**Example:**
```
Input: arr[] = {38, 27, 43, 3, 9, 82, 10}
Output: 3 9 10 27 38 43 82
```

**Memory Optimization:**

The standard implementation creates a new temporary vector in each merge call, which can be inefficient. Here's an optimized approach:

**Optimized Approach - Preallocate Temporary Array:**
```cpp
// Instead of creating temp vector in merge function:
void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;  // Creates new vector every call ❌
    // ... rest of merge
}

// Optimize by creating temp once in main and passing it:
void merge(vector<int> &arr, vector<int> &temp, int low, int mid, int high) {
    int left = low;
    int right = mid + 1;
    int k = low;  // Index for temp array
    
    while(left <= mid && right <= high) {
        if(arr[left] <= arr[right]) {
            temp[k++] = arr[left++];
        } else {
            temp[k++] = arr[right++];
        }
    }
    while(left <= mid) temp[k++] = arr[left++];
    while(right <= high) temp[k++] = arr[right++];
    
    // Copy back to original array
    for(int i = low; i <= high; i++) {
        arr[i] = temp[i];
    }
}

void mS(vector<int> &arr, vector<int> &temp, int low, int high) {
    if(low >= high) return;
    int mid = (low + high) / 2;
    mS(arr, temp, low, mid);
    mS(arr, temp, mid + 1, high);
    merge(arr, temp, low, mid, high);
}

void Merge_sort(vector<int> &arr, int n) {
    vector<int> temp(n);  // Create once, reuse throughout ✅
    mS(arr, temp, 0, n-1);
}
```

**Benefits of Optimization:**
- ✅ Reduces memory allocations from O(n log n) to O(n)
- ✅ Improves cache performance
- ✅ Faster execution due to reduced allocation overhead
- ✅ Same O(n) space complexity but with better constants

**When This Optimization Matters:**
- Large arrays (n > 10,000)
- Performance-critical applications
- Systems with limited memory bandwidth
- When merge sort is called repeatedly

---

### 5. Quick Sort

**Function:** `quick_sort(vector<int> &arr, int low, int high)`

A highly efficient divide-and-conquer algorithm that selects a pivot element and partitions the array around it, then recursively sorts the partitions. Uses tail call optimization to reduce stack space.

**Algorithm:**
1. Choose a pivot element (random selection for better average case)
2. Partition the array: elements smaller than pivot on left, larger on right
3. Pivot is now in its final sorted position
4. Recursively apply the same process to left and right subarrays
5. Use tail call optimization: recursively sort smaller partition, iterate on larger

**Working Example:**
```cpp
arr[] = {10, 7, 8, 9, 1, 5}
Pivot selection: random (shown with last element for simplicity)

Initial: [10, 7, 8, 9, 1, 5]
         Select pivot = 5

Partition Process:
  Compare 10 with 5: 10 > 5 → stays right
  Compare 7 with 5:  7 > 5 → stays right
  Compare 8 with 5:  8 > 5 → stays right
  Compare 9 with 5:  9 > 5 → stays right
  Compare 1 with 5:  1 < 5 → move to left
  Place pivot: [1, 5, 8, 9, 10, 7]
                   ↑
               pivot in position

Recursive Calls:
  Left: [1] → already sorted
  Right: [8, 9, 10, 7]
         Select pivot = 7
         Partition: [7, 9, 10, 8]
         Left: [] → empty
         Right: [9, 10, 8]
                Select pivot = 8
                Partition: [8, 10, 9]
                Left: [] → empty
                Right: [10, 9]
                       Select pivot = 9
                       Partition: [9, 10]
                       Result: [9, 10]

Final Result: [1, 5, 7, 8, 9, 10]
```

**Partition Visualization:**
```
Array: [10, 7, 8, 9, 1, 5]  pivot = 5
        ↑
        i=-1 (boundary between smaller and larger elements)

j=0: arr[0]=10 > 5 → no swap
     [10, 7, 8, 9, 1, 5]  i=-1

j=1: arr[1]=7 > 5 → no swap
     [10, 7, 8, 9, 1, 5]  i=-1

j=2: arr[2]=8 > 5 → no swap
     [10, 7, 8, 9, 1, 5]  i=-1

j=3: arr[3]=9 > 5 → no swap
     [10, 7, 8, 9, 1, 5]  i=-1

j=4: arr[4]=1 < 5 → i++, swap arr[0] ↔ arr[4]
     [1, 7, 8, 9, 10, 5]  i=0
                ↑

Finally: swap pivot (arr[high]) with arr[i+1]
     [1, 5, 8, 9, 10, 7]
         ↑
         Pivot at index 1
```

**Tail Call Optimization:**
```cpp
// Without optimization (recursive on both sides):
void quick_sort_basic(arr, low, high) {
    if(low < high) {
        int p = partition(arr, low, high);
        quick_sort_basic(arr, low, p-1);     // Left subarray
        quick_sort_basic(arr, p+1, high);    // Right subarray
    }
}
// Space: O(n) worst case - all recursive calls on stack

// With tail call optimization (iterative on larger partition):
void quick_sort(arr, low, high) {
    while(low < high) {
        int p = partition(arr, low, high);
        if(p-low < high-p) {  // Left is smaller
            quick_sort(arr, low, p-1);   // Recurse on smaller
            low = p + 1;                 // Iterate on larger
        } else {              // Right is smaller
            quick_sort(arr, p+1, high);  // Recurse on smaller
            high = p - 1;                // Iterate on larger
        }
    }
}
// Space: O(log n) - only smaller partition adds to stack
```

**Random Pivot Selection:**
```cpp
// Why random pivot?
Worst case for Quick Sort: Already sorted array with fixed pivot
arr[] = [1, 2, 3, 4, 5] with pivot = last element

Pass 1: pivot=5 → [1,2,3,4] | [5] → Imbalanced!
Pass 2: pivot=4 → [1,2,3] | [4,5] → Still imbalanced!
Pass 3: pivot=3 → [1,2] | [3,4,5]
...
Result: O(n²) time, O(n) space

// Random pivot selection:
- Pivot chosen randomly from [low...high]
- Swapped to the end before partitioning
- Makes worst case probabilistically rare
- Average case O(n log n) highly likely
```

**Time Complexity:**
- Best Case: O(n log n) - pivot divides array evenly
- Average Case: O(n log n) - random pivot gives balanced partitions
- Worst Case: O(n²) - pivot is always smallest/largest (rare with random selection)

**Space Complexity:** 
- O(log n) - with tail call optimization (only smaller partition on stack)
- O(n) - without optimization in worst case

**Characteristics:**
- ✅ In-place sorting (O(1) extra space if we ignore recursion stack)
- ❌ Not stable (can change relative order of equal elements)
- ❌ Not adaptive (doesn't detect sorted data)
- ✅ Cache-friendly (good locality of reference)
- ✅ Average case faster than Merge Sort (less overhead)
- ✅ Tail call optimization reduces stack depth
- ✅ Random pivot prevents worst case on sorted data

**Example:**
```
Input: arr[] = {56, 23, 45, 78, 23, 12, 4, 5, 67, 78, 89, 87, 34, 2, 312, 34, 4, 7}
Output: 2 4 4 5 7 12 23 23 34 34 45 56 67 78 78 87 89 312
```

**Optimizations Explained:**

1. **Random Pivot Selection:**
   - Prevents worst case on sorted/reverse sorted arrays
   - Makes O(n²) case probabilistically unlikely
   - Simple to implement with `rand()`

2. **Tail Call Optimization:**
   - Reduces stack space from O(n) to O(log n)
   - Always recurse on smaller partition
   - Iterate on larger partition
   - Critical for large arrays

3. **Why Quick Sort is "Quick":**
   - In-place partitioning (no extra arrays like Merge Sort)
   - Better cache performance (sequential access)
   - Fewer data movements than Merge Sort
   - Smaller constant factors in O(n log n)

**Comparison with Merge Sort:**
```
Quick Sort:
✅ In-place (O(log n) space)
✅ Faster average case (better cache, less overhead)
❌ Unstable
❌ Worst case O(n²)

Merge Sort:
❌ Requires O(n) extra space
❌ Slower in practice (more data movement)
✅ Stable
✅ Guaranteed O(n log n)
```

---

## Comparison Table

| Algorithm        | Best Case     | Average Case  | Worst Case   | Space     | Stable | Adaptive |
|------------------|---------------|---------------|--------------|-----------|--------|----------|
| Selection Sort   | O(n²)         | O(n²)         | O(n²)        | O(1)      | ❌     | ❌       |
| Bubble Sort      | O(n)          | O(n²)         | O(n²)        | O(1)      | ✅     | ✅       |
| Insertion Sort   | O(n)          | O(n²)         | O(n²)        | O(1)      | ✅     | ✅       |
| Merge Sort       | O(n log n)    | O(n log n)    | O(n log n)   | O(n)      | ✅     | ❌       |
| Quick Sort       | O(n log n)    | O(n log n)    | O(n²)*       | O(log n)  | ❌     | ❌       |

*With random pivot selection, the worst case is probabilistically rare.*

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

### Merge Sort:
- For large datasets (n > 10,000)
- When consistent O(n log n) performance is required
- When stability is important (preserving order of equal elements)
- For external sorting (sorting data that doesn't fit in memory)
- When parallel processing is available (divide-and-conquer is parallelizable)
- In applications where worst-case performance matters

### Quick Sort:
- **Most common choice for general-purpose sorting** (used in many standard libraries)
- For large datasets where average case performance matters
- When O(log n) space is acceptable but O(n) is not
- When cache performance is critical (better locality than Merge Sort)
- For in-memory sorting with good average performance
- When stability is not required
- In systems programming and performance-critical applications
- When dealing with random or uniformly distributed data

---

## Key Takeaways

1. **In-Place vs External Memory:** Quick Sort uses O(log n), Merge Sort uses O(n) space
2. **Comparison-Based:** All algorithms order elements through comparisons
3. **Understand Trade-offs:** Selection Sort minimizes swaps, Bubble Sort is adaptive, Quick Sort is fastest on average
4. **Time Complexity Matters:** O(n²) algorithms unsuitable for large datasets; O(n log n) scales well
5. **Stability Consideration:** Merge Sort and Insertion Sort are stable; Quick Sort and Selection Sort are not
6. **Optimization Helps:** Random pivot (Quick Sort), early termination (Bubble Sort), and memory reuse (Merge Sort) significantly improve performance
7. **Algorithm Selection:** Choose based on data characteristics, stability requirements, and space constraints
8. **Quick Sort Dominance:** Most widely used in practice due to excellent average case and cache performance
9. **Divide-and-Conquer Power:** Both Merge Sort and Quick Sort leverage this paradigm for O(n log n) performance

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
