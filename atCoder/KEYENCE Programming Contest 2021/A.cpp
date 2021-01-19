#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[200007], b[200007], maxs[200007][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);    
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        maxs[i][0] = max((i ? maxs[i - 1][0] : 0), a[i]);
    }
    for(ll i = 0; i < n; ++i) {
        cin >> b[i];
        maxs[i][1] = max((i ? maxs[i - 1][1] : 0), b[i]);
    }

    ll res = 0;
    for(ll i = 0; i < n; ++i) {
        res = max(res, b[i] * maxs[i][0]);
        cout << res << '\n';
    }    
    return 0;
}