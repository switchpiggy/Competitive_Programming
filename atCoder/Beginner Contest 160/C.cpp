#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a[200007], diff[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    for(ll i = 0; i < n; ++i) {
        if(i == n - 1) {
            diff[i] = a[0] + (k - a[i]);
        } else diff[i] = a[i + 1] - a[i];
    }

    ll maxn = 0;
    for(ll i = 0; i < n; ++i) maxn = max(maxn, diff[i]);

    cout << k - maxn << endl;
    return 0;
}