#include <bits/stdc++.h>
using namespace std;

void count_digit(int n) {
    int count = 0;
    if (n == 0) {
        count = 1; // 0 has 1 digit
    } else {
        count = log10(abs(n)) + 1; // abs() to handle negative numbers
    }
    cout << "Number of digits: " << count << endl;
}
void reverse_number(int n) {
    int reversed = 0;
    while (n != 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }
    cout << "Reversed number: " << reversed << endl;
}
void palindrome_check(int n) {
    int original = n;
    int rev = 0;

    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }

    cout << (rev == original ? "true" : "false");
}


int main() {
    count_digit(-12313);
    reverse_number(-12313);
    palindrome_check(0);
    return 0;
}