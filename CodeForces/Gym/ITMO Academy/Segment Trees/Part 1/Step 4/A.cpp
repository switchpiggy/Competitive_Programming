#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m;

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
            v[x] = ((i%2 == 0) ? val : (-1 * val));
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
        if(rx <= l || lx >= r) return 0;
        if(l <= lx && rx <= r) return v[x];
        return sum(l, r, 2 * x + 1, lx, (lx + rx)/2) + sum(l, r, 2 * x + 2, (lx + rx)/2, rx);
    }

    ll alternatingSum(ll l, ll r) {
        ll cur = sum(l, r, 0, 0, size);
        if(l%2 == 1) return -1 * cur;
        return cur;
    }
};

segTree st;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    st.init(n);
    for(ll i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        st.set(i, a);
    } 

    cin >> m;
    for(ll i = 0; i < m; ++i) {
        ll t;
        cin >> t;
        if(!t) {
            ll j, k;
            cin >> j >> k;
            j--;
            st.set(j, k);
        } else {
            ll l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << st.alternatingSum(l, r + 1) << '\n';
        }
    }

    return 0;
}