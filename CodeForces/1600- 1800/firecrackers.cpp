#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
ll t, n, m, a, b, s[200007];

bool check(ll x) {
    if(x > abs(b - a) - 1) return 0;
    ll survive = (b > a ? b - 1 : n - b), maxtime = LLONG_MIN;
    for(ll i = 0; i < x; ++i) {
        maxtime = max(maxtime, s[i] + (x - i));
    }

    return maxtime <= survive;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m >> a >> b;
        for(ll i = 0; i < m; ++i) {
            cin >> s[i];
        }

        sort(s, s + m);
        ll l = -1, r = m + 1, ans = -1;
        while(l < r) {
            ll mid = (l + r)/2;
            if(check(mid)) {
                ans = mid;
                l = mid + 1;
            } else r = mid;
        }

        cout << ans << '\n';
    }

    return 0;
}