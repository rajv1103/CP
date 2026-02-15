#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long p = 1;
    while (n%p==0) {
        p *= 3;
       
    }
    cout << (n+p-1)/p << endl;
    return 0;
}
