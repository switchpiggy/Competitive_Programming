#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll l[1000007], r[1000007], a[1000007];
map<ll, ll> cnt;
ll n;

struct segTree {
    ll size;
    vector<ll> v;

    void init(ll x) {
        size = 1;
        while(size <= x) size *= 2;
        v.assign(size * 2, 0);
    }

    void add(ll i, ll val, ll x, ll lx, ll rx) {
        if(rx - lx == 1) {
            v[x] += val;
            return;
        }

        if(i < (lx + rx)/2) add(i, val, 2 * x + 1, lx, (lx + rx)/2);
        else add(i, val, 2 * x + 2, (lx + rx)/2, rx);

        v[x] = v[2 * x + 1] + v[2 * x + 2];
    }

    void add(ll i, ll val) {
        add(i, val, 0, 0, size);
    }

    ll sum(ll l, ll r, ll x, ll lx, ll rx) {
        if(rx <= l || r <= lx) return 0;
        if(l <= lx && rx <= r) return v[x];

        return sum(l, r, 2 * x + 1, lx, (lx + rx)/2) + sum(l, r, 2 * x + 2, (lx + rx)/2, rx);
    }

    ll sum(ll l, ll r) {
        return sum(l, r, 0, 0, size);
    }
};

segTree st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    for(ll i = 0; i < n; ++i) {
        l[i] = cnt[a[i]];
        cnt[a[i]]++;
    }

    cnt.clear();
    for(ll i = n - 1; i >= 0; --i) {
        r[i] = cnt[a[i]];
        cnt[a[i]]++;
    }

    ll ans = 0;
    st.init(1000001);

    for(ll i = n - 1; i >= 0; --i) {
        ans += st.sum(0, l[i]);
        st.add(r[i], 1);
    }

    cout << ans << '\n';
    return 0;
}