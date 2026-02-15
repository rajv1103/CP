#include <bits/stdc++.h>
using namespace std;
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n & 1)
        {
            cout << "YES" << endl;
            continue;
        }
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 1; i < n - 1; i++)
        {
            int temp = arr[i - 1] - arr[i];
            arr[i] += temp;
            arr[i + 1] += temp;
        }
        if(arr[n-1]<arr[n-2]) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}
