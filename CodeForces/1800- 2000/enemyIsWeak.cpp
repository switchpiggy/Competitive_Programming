#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[1000007];

struct segTree {
    ll size;
    vector<ll> v;
    void init(ll x) {
        size = 1;
        while(size < x) size *= 2;
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
        return;
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

segTree p;
segTree cnt;

ll h[1000007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        h[i] = a[i];
    }

    sort(h, h + n);

    for(ll i = 0; i < n; ++i) {
        a[i] = lower_bound(h, h + n, a[i]) - h;
    }
    
    p.init(1000001);
    cnt.init(1000001);

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        ll k = p.sum(a[i] + 1, 1000001);
        p.add(a[i], 1);
        ans += cnt.sum(a[i] + 1, 1000001);
        cnt.add(a[i], k);
    }

    cout << ans << '\n';
    return 0;
}