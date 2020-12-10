#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s;

bool ok(ll x) {
    ll last = -1, r = -1, rr = -1;
    for(ll i = 0; i < n; ++i) {
        if(s[i] == '*' && last == -1 && i > rr) last = i;
        if(s[i] == 'P') {
            if(last != -1) {
                if(i - last > x) return 0;
                r = max(x - 2 * (i - last), (x - (i - last))/2);
            } else r = x;
            rr = i + max(0ll, r);
            last = -1;
        }
    }

    if(last == -1) return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    ll l = 0, r = 1e18;
    ll ans = INT_MAX;
    while(l < r) {
        ll m = (l + r)/2;
        if(ok(m)) {
            ans = m;
            r = m;
        } else l = m + 1;
    }

    cout << ans << '\n';
    return 0;
}