#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benqueue queue
#define pbenqueue priority_queue
ll t, n, k, a[200007];

bool check(ll x) {
    ll res = 0, tot = 0;
    for(ll i = 1; i < x; ++i) {
        res += i;
        tot += 2 * i - 1;
    }

    for(ll i = k - x + 2; i < k; ++i) res += k - i;

    //cout << x << ' ' << res << ' ' << tot << '\n';
    //for(ll i = k + x + 1; i <= n; ++i) res += i;
    return res <= tot;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k;
        ll ans = 0;
        ll l = 0, r = n - k + 1;
        if(check(r)) ans = r;
        else {
        while(l < r) {
            ll mid = (l + r)/2;
            if(check(mid)) {
                ans = mid;
                l = mid + 1;
            } else r = mid;
        }
        }

        for(ll i = 1; i <= k; ++i) a[i] = i;
        //cout << k - ans + 1 << ' ';
        reverse(a + (k - ans + 1), a + k + 1);
        for(ll i = 1; i <= k; ++i) cout << a[i] << ' ';
        cout << '\n';
    }

    return 0;
    //cout << check(2) << '\n';
}