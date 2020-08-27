#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x, f, a[200007];

int main() {
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    cin >> x >> f;

    ll res = 0;
    for(ll i = 0; i < n; ++i) {
        res += a[i]/(f + x);
        if(a[i]%(f + x) > x) res++; 
    }

    cout << res * f << endl;
    return 0;
}