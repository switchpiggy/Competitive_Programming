#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct segTree {
    ll size;
    vector<ll> v;

    void init(ll x) {
        size = 1;
        while(size <= x) size *= 2;
        v.assign(size * 2, 0);
    }

    void set(ll i, ll val, ll x, ll lx, ll rx) {
        if(rx - lx == 1) {
            v[x] = val;
            return;
        }

        if(i < (lx + rx)/2) set(i, val, 2 * x + 1, lx, (lx + rx)/2);
        else set(i, val, 2 * x + 2, (lx + rx)/2, rx);

        v[x] = max(v[2 * x + 1], v[2 * x + 2]);
    }

    void set(ll i, ll val) {
        set(i, val, 0, 0, size);
    }

    ll find_max(ll x, ll lx, ll rx, ll l, ll r) {
        if(lx >= r || rx <= l) return 0;
        if(l <= lx && rx <= r) return v[x];

        return max(find_max(2 * x + 1, lx, (lx + rx)/2, l, r), find_max(2 * x + 2, (lx + rx)/2, rx, l, r));
    }

    ll find_max(ll l, ll r) {
        return find_max(0, 0, size, l, r);
    }
};

segTree st;
ll n, k, a[10007], dp[10007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
    cin >> n >> k;
    st.init(n + 1);
    for(ll i = 1; i <= n; ++i) {
        cin >> a[i];
        st.set(i, a[i]);
    }

    for(ll i = 0; i <= n; ++i) {
        for(ll j = 1; j <= k && i + j <= n; ++j) {
            dp[i + j] = max(dp[i + j], dp[i] + j * st.find_max(i + 1, i + j + 1));
        }
    }

    //for(ll i = 1; i <= n; ++i) cout << dp[i] << ' ';

    cout << dp[n] << '\n';
    return 0;
}