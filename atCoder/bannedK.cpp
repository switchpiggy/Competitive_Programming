#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[200007];
map<ll, ll> occ;

int main() {
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        occ[a[i]]++;
    }

    ll total = 0;
    for(ll i = 1; i <= n; ++i) {
        total += (occ[i] * (occ[i] - 1))/2;
    }

    for(ll i = 0; i < n; ++i) {
        cout << total - occ[a[i]] + 1 << endl;
    }

    return 0;
}