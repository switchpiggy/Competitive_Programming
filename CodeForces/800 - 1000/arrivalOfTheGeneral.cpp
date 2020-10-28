#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    ll maxn = INT_MIN, minn = INT_MAX;
    for(ll i = 0; i < n; ++i) {
        maxn = max(maxn, a[i]);
        minn = min(minn, a[i]);
    }

    ll l = 0, r = 0;
    for(ll i = 0; i < n; ++i) {
        if(a[i] == maxn) {
            l = i;
            break;
        }
    }

    for(ll i = n - 1; i >= 0; --i) {
        if(a[i] == minn) {
            r = i;
            break;
        }
    }

    cout << l + (n - 1 - r) - (l > r) << '\n';
    return 0;
}