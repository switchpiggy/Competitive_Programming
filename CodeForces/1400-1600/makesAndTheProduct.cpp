#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[1000007];
map<ll, ll> occ;

ll choose(ll x, ll r) {
    ll ans = 1;
    for(ll i = 1; i <= r; ++i) {
        ans *= x - r + i;
        ans /= i;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    sort(a, a + n);

    for(ll i = 0; i < n; ++i) {
        occ[a[i]]++;
    }

    ll x = a[0], y = a[1], z = a[2];
    if(x == y && y == z) {
        cout << choose(occ[x], 3) << '\n';
    } else if(y == z) {
        cout << choose(occ[y], 2) << '\n';
    } else {
        cout << occ[z] << '\n';
    }

    return 0;
}