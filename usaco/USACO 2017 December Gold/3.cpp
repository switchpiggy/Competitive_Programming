#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, f, s, pf[100007];

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

    ll findMax(ll l, ll r, ll x, ll lx, ll rx) {
        if(rx <= l || lx >= r) return 0;
        if(l <= lx && rx <= r) return v[x];

        return max(findMax(l, r, 2 * x + 1, lx, (lx + rx)/2), findMax(l, r, 2 * x + 2, (lx + rx)/2, rx));
    }

    ll findMax(ll l, ll r) {
        return findMax(l, r, 0, 0, size);
    }
};

segTree st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("hayfeast.in", "r", stdin);
    freopen("hayfeast.out", "w", stdout);
    cin >> n >> m;
    st.init(n);

    for(ll i = 0; i < n; ++i) {
        cin >> f >> s;
        st.set(i, s);
        pf[i] = f;
        if(i) pf[i] += pf[i - 1];
    }

    ll ans = LONG_LONG_MAX;
    for(ll i = 0; i < n; ++i) {
        ll k = lower_bound(pf, pf + n, (i ? pf[i - 1] : 0) + m) - pf;
        //cout << k << '\n';
        if(k == n) continue;
        ans = min(ans, st.findMax(i, k + 1));
    }

    cout << ans << '\n';
    return 0;
}