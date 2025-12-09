# Basic Maths Problems

A collection of fundamental mathematical programming problems implemented in C++. These problems cover essential number theory and mathematical operations commonly used in competitive programming and interviews.

## Table of Contents

1. [Count Digits](#1-count-digits)
2. [Reverse Number](#2-reverse-number)
3. [Palindrome Check](#3-palindrome-check)
4. [GCD and LCM](#4-gcd-and-lcm)
5. [Armstrong Number Check](#5-armstrong-number-check)
6. [Print All Factors](#6-print-all-factors)
7. [Prime Number Check](#7-prime-number-check)

---

## Problems Overview

### 1. Count Digits

**Function:** `count_digit(int n)`

Counts the number of digits in a given number.

**Algorithm:**
- Uses logarithm formula: `digits = log10(n) + 1`
- Special handling for `n = 0` (has 1 digit)
- Uses `abs()` to handle negative numbers

**Time Complexity:** O(1)

**Example:**
```
Input: -12313
Output: Number of digits: 5
```

---

### 2. Reverse Number

**Function:** `reverse_number(int n)`

Reverses the digits of a given number.

**Algorithm:**
1. Extract last digit using `n % 10`
2. Build reversed number: `reversed = reversed * 10 + digit`
3. Remove last digit: `n /= 10`
4. Repeat until `n = 0`

**Time Complexity:** O(log₁₀n) - proportional to number of digits

**Example:**
```
Input: -12313
Output: Reversed number: -31321
```

---

### 3. Palindrome Check

**Function:** `palindrome_check(int n)`

Checks if a number reads the same forwards and backwards.

**Algorithm:**
- Returns false for negative numbers
- Returns false for numbers ending in 0 (except 0 itself)
- Reverses half the number and compares with the other half
- Handles odd-length numbers by dividing reversed by 10

**Time Complexity:** O(log₁₀n)

**Example:**
```
Input: 101101
Output: true

Input: 12321
Output: true
```

---

### 4. GCD and LCM

**Function:** `gcd_lcm(int a, int b)`

Calculates both Greatest Common Divisor (GCD) and Least Common Multiple (LCM) of two numbers.

**Algorithm:**
- **GCD:** Uses Euclidean algorithm
  - `gcd(a, b) = gcd(b, a % b)`
  - Base case: when `b = 0`, GCD is `a`
- **LCM:** Uses formula `LCM(a, b) = (a × b) / GCD(a, b)`

**Time Complexity:** O(log(min(a, b)))

**Example:**
```
Input: 12, 15
Output: 
GCD: 3
LCM: 60
```

---

### 5. Armstrong Number Check

**Function:** `armstrong_check(int n)`

Checks if a number is an Armstrong number (sum of its digits raised to the power of number of digits equals the number itself).

**Algorithm:**
1. Count number of digits
2. For each digit, raise it to the power of total digits
3. Sum all powered digits
4. Compare sum with original number

**Time Complexity:** O(d²) where d is number of digits

**Examples:**
```
153 = 1³ + 5³ + 3³ = 1 + 125 + 27 = 153 ✓
370 = 3³ + 7³ + 0³ = 27 + 343 + 0 = 370 ✓
9474 = 9⁴ + 4⁴ + 7⁴ + 4⁴ = 6561 + 256 + 2401 + 256 = 9474 ✓
```

**Output:**
```
Input: 153
Output: true
```

---

### 6. Print All Factors

**Function:** `factors(int n)`

Prints all factors (divisors) of a number in sorted order.

**Algorithm:**
1. Iterate only up to √n
2. If `i` divides `n`, both `i` and `n/i` are factors
3. Avoid duplicates when `i = n/i` (perfect square case)
4. Sort factors before printing

**Time Complexity:** O(√n) for finding + O(f log f) for sorting (where f is number of factors)

**Example:**
```
Input: 28
Output: 1 2 4 7 14 28
```

---

### 7. Prime Number Check

**Function:** `prime_check(int n)`

Checks if a number is prime (only divisible by 1 and itself).

**Algorithm:**
- Numbers ≤ 1 are not prime
- 2 is the only even prime
- Check divisibility only up to √n
- If any number divides n, it's not prime

**Time Complexity:** O(√n)

**Example:**
```
Input: 29
Output: true

Input: 28
Output: false
```

---

### Optimizations Used

1. **Factor Finding:** Only iterate up to √n instead of n
2. **Prime Check:** Only check divisibility up to √n
3. **Digit Count:** Use logarithm instead of loop
4. **Palindrome Check:** Only reverse half the number

---

## Complexity Summary

| Function         | Time Complexity        | Space Complexity |
|------------------|-------------------------|------------------|
| count_digit      | O(1)                    | O(1)             |
| reverse_number   | O(log n)                | O(1)             |
| palindrome_check | O(log n)                | O(1)             |
| gcd_lcm          | O(log(min(a, b)))       | O(1)             |
| armstrong_check  | O(d²)                   | O(1)             |
| factors          | O(√n)                   | O(f)             |
| prime_check      | O(√n)                   | O(1)             |

*where d = number of digits, f = number of factors*

---

## Learning Objectives

These problems help develop:
- Understanding of number theory
- Efficient algorithm design
- Mathematical optimization techniques
- Handling edge cases (negative numbers, zero, etc.)
- Time complexity analysis

---

## Common Pitfalls

1. **Overflow:** When reversing numbers or calculating LCM, use appropriate data types
2. **Negative Numbers:** Handle sign separately in reversal and digit counting
3. **Zero Handling:** Special case in logarithm-based digit counting
4. **Perfect Squares:** Avoid duplicate factors when i = n/i

---

## Author

Part of Striver's A2Z DSA Course - Step 1, Lecture 4 (Basic Maths)
