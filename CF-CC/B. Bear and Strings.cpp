#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size(), last = 0;
    long long count = 0;

    for (int i = 0; i <= n - 4; ++i) {
        if (s.substr(i, 4) == "bear") {
            count += (i + 1 - last) * (n - (i + 3)); // Count the number of substrings
            last = i + 1;//
        }
    }
    cout << count << endl;
    return 0;
}
