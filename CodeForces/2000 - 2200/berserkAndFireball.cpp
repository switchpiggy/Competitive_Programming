#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, x, k, y, a[200007], b[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> x >> k >> y;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    for(ll i = 0; i < m; ++i) cin >> b[i];

    ll cur = 0, maxn = 0, len = 0, ans = 0;
    for(ll i = 0; i < n; ++i) {
        if(cur < m && a[i] == b[cur]) {
            cur++;
            if(!len) continue;
            ll res = 0, p = (i - len - 1 < 0 ? 0 : a[i - len - 1]);

            if(!(len < k && maxn > p && maxn > a[i])) {
                res = len/k * x;
                if(maxn <= a[i] || maxn <= p) res = min(res, (len - len%k) * y);
                else res = min(res, (len - len%k - k) * y + x);
            } else  {
                cout << "-1\n";
                return 0;
            }

            ans += res + len%k * y;
            len = 0;
            maxn = 0;
        } else {
            len++;
            maxn = max(maxn, a[i]);
        }
    }

    if(cur < m) {
        //cout << cur << ' ';
        cout << "-1\n";
        return 0;
    }

    if(len) {
            ll res = 0, p = (n - 1 - len < 0 ? 0 : a[n - 1 - len]);

            if(!(len < k && maxn > p)) {
                res = len/k * x;
                if(maxn <= p) res = min(res, (len - len%k) * y);
                else res = min(res, (len - len%k - k) * y + x);
            } else  {
                //cout << p << ' ' << maxn << '\n';
                cout << "-1\n";
                return 0;
            }

            ans += res + len%k * y;
    }

    cout << ans << '\n';
    return 0;
}