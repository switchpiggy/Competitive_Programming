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
            v[x] += val;
            return;
        }

        if(i < (lx + rx)/2) set(i, val, 2 * x + 1, lx, (lx + rx)/2);
        else set(i, val, 2 * x + 2, (lx + rx)/2, rx);

        v[x] = v[2 * x + 1] + v[2 * x + 2];
    }

    void set(ll i, ll val) {
        set(i, val, 0, 0, size);
    }

    ll sum(ll x, ll lx, ll rx, ll l, ll r) {
        if(rx <= l || lx >= r) return 0;
        if(l <= lx && rx <= r) return v[x];
        return sum(2 * x + 1, lx, (lx + rx)/2, l, r) +  sum(2 * x + 2, (lx + rx)/2, rx, l, r);
    }

    ll sum(ll l, ll r) {
        return sum(0, 0, size, l, r);
    }
};

ll n, a[100007], res[100007];
vector<pair<ll, ll>> v;
segTree st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("haircut.in", "r", stdin);
    freopen("haircut.out", "w", stdout);
    cin >> n;
    st.init(n + 1);
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        v.push_back({a[i], st.sum(a[i] + 1, n + 1)});
        st.set(a[i], 1);
    }

    ll sum = 0;
    for(ll i = 0; i < n; ++i) sum += v[i].second;
    sort(v.begin(), v.end(), greater<pair<ll, ll>>());

    ll cur = 0;
    for(ll j = n - 1; j >= 0; --j) {
        while(cur < (ll)v.size() && v[cur].first >= j) {
            sum -= v[cur].second;
            cur++;
        }
        res[j] = sum;
    }

    for(ll i = 0; i < n; ++i) cout << res[i] << '\n';
    return 0;
}