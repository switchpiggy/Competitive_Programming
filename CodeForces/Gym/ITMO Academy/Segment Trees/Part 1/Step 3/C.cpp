#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[200007], last[200007], ans[200007];

struct segTree {
    ll size;
    vector<ll> v;

    void init(ll x) {
        size = 1;
        while(size <= x) size *= 2;
        v.assign(size * 2, 0);
    }

    void set(ll i, ll x, ll lx, ll rx) {
        if(rx - lx == 1) {
            v[x] = 1;
            return;
        }

        if(i < (lx + rx)/2) set(i, 2 * x + 1, lx, (lx + rx)/2);
        else set(i, 2 * x + 2, (lx + rx)/2, rx);

        v[x] = v[2 * x + 1] + v[2 * x + 2];
    }

    void set(ll i) {
        set(i, 0, 0, size);
    }

    ll sum(ll l, ll r, ll x, ll lx, ll rx) {
        if(r <= lx || rx <= l) return 0;
        if(l <= lx && rx <= r) {
            return v[x];
        }

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
    st.init(2 * n);
    for(ll i = 0; i < 2 * n; ++i) {
        cin >> a[i];
        last[i + 1] = -1;
    }

    for(ll i = 0; i < 2 * n; ++i) {
        if(last[a[i]] == -1) {
            last[a[i]] = i;
        } else {
            ans[a[i]] = st.sum(last[a[i]], i);
            st.set(last[a[i]]);
        }
    }

    for(ll i = 1; i <= n; ++i) cout << ans[i] << ' ';
    return 0;
}