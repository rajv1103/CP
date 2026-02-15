#include <bits/stdc++.h>
#define int long long
using namespace std;

struct grup {
    int size;
    vector<int> tree;
    grup(int n=0): size(n), tree(n+1,0) {}
    void init(int n){
        size = n;
        tree.assign(n+1, 0);
    }
    void add(int idx){
        for(; idx <= size; idx += idx & -idx)
            tree[idx]++;
    }
    int sum(int idx){
        int s = 0;
        for(; idx > 0; idx -= idx & -idx)
            s += tree[idx];
        return s;
    }
};


pair<int, vector<int>> rce(const vector<int>& dog) {
    int n = dog.size() - 1;
    grup kitty(n);
    kitty.init(n);
    vector<int> rightInv(n+1);
    int total = 0;
   
    for(int i = n; i >= 1; --i) {
        rightInv[i] = kitty.sum(dog[i] - 1);
        total += rightInv[i];
        kitty.add(dog[i]);
    }
    return { total, rightInv };
}


vector<int> lre(const vector<int>& dog) {
    int n = dog.size() - 1;
    grup puppy(n);
    puppy.init(n);
    vector<int> leftGreat(n+1);
    
    for(int i = 1; i <= n; ++i) {
        int seenLessOrEq = puppy.sum(dog[i]);
        leftGreat[i] = (i - 1) - seenLessOrEq;
        puppy.add(dog[i]);
    }
    return leftGreat;
}

void fna() {
    int n; 
    cin >> n;
    vector<int> dog(n+1);
    for(int i = 1; i <= n; ++i)
        cin >> dog[i];

   
    auto [invTotal, rightInv] = rce(dog);
    
    vector<int> leftGreat = lre(dog);

    long long penalty = 0;
    for(int j = 1; j <= n; ++j) {
       
        long long D = (n - j) - rightInv[j] - leftGreat[j];
        if(D < 0) 
            penalty += D;
    }

    long long result = invTotal + penalty;
    cout << result << "\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while(t--) 
        fna();

    return 0;
}
