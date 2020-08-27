#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a[2007];

int main() {
    cin >> n >> k;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    ll res = 0;
    for(ll i = 0; i < n; ++i) {
        if(5 - a[i] >= k) res++;
    }

    cout << res/3 << endl;
    return 0;
}