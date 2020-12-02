#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, w, a[100007];

bool check(ll x) {
    vector<ll> b(n + 1, 0);

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        if(i) b[i] += b[i - 1];
        if(a[i] < x) {
            if(b[i] >= x - a[i]) continue;
            else {
                ll cur = (x - a[i]) - b[i];
                b[i] += cur;
                ans += cur;
                if(i + w < n) b[i + w] -= cur;
            }
        }
    }

    return (ans <= m);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> w;

    ll mins = LONG_LONG_MAX;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        mins = min(mins, a[i]);
    }

    ll l = mins, r = 10000000001, ans = -1;
    while(l < r) {
        ll mid = (l + r)/2;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid;
    }

    cout << ans << '\n';
    return 0;
}