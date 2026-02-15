#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int& x : a) cin >> x;

    vector<int> improvement(k + 1, 0); // 1-based index

    int i = 0;
    while (i < n) {
        int l = i;
        int genre = a[i];
        while (i < n && a[i] == genre) i++; // find segment [l, i-1]
        int r = i - 1;

        // Check boundaries
        if (l == 0 || r == n - 1) {
            // Segment at start or end
            improvement[genre] += 1;
        } else {
            int left = a[l - 1];
            int right = a[r + 1];
            if (left == right) improvement[genre] += 2;
            else improvement[genre] += 1;
        }
    }

    // Find genre with maximum total improvement
    int bestGenre = 1;
    for (int g = 2; g <= k; ++g) {
        if (improvement[g] > improvement[bestGenre]) {
            bestGenre = g;
        }
    }

    cout << bestGenre << "\n";
    return 0;
}
