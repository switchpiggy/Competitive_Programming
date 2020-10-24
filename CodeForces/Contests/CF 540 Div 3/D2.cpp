#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a[200007];

bool check(ll x) {
    ll res = 0, cur = 0;

    for(ll j = n - 1; j >= n - n%x; --j) res += max(0ll, a[j] - n/x);

    for(ll j = 0; j < n - n%x; ++j) {
        if(j%x == 0 && j) cur++;
        res += max(0ll, a[j] - cur);
    }

    return res >= m;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    sort(a, a + n, greater<ll>());

    ll l = 1, r = n + 1, ans = -1;
    while(l < r) {
        ll m = (l + r)/2;
        if(check(m)) {
            ans = m;
            r = m;
        } else l = m + 1;
    }

    cout << ans << '\n';
    return 0;
}