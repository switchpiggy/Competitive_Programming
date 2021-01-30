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

struct node {
    ll val = 0, op = -1;
    node(ll x, ll y) {
        op = x;
        val = y;
    }

    node() {
        val = 0;
        op = -1;
    }
};

struct segTree {
    ll size;
    vector<node> v;

    void init(ll x) {
        size = 1;
        while(size <= x) size *= 2;
        v.clear();
        v.assign(size * 2, node(-1, 0));
    }

    void build(vector<ll> &a, ll x, ll lx, ll rx) {
        v[x].op = -1, v[x].val = 0;
        if(rx - lx == 1) {
            v[x].val = a[lx];
            return;
        }

        build(a, 2 * x + 1, lx, (lx + rx)/2);
        build(a, 2 * x + 2, (lx + rx)/2, rx);

        v[x].val = v[2 * x + 1].val + v[2 * x + 2].val;
    }

    void build(vector<ll> &a) {
        v.clear();
        size = 1;
        while(size <= sz(a)) size *= 2;
        v.assign(size * 4 + 10, node(-1, 0));
        build(a, 0, 0, size);
    }

    void propagate(ll x, ll lx, ll rx) {
        if(v[x].op == -1) return;
        if(rx - lx > 1) {
            v[2 * x + 1].op = v[x].op;
            v[2 * x + 2].op = v[x].op;
        }
        v[x].val = v[x].op * (rx - lx);
        v[x].op = -1;
        return;
    }

    void range_assign(ll y, ll l, ll r, ll x, ll lx, ll rx) {
        propagate(x, lx, rx);
        if(rx <= l || lx >= r) return;
        if(l <= lx && rx <= r) {
            v[x].op = y;
            propagate(x, lx, rx);
            return;
        }

        range_assign(y, l, r, 2 * x + 1, lx, (lx + rx)/2);
        range_assign(y, l, r, 2 * x + 2, (lx + rx)/2, rx);
        v[x].val = v[2 * x + 1].val + v[2 * x + 2].val;
    }

    void range_assign(ll val, ll l, ll r) {
        range_assign(val, l, r, 0, 0, size);
    }

    ll range_sum(ll l, ll r, ll x, ll lx, ll rx) {
        propagate(x, lx, rx);
        if(rx <= l || lx >= r) return 0;
        if(l <= lx && rx <= r) {
            return v[x].val;
        }
        
        //if(one) return rx - lx;
        return range_sum(l, r, 2 * x + 1, lx, (lx + rx)/2) + range_sum(l, r, 2 * x + 2, (lx + rx)/2, rx);
    }

    ll range_sum(ll l, ll r) {
        return range_sum(l, r, 0, 0, size);
    }
};

segTree st;
ll t, n, q;
string s, f;
vector<pair<ll, ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        v.clear();
        //st.init(n + 1);
        cin >> n >> q >> s >> f;
        vector<ll> a;
        for(ll i = 0; i < n; ++i) {
            a.push_back(f[i] - '0');
        }

        st.build(a);

        //cout << st.range_sum(0, n) << '\n';

        for(ll i = 0; i < q; ++i) {
            ll l, r;
            cin >> l >> r;
            v.push_back({l - 1, r - 1});
        }

        //cout << st.range_sum(4, 5) << '\n';
        
        bool ok = 1;
        for(ll i = q - 1; i >= 0; --i) {
            ll sum = st.range_sum(v[i].first, v[i].second + 1);
            if((v[i].second - v[i].first + 1)%2 == 0 && (v[i].second - v[i].first + 1)/2 == sum) {
                ok = 0;
                break;
            }
            if(sum > (v[i].second - v[i].first + 1)/2) st.range_assign(1, v[i].first, v[i].second + 1);
            else st.range_assign(0, v[i].first, v[i].second + 1);
        }
        
        string res;
        for(ll i = 0; i < n; ++i) {
            if(st.range_sum(i, i + 1)) res += '1';
            else res += '0';
        }

        if(res != s) ok = 0;
        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}