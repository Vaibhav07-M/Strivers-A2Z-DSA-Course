#include <iostream>
using namespace std;

void pattern1(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "* ";
        }
        cout << "\n";
    }
}
void pattern2(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "* ";
        }
        cout << "\n";
    }
}
void pattern3(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j;
        }
        cout << "\n";
    }
}
void pattern4(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << i;
        }
        cout << "\n";
    }
}
void pattern5(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << "\n";
    }
}
void pattern6(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << j;
        }
        cout << "\n";
    }
}
void pattern7(int n) {
    for(int i=0; i<n;i++) {
        for(int j=0; j<n-i-1; j++) {
            cout<<" ";
        }
        for(int j=0; j<2*i+1; j++) {
            cout<<"*";
        }
        for(int j=0; j<n-i-1; j++) {
            cout<<" ";
        }
        cout<<endl;
    }
}
void pattern8(int n) {
    for(int i=0; i<n;i++) {
        for(int j=0; j<i; j++) {
            cout<<" ";
        }
        for(int j=0; j<2*n-(2*i+1); j++) {
            cout<<"*";
        }
        for(int j=0; j<i; j++) {
            cout<<" ";
        }
        cout<<endl;
    }
}
void pattern9(int n) {
    for(int i=0;i<n;i++) {
        for(int j=0; j<n-i-1;j++) {
            cout<<" ";
        }
        for(int j=0; j<2*i+1;j++) {
            cout<<"*";
        }
        for(int j=0; j<n-i-1;j++) {
            cout<<" ";
        }
        cout<<endl;
    }
    for(int i=1;i<n;i++) {
        for(int j=0; j<i;j++) {
            cout<<" ";
        }
        for(int j=0; j<2*n-(2*i+1);j++) {
            cout<<"*";
        }
        for(int j=0; j<i;j++) {
            cout<<" ";
        }
        cout<<endl;
    }
}
void pattern10(int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<i+1;j++) {
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-i-1;j++) {
            cout<<"*";
        }
        cout<<endl;
    }
}
void pattern11(int n) {
    int start;
    for(int i=0;i<n;i++) {
        if(i%2 == 0) start = 1;
        else start = 0;
        for(int j=0;j<i+1;j++) {
            cout<<start;
            start = 1 - start;
        }
        cout<<endl;
    }
}
void pattern12(int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<=i;j++){
            cout<<j+1;
        }
        for(int j=0;j<2*(n-i-1);j++) {
            cout<<" ";
        }
        for(int j=i+1;j>0;j--){
            cout<<j;
        }
        cout<<endl;
    }
}
void pattern13(int n) {
    int count = 1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<=i;j++) {
            cout<<count<<" ";
            count++;
        }
        cout<<endl;
    }
}
void pattern14(int n) {
    for(int i=0;i<n;i++) {
        for(char ch='A';ch<'A'+i+1;ch++) {
            cout<<ch;
        }
        cout<<endl;
    }
}
void pattern15(int n) {
    for(int i=n;i>0;i--) {
        for(char ch='A';ch<'A'+i;ch++) {
            cout<<ch;
        }
        cout<<endl;
    }
}
void pattern16(int n) {
    char ch='A';
    for(int i=0;i<n;i++) {
        for(int j=0;j<i+1;j++) {
            cout<<ch;
        }
        ch++;
        cout<<endl;
    }
}
void pattern17(int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-i-1;j++) {
            cout<<" ";
        }
        for(char ch='A';ch<'A'+i+1;ch++) {
            cout<<ch;
        }
        for(char ch='A'+i-1;ch>'A'-1;ch--) {
            cout<<ch;
        }
        cout<<endl;
    }
}
void pattern18(int n) {
    for(int i=n;i>0;i--) {
        for(char ch='A'+i-1;ch<'A'+n;ch++) {
            cout<<ch;
        }
        cout<<endl;
    }
}
void pattern19(int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-i;j++) {
            cout<<"*";
        }
        for(int j=0;j<2*i;j++) {
            cout<<" ";
        }
        for(int j=0;j<n-i;j++) {
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++) {
            cout<<"*";
        }
        for(int j=0;j<2*(n-i-1);j++) {
            cout<<" "; 
        }
        for(int j=0;j<i+1;j++) {
            cout<<"*";
        }
        cout<<endl;
    }
}
void pattern20(int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<i+1;j++) {
            cout<<"*";
        }
        for(int j=0;j<2*(n-i-1);j++) {
            cout<<" ";
        }
        for(int j=0;j<i+1;j++) {
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=1;i<n;i++) {
        for(int j=0;j<n-i;j++) {
            cout<<"*";
        }
        for(int j=0;j<2*i;j++) {
            cout<<" ";
        }
        for (int j=0;j<n-i;j++) {
            cout<<"*";
        }
        cout<<endl;
    }
}
void pattern21(int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i==0 || i==n-1 || j==0 | j==n-1) cout<<"*";
            else cout<<" ";
        }
        cout<<endl;
    }
}
void pattern22(int n) {
    for(int i=0;i<2*n-1;i++) {
        for(int j=0;j<2*n-1;j++) {
            int top = i;
            int left = j;
            int right = (2*n-2) - j;
            int bottom = (2*n-2) - i;
            cout<<n - min(min(top,bottom),min(left,right));
        }
        cout<<endl;
    }
}

int main() {
    cout<<"\nPattern 1: Square Pattern\n";
    pattern1(5);
    cout<<"\nPattern 2: Right Triangle\n";
    pattern2(5);
    cout<<"\nPattern 3: Number Triangle\n";
    pattern3(5);
    cout<<"\nPattern 4: Repeated Number Triangle\n";
    pattern4(5);
    cout<<"\nPattern 5: Inverted Right Triangle\n";
    pattern5(5);
    cout<<"\nPattern 6: Inverted Number Triangle\n";
    pattern6(5);
    cout<<"\nPattern 7: Pyramid\n";
    pattern7(5);
    cout<<"\nPattern 8: Inverted Pyramid\n";
    pattern8(5);
    cout<<"\nPattern 9: Diamond\n";
    pattern9(5);
    cout<<"\nPattern 10: Half Diamond\n";
    pattern10(5);
    cout<<"\nPattern 11: Binary Triangle\n";
    pattern11(5);
    cout<<"\nPattern 12: Number Crown\n";
    pattern12(5);
    cout<<"\nPattern 13: Increasing Number Triangle\n";
    pattern13(5);
    cout<<"\nPattern 14: Alphabet Triangle\n";
    pattern14(5);
    cout<<"\nPattern 15: Inverted Alphabet Triangle\n";
    pattern15(5);
    cout<<"\nPattern 16: Repeated Alphabet Triangle\n";
    pattern16(5);
    cout<<"\nPattern 17: Alphabet Pyramid\n";
    pattern17(5);
    cout<<"\nPattern 18: Reverse Alphabet Triangle\n";
    pattern18(5);
    cout<<"\nPattern 19: Symmetric Butterfly\n";
    pattern19(5);
    cout<<"\nPattern 20: Hollow Butterfly\n";
    pattern20(5);
    cout<<"\nPattern 21: Hollow Square\n";
    pattern21(5);
    cout<<"\nPattern 22: Number Square (Concentric)\n";
    pattern22(5);
    return 0;
}