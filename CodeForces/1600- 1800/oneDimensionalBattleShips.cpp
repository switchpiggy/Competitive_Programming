#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, m, a, x[200007];

bool check(ll q) {
    vector<bool> ok(n + 1, 0);
    for(ll i = 0; i < q; ++i) {
        ok[x[i]] = 1;
    }
    
    ll cur = 0, res = 0;
    for(ll i = 1; i <= n; ++i) {
        if(!ok[i]) cur++;
        else {
            res += (cur + 1)/(a + 1);
            cur = 0;
        }
    }

    if(cur) res += (cur + 1)/(a + 1);

    //cout << q << ' ' << res << '\n';
    return res < k;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> a >> m;
    for(ll i = 0; i < m; ++i) cin >> x[i];

    ll l = 0, r = m + 1, ans = -1;
    while(l < r) {
        ll mid = (l + r)/2;
        if(check(mid)) {
            ans = mid;
            r = mid;
        } else l = mid + 1;
    }

    cout << ans << '\n';
    return 0;
}