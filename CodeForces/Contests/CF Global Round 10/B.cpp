#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t ,n, k, a[200007];

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(ll i = 0; i < n; ++i) cin >> a[i];
        ll maxn = INT_MIN;
        for(ll i = 0; i < n; ++i) {
            maxn = max(maxn, a[i]);
        }

        ll maxn2 = INT_MIN;
        for(ll i = 0; i < n; ++i) {
            a[i] = maxn - a[i];
            maxn2 = max(maxn2, a[i]);
        }

        if((k - 1)%2 == 0) {
            for(ll i = 0; i < n; ++i) cout << a[i] << ' ';
            cout << '\n';
            continue;
        }

        for(ll i = 0; i < n; ++i) a[i] = maxn2 - a[i];
        for(ll i = 0; i < n; ++i) cout << a[i] << ' ';
        cout << endl;
    }

    return 0;
}