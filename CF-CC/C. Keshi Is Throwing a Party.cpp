//In the name of God
#include <bits/stdc++.h>
using namespace std;
 
typedef int ll;
typedef pair<ll, ll> pll;
 
const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;
 
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()
 
ll q, n, a[maxn], b[maxn];
 
bool ok(ll x){
	ll c = 0;
	for(ll i = 0; i < n; i++){
		if(x - 1 - a[i] <= c && c <= b[i]) c++;
	}
	return c >= x;
}
 
int main(){
    fast_io;
    
    cin >> q;
    while(q--){
        cin >> n;
        for(ll i = 0; i < n; i++){
        	cin >> a[i] >> b[i];
    	}
    	ll l = -1, r = n + 1, mid;
    	while(r - l > 1){
    		mid = (l + r) >> 1;
    		if(ok(mid)) l = mid;
    		else r = mid;
    	}
    	cout << l << "\n";
    }
    return 0;
}