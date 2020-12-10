#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, l[100007], r[100007];

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
        if(lx >= r || rx <= l) return 0;
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
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    cin >> n;
    st.init(2 * n);
    for(ll i = 1; i <= 2 * n; ++i) {
        ll a;
        cin >> a;
        if(l[a]) r[a] = i;
        else l[a] = i;
    }

    vector<pair<pair<ll, ll>, ll>> v;
    for(ll i = 1; i <= n; ++i) {
        v.push_back({{l[i], 1}, i});
        v.push_back({{r[i], 0}, i});
    }

    sort(v.begin(), v.end());

    st.init(2 * n);
    ll ans = 0;
    for(ll i = 0; i < (ll)v.size(); ++i) {
        //cout << v[i].first.first << ' ' <<  v[i].first.second << ' ' << v[i].second << '\n';
        if(v[i].first.second == 1) {
            st.add(v[i].first.first, 1);
        } else {
            st.add(l[v[i].second], -1);
            //st.add(v[i].first.first, -1);
            ans += st.sum(l[v[i].second], v[i].first.first + 1);
        }
    }

    cout << ans << '\n';
    return 0;
}