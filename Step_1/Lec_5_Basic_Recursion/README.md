# Basic Recursion

A comprehensive collection of fundamental recursion problems implemented in C++. These problems demonstrate core recursive thinking patterns and techniques essential for problem-solving in data structures and algorithms.

## Table of Contents

1. [Print Numbers 1 to N](#1-print-numbers-1-to-n)
2. [Print Numbers N to 1](#2-print-numbers-n-to-1)
3. [Sum of First N Numbers](#3-sum-of-first-n-numbers)
4. [Factorial of N](#4-factorial-of-n)
5. [Print Array](#5-print-array)
6. [Print Array in Reverse](#6-print-array-in-reverse)
7. [Check Palindrome String](#7-check-palindrome-string)
8. [Fibonacci Number](#8-fibonacci-number)

---

## What is Recursion?

Recursion is a programming technique where a function calls itself to solve a problem by breaking it down into smaller, similar subproblems.

### Key Components of Recursion:
1. **Base Case:** Condition that stops the recursion
2. **Recursive Case:** Function calls itself with modified parameters
3. **Progress:** Each recursive call moves closer to the base case

---

## Problems Overview

### 1. Print Numbers 1 to N

**Function:** `print_n_asc(int i, int n)`

Prints numbers from 1 to N in ascending order using recursion.

**Algorithm:**
- Base case: If `i > n`, return
- Print current number `i`
- Recursively call with `i+1`

**Recursion Tree (n=5):**
```
print_n_asc(1, 5) → prints 1
  └─ print_n_asc(2, 5) → prints 2
      └─ print_n_asc(3, 5) → prints 3
          └─ print_n_asc(4, 5) → prints 4
              └─ print_n_asc(5, 5) → prints 5
                  └─ print_n_asc(6, 5) → return
```

**Time Complexity:** O(n)  
**Space Complexity:** O(n) - recursion stack

**Example:**
```
Input: print_n_asc(1, 5)
Output: 1 2 3 4 5
```

---

### 2. Print Numbers N to 1

**Function:** `print_n_dec(int i, int n)`

Prints numbers from N to 1 in descending order using recursion.

**Algorithm:**
- Base case: If `n < 1`, return
- Print current number `n`
- Recursively call with `n-1`

**Recursion Tree (n=5):**
```
print_n_dec(1, 5) → prints 5
  └─ print_n_dec(1, 4) → prints 4
      └─ print_n_dec(1, 3) → prints 3
          └─ print_n_dec(1, 2) → prints 2
              └─ print_n_dec(1, 1) → prints 1
                  └─ print_n_dec(1, 0) → return
```

**Time Complexity:** O(n)  
**Space Complexity:** O(n)

**Example:**
```
Input: print_n_dec(1, 5)
Output: 5 4 3 2 1
```

---

### 3. Sum of First N Numbers

**Function:** `print_sum(int i, int n, int sum = 0)`

Calculates the sum of numbers from 1 to N using recursion with accumulator.

**Algorithm:**
- Base case: If `i > n`, print sum and return
- Recursively call with `i+1` and `sum+i`
- Uses tail recursion optimization with accumulator

**Recursion Flow:**
```
print_sum(1, 5, 0)
  → print_sum(2, 5, 1)
    → print_sum(3, 5, 3)
      → print_sum(4, 5, 6)
        → print_sum(5, 5, 10)
          → print_sum(6, 5, 15)
            → prints 15
```

**Time Complexity:** O(n)  
**Space Complexity:** O(n)

**Example:**
```
Input: print_sum(1, 5)
Output: 15
Explanation: 1+2+3+4+5 = 15
```

---

### 4. Factorial of N

**Function:** `print_factorial(int n, int sum = 1)`

Calculates factorial of N using recursion with accumulator.

**Algorithm:**
- Base case: If `n < 1`, print factorial and return
- Recursively call with `n-1` and `sum*n`
- Uses tail recursion with accumulator pattern

**Recursion Flow:**
```
print_factorial(5, 1)
  → print_factorial(4, 5)
    → print_factorial(3, 20)
      → print_factorial(2, 60)
        → print_factorial(1, 120)
          → print_factorial(0, 120)
            → prints 120
```

**Formula:** n! = n × (n-1)!

**Time Complexity:** O(n)  
**Space Complexity:** O(n)

**Example:**
```
Input: print_factorial(5)
Output: 120
Explanation: 5! = 5×4×3×2×1 = 120
```

---

### 5. Print Array

**Function:** `print_array(int arr[], int n, int i = 0)`

Prints all elements of an array using recursion.

**Algorithm:**
- Print element at index `i`
- Base case: If `i == n`, return
- Recursively call with `i+1`

**Time Complexity:** O(n)  
**Space Complexity:** O(n)

**Example:**
```
Input: arr[] = {1, 2, 3, 4}, n = 3
Output: 1 2 3 4
```

---

### 6. Print Array in Reverse

**Function:** `print_reverse_array(int arr[], int n)`

Prints array elements in reverse order using recursion.

**Algorithm:**
- Print element at index `n`
- Base case: If `n == 0`, return
- Recursively call with `n-1`

**Recursion Order:**
```
print_reverse_array(arr, 3) → prints arr[3]
  └─ print_reverse_array(arr, 2) → prints arr[2]
      └─ print_reverse_array(arr, 1) → prints arr[1]
          └─ print_reverse_array(arr, 0) → prints arr[0]
              └─ return
```

**Time Complexity:** O(n)  
**Space Complexity:** O(n)

**Example:**
```
Input: arr[] = {1, 2, 3, 4}, n = 3
Output: 4 3 2 1
```

---

### 7. Check Palindrome String

**Function:** `print_palindrome(string& s, int i)`

Checks if a string is a palindrome using recursion and two-pointer technique.

**Algorithm:**
- Base case: If `i > length/2`, string is palindrome
- Compare character at position `i` with character at `length-i-1`
- If they don't match, return false
- Recursively check next pair

**Recursion Flow for "racecar":**
```
i=0: s[0]='r' == s[6]='r' ✓
  → i=1: s[1]='a' == s[5]='a' ✓
      → i=2: s[2]='c' == s[4]='c' ✓
          → i=3: 3 > 7/2, return true
```

**Time Complexity:** O(n/2) = O(n)  
**Space Complexity:** O(n/2) = O(n)

**Example:**
```
Input: "racecar"
Output: true

Input: "hello"
Output: false
```

---

### 8. Fibonacci Number

**Function:** `faboncci(int n)`

Calculates the nth Fibonacci number using recursion.

**Algorithm:**
- Base cases: 
  - If `n == 0`, return 0
  - If `n == 1`, return 1
- Recursive case: `fib(n) = fib(n-1) + fib(n-2)`

**Recursion Tree for fib(5):**
```
                          fib(5)
                        /        \
                   fib(4)         fib(3)
                 /       \       /       \
            fib(3)     fib(2)  fib(2)    fib(1)
           /     \     /    \   /   \
      fib(2)  fib(1) fib(1) fib(0) fib(1) fib(0)
      /    \
  fib(1)  fib(0)

```

**Fibonacci Sequence:** 0, 1, 1, 2, 3, 5, 8, 13, 21, 34...

**Time Complexity:** O(2ⁿ) - exponential (without memoization)  
**Space Complexity:** O(n) - recursion depth

**Example:**
```
Input: faboncci(6)
Output: 8
Explanation: 0, 1, 1, 2, 3, 5, 8
```

**Note:** This implementation has exponential time complexity. For better performance, use dynamic programming or memoization.

---

## Recursion Patterns Used

### 1. **Simple Recursion**
- Function calls itself with modified parameter
- Example: `print_n_asc`, `print_n_dec`

### 2. **Tail Recursion**
- Recursive call is the last operation
- Can be optimized by compiler
- Example: `print_sum`, `print_factorial`

### 3. **Multiple Recursion**
- Function makes multiple recursive calls
- Example: `faboncci` (makes 2 recursive calls)

### 4. **Two-Pointer Recursion**
- Uses index to compare elements from both ends
- Example: `print_palindrome`

---

## Complexity Summary

| Function              | Time Complexity | Space Complexity | Recursion Type |
|-----------------------|-----------------|------------------|----------------|
| print_n_asc           | O(n)            | O(n)             | Simple         |
| print_n_dec           | O(n)            | O(n)             | Simple         |
| print_sum             | O(n)            | O(n)             | Tail           |
| print_factorial       | O(n)            | O(n)             | Tail           |
| print_array           | O(n)            | O(n)             | Simple         |
| print_reverse_array   | O(n)            | O(n)             | Simple         |
| print_palindrome      | O(n)            | O(n)             | Two-pointer    |
| fibonacci             | O(2ⁿ)           | O(n)             | Multiple       |


---

## Key Concepts

### Stack Overflow
- Recursion uses call stack memory
- Too many recursive calls can cause stack overflow
- Solution: Use iteration or tail recursion optimization

### Tail Recursion Optimization
- When recursive call is the last operation
- Compiler can optimize to iterative code
- Examples: `print_sum`, `print_factorial`

### Base Case Importance
- Every recursion MUST have a base case
- Prevents infinite recursion
- Defines when to stop recursing

---

## Common Recursion Mistakes

1. **Missing Base Case:** Causes infinite recursion and stack overflow
2. **Wrong Progress:** Recursive call doesn't move towards base case
3. **Multiple Base Cases:** Forgetting to handle all edge cases
4. **Inefficient Recursion:** Like Fibonacci without memoization

---

## When to Use Recursion

✅ **Good for:**
- Tree/Graph traversal
- Divide and conquer algorithms
- Backtracking problems
- Problems with recursive structure

❌ **Avoid when:**
- Simple iteration is clearer
- Stack space is limited
- Performance is critical (without optimization)

---

## Learning Objectives

These problems help develop:
- Recursive thinking and problem decomposition
- Understanding call stack and memory usage
- Base case identification
- Converting iterative logic to recursive
- Recognizing recursion patterns

---

## Author

Part of Striver's A2Z DSA Course - Step 1, Lecture 5 (Basic Recursion)
