#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, p[100007], sum[100007], a[100007];

struct segTree {
    ll size;
    vector<ll> v;

    void init(ll x) {
        size = 1;
        while(size <= x) size *= 2;
        v.assign(size * 2, 0);
    }

    void set(ll i, ll val, ll x , ll lx, ll rx) {
        if(rx - lx == 1) {
            v[x] = val;
            return;
        }

        if(i < (lx + rx)/2) set(i, val, 2 * x + 1, lx, (lx + rx)/2);
        else set(i, val, 2 * x + 2, (lx + rx)/2, rx);

        v[x] = v[2 * x + 1] + v[2 * x + 2];
    }

    void set(ll i, ll val) {
        set(i, val, 0, 0, size);
    }

    ll sum(ll l, ll r, ll x, ll lx, ll rx) {
        if(lx >= r || rx <= l) return 0;
        if(l <= lx && rx <= r) return v[x];

        return sum(l, r, 2 * x + 1, lx, (lx + rx)/2) + sum(l, r, 2 * x + 2, (lx + rx)/2, rx);
    }

    ll sum(ll l, ll r) {
        return sum(l, r, 0, 0, size);
    }

    ll getOne(ll x, ll lx, ll rx) {
        if(rx - lx == 1) return lx;
        if(v[2 * x + 2] > 0) return getOne(2 * x + 2, (lx + rx)/2, rx);
        return getOne(2 * x + 1, lx, (lx + rx)/2);
    }

    ll getOne() {
        return getOne(0, 0, size);
    }
};

segTree st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    st.init(n + 1);
    ll ans = 0;
    for(ll i = 1; i <= n; ++i) cin >> p[i];

    for(ll i = 1; i <= n; ++i) {
        ll k = st.sum(p[i] + 1, n + 1);
        //cout << k << ' ';
        if(k == 1) {
            //cout << st.getOne() << ' ';
            sum[st.getOne()]++;
        }
        if(k == 0) {
            ans++;
            a[p[i]]++;
        }
        st.set(p[i], 1);
    }

    ll res = 0, cur = 1;
    for(ll i = 1; i <= n; ++i) {
        //cout << sum[i] << ' ';
        if(ans - a[i] + sum[i] > res) {
            res = ans - a[i] + sum[i];
            cur = i;
        }
    }

    cout << cur << '\n';
    return 0;
}