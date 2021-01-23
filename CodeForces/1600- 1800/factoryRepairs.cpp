#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define benq queue
#define pbenq priority_queue
#define all(x) (x.begin(), x.end())
ll n, k, a, b, q, x, y, p;

struct segTree {
    ll size;
    vector<ll> v;
    
    void init(ll x) {
        size = 1;
        while(size <= x) size *= 2;
        v.assign(size * 2, 0);
    }

    void add(ll val, ll pos, ll maxn, ll x, ll lx, ll rx) {
        if(rx - lx == 1) {
            v[x] += val;
            v[x] = min(v[x], maxn);
            return;
        }

        if(pos < (lx + rx)/2) add(val, pos, maxn, 2 * x + 1, lx, (lx + rx)/2);
        else add(val, pos, maxn, 2 * x + 2, (lx + rx)/2, rx);

        v[x] = v[2 * x + 1] + v[2 * x + 2];
    }

    void add(ll val, ll pos, ll maxn) {
        add(val, pos, maxn, 0, 0, size);
    }

    ll range_sum(ll l, ll r, ll x, ll lx, ll rx) {
        if(l <= lx && rx <= r) return v[x];
        if(lx >= r || rx <= l) return 0;
        return range_sum(l, r, 2 * x + 1, lx, (lx + rx)/2) + range_sum(l, r, 2 * x + 2, (lx + rx)/2, rx);
    }

    ll range_sum(ll l, ll r) {
        return range_sum(l, r, 0, 0, size);
    }
};

segTree before, after;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> a >> b >> q;
    before.init(n + 1);
    after.init(n + 1);

    for(ll i = 0; i < q; ++i) {
        ll t;
        cin >> t;
        if(t == 1) {
            cin >> x >> y;
            before.add(y, x, b);
            after.add(y, x, a);
        } else {
            cin >> p;
            cout << before.range_sum(1, p) + after.range_sum(min(n + 1, p + k), n + 1) << '\n';
        }
    }
}