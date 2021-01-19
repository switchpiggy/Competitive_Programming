#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define benq queue
#define pbenq priority_queue
#define all(x) (x.begin(), x.end())
ll n, a[300007], sp[300007][21][2];

bool ok(ll pos, ll end) {
    ll gcd = 0, mins = LLONG_MAX, l = pos, r = end;
    for(ll i = 20; i >= 0; --i) {
        if((1ll << i) <= r - l + 1) {
            gcd = __gcd(gcd, sp[l][i][1]);
            mins = min(mins, sp[l][i][0]);
            l += (1ll << i);
        }
    }

    //cout << gcd << ' ' << mins << '\n' << pos << ' ' << end << '\n';
    return gcd == mins;
}

bool check(ll x) {
    for(ll i = 0; i < n - x + 1; ++i) {
        if(ok(i, i + x - 1)) return 1;
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    for(ll i = 0; i < n; ++i) sp[i][0][0] = sp[i][0][1] = a[i];
    for(ll i = 1; i < 20; ++i) {
        for(ll j = 0; j < n - (1ll << i) + 1; ++j) {
            sp[j][i][0] = min(sp[j][i - 1][0], sp[j + (1ll << (i - 1))][i - 1][0]);
            sp[j][i][1] = __gcd(sp[j][i - 1][1], sp[j + (1ll << (i - 1))][i - 1][1]);
        }
    }

    ll l = 0, r = n + 1, ans = 0;
    while(l < r) {
        ll mid = (l + r)/2;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid;
    }

    //cout << ans - 1 << '\n';
    vector<ll> res;
    for(ll i = 0; i < n - ans + 1; ++i) {
        if(ok(i, i + ans - 1)) res.push_back(i + 1);
    }

    cout << (ll)res.size() << ' ' << ans - 1 << '\n';
    for(ll i : res) cout << i << ' ';
    //cout << '\n';
    //cout << check(5) << '\n';
    return 0;
}