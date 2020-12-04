#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, q, a[1000007], k[1000007];

bool check(ll x) {
    ll cnt = 0;
    for(ll i = 0; i < n; ++i) if(a[i] <= x) cnt++;
    for(ll i = 0; i < q; ++i) {
        if(k[i] > 0 && k[i] <= x) cnt++;
        if(k[i] < 0 && abs(k[i]) <= cnt) cnt--;
    }

    return (cnt > 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    for(ll i = 0; i < q; ++i) cin >> k[i];

    ll l = 0, r = 1000001;
    if(!check(10000000000)) {
        cout << "0\n";
        return 0;
    }

    ll ans = 0;
    while(l < r) {
        ll m = (l + r)/2;
        if(check(m)) {
            ans = m;
            r = m;
        } else {
            l = m + 1;
        }
    }

    cout << ans << '\n';
    return 0;
}