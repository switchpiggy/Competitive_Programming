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
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define PI 3.14159265358979323846264338
#define flout cout << fixed << setprecision(12)

struct node {
    ll op, val;
    node() {
        op = 0;
        val = 0;
    }
};

struct segTree {
    ll size;
    vector<node> v;

    void init(ll x) {
        size = 1;
        while(size <= x) size *= 2;
        v.assign(size * 4 + 7, node());
    }

    void build(vector<ll> &a, ll x, ll lx, ll rx) {
        v[x].op = 0;
        if(rx - lx == 1) {
            if(lx < sz(a)) v[x].val = a[lx];
            return;
        }

        build(a, 2 * x + 1, lx, (lx + rx)/2);
        build(a, 2 * x + 2, (lx + rx)/2, rx);

        pull(x, lx, rx);
    }

    void build(vector<ll> &a) {
        v.clear();
        size = 1;
        while(size <= sz(a)) size *= 2;
        v.assign(size * 4 + 7, node());

        build(a, 0, 0, size);
    }

    void push(ll x, ll lx, ll rx) {
        if(!v[x].op) return;
        
        v[2 * x + 1].op = 1 - v[2 * x + 1].op;
        v[2 * x + 1].val = (lx + rx)/2 - lx - v[2 * x + 1].val;
        v[2 * x + 2].op = 1 - v[2 * x + 2].op;
        v[2 * x + 2].val = rx - (lx + rx)/2 - v[2 * x + 2].val;
        v[x].op = 0;
        

        v[x].op = 0;
        return;
    }

    void pull(ll x, ll lx, ll rx) {
        if(rx - lx == 1) {
            return;
        }
        v[x].val = (v[2 * x + 1].val + v[2 * x + 2].val);
    }

    void range_xor(ll l, ll r, ll x, ll lx, ll rx) {
        //if(l == 2 && r == 3) cout << lx << ' ' << rx << '\n';
        //push(x, lx, rx);
        if(lx >= r || rx <= l) return;
        //if(l == 3 && r == 4) cout << lx << ' ' << rx << '\n';
        if(l <= lx && rx <= r) {
            //if(l == 3 && r == 4) cout << lx << ' ' << rx << ' ' << v[x].val << '\n';
            v[x].op = 1 - v[x].op;
            v[x].val = (rx - lx - v[x].val);
            //if(l == 3 && r == 4) cout << lx << ' ' << rx << ' ' << v[x].val << '\n';
            return;
        }

        push(x, lx, rx);

        range_xor(l, r, 2 * x + 1, lx, (lx + rx)/2);
        range_xor(l, r, 2 * x + 2, (lx + rx)/2, rx);

        pull(x, lx, rx);
    }
    
    void range_xor(ll l, ll r) {
        range_xor(l, r, 0, 0, size);
    } 

    ll range_sum(ll l, ll r, ll x, ll lx, ll rx) {
        //push(x, lx, rx);
        if(lx >= r || rx <= l) return 0;
        if(l <= lx && rx <= r) {
            //if(l == 2 && r == 3) cout << lx << ' ' << rx << ' ' << v[x].val << '\n';
            return v[x].val;
        }

        push(x, lx, rx);
        ll res = range_sum(l, r, 2 * x + 1, lx, (lx + rx)/2) + range_sum(l, r, 2 * x + 2, (lx + rx)/2, rx);
        //pull(x, lx, rx);
        //if(l == 2 && r == 3) cout << lx << ' ' << rx << ' ' << res << '\n';
        return res;
    }

    ll range_sum(ll l, ll r) {
        return range_sum(l, r, 0, 0, size);
    }
};

ll n, m, a[100007];
segTree st[21];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for(ll i = 0; i < 20; ++i) {
        vector<ll> v;
        for(ll j = 0; j < n; ++j) if(a[j] & (1 << i)) v.push_back(1);
        else v.push_back(0);

        st[i].build(v);
    }

    //cout << '\n';
    //cout << st[0].range_sum(2, 3) << '\n';
    //for(ll i = 0; i < n; ++i) cout << st[0].range_sum(i, i + 1) << ' ';
    //cout << '\n';

    cin >> m;
    while(m--) {
        ll t, l, r;
        cin >> t;
        if(t == 2) {
            ll x;
            cin >> l >> r >> x;
            for(ll i = 0; i < 20; ++i) {
                if(x & (1 << i)) st[i].range_xor(l - 1, r);
            }
        } else {
            cin >> l >> r;
            ll ans = 0;
            for(ll i = 0; i < 20; ++i) {
                ans += st[i].range_sum(l - 1, r) * (1 << i);
            }

            cout << ans << '\n';
        }
    }

    return 0;
}