#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, b, a[2007];

int main() {
    cin >> n >> b;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    ll maxn = b;
    for(ll i = 0; i < n; ++i) {
        for(ll j = i + 1; j < n; ++j) {
            maxn = max(maxn, b%a[i] + (b/a[i]) * a[j]);
        }
    }

    cout << maxn << endl;
    return 0;
}