#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define m1(x) memset(x, 1, sizeof(x))
#define m0(x) memset(x, 0, sizeof(x))
#define inf(x) memset(x, 0x3f, sizeof(x))
#define flout cout << fixed << setprecision(12)

struct segTree {
    ll size;
    vector<ll> v;

    void init(ll x) {
        size = 1;
        while(size <= x) size *= 2;
        v.assign(size * 2, 0);
    }

    void set(ll p, ll val, ll x, ll lx, ll rx) {
        if(rx - lx == 1) {
            v[x] = val;
            return;
        }

        if(p < (lx + rx)/2) set(p, val, 2 * x + 1, lx, (lx + rx)/2);
        else set(p, val, 2 * x + 2, (lx + rx)/2, rx);

        v[x] = v[2 * x + 1] + v[2 * x + 2];
    }

    void set(ll p, ll val) {
        set(p, val, 0, 0, size);
    }

    ll range_sum(ll l, ll r, ll x, ll lx, ll rx) {
        if(l <= lx && rx <= r) return v[x];
        if(r <= lx || rx <= l) return 0;
        return range_sum(l, r, 2 * x + 1, lx, (lx + rx)/2) + range_sum(l, r, 2 * x + 2, (lx + rx)/2, rx);
    }

    ll range_sum(ll l, ll r) {
        return range_sum(l, r, 0, 0, size);
    }
};

ll n, q, r[100007], c[100007];
segTree sr, sc;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    sr.init(n + 1);
    sc.init(n + 1);
    for(ll i = 0; i < n; ++i) {
        cin >> r[i];
        sr.set(i, r[i]%2);
    }

    for(ll i = 0; i < n; ++i) {
        cin >> c[i];
        sc.set(i, c[i]%2);
    }

    while(q--) {
        ll x, y, a, b;
        cin >> x >> y >> a >> b;
        if(x > a) swap(x, a);
        if(y > b) swap(y, b);
        x--;
        y--;
        ll res = sr.range_sum(x, a), res1 = sc.range_sum(y, b);
        if(res == abs(a - x) && res1 == abs(b - y)) cout << "YES\n";
        else if(res + res1 == 0) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}