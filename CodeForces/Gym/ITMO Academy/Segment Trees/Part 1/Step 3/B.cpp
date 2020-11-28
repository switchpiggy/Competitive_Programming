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

        v[x] = v[2 * x + 1] + v[2 * x + 2];
    }

    void set(ll i, ll val) {
        set(i, val, 0, 0, size);
    }

    ll findOne(ll k, ll x, ll lx, ll rx, ll cur) {
        if(rx - lx == 1) {
            return lx;
        }

        if(k <= v[2 * x + 2] + cur) return findOne(k, 2 * x + 2, (lx + rx)/2, rx, cur);
        return findOne(k, 2 * x + 1, lx, (lx + rx)/2, cur + v[2 * x + 2]);
    }

    ll findOne(ll k) {
        return findOne(k, 0, 0, size, 0);
    }
};

segTree st;
ll n, a[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    st.init(n);
    for(ll i = 0; i < n; ++i) {
        st.set(i, 1);
    }
    //cout << st.size << '\n';

    vector<ll> ans;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    for(ll i = n - 1; i >= 0; --i) {
        ll cur = st.findOne(a[i] + 1);
        ans.push_back(cur + 1);
        st.set(cur, 0);
    }

    for(ll i = n - 1; i >= 0; --i) cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}