#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, l[1000007], r[1000007];
vector<ll> a;

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
        if(rx <= l || lx >= r) return 0;
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
    freopen("bphoto.in", "r", stdin);
    freopen("bphoto.out", "w", stdout);
    
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        a.push_back(x);
    }

    st.init(1000000);

    vector<ll> b(a);
    sort(b.begin(), b.end());
    for(ll i = 0; i < (ll)a.size(); ++i) {
        ll k = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        a[i] = k;
    }

    for(ll i = 0; i < (ll)a.size(); ++i) {
        l[i] = st.sum(a[i] + 1, 1000001);
        st.add(a[i], 1);
    }

    st.init(1000000);
    for(ll i = (ll)a.size() - 1; i >= 0; --i) {
        r[i] = st.sum(a[i] + 1, 1000001);
        st.add(a[i], 1);
    }

    ll ans = 0;
    for(ll i = 0; i < (ll)a.size(); ++i) {
        if(l[i] * 2 < r[i] || r[i] * 2 < l[i]) ans++;
    }

    cout << ans << '\n';
}