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
ll n, ans[200007];

struct node {
    ll val, op;
    node() {
        val = LLONG_MAX;
        op = 0;
    }

    node(ll x, ll y) {
        val = x;
        op = y;
    }
};

struct segTree {
    ll size;
    vector<node> v;

    void build(vector<ll> &a, ll x, ll lx, ll rx) {
        v[x].op = 0;
        if(rx - lx == 1) {
            if(sz(a) > lx) v[x].val = a[lx];
            return;
        }

        build(a, 2 * x + 1, lx, (lx + rx)/2);
        build(a, 2 * x + 2, (lx + rx)/2, rx);
        
        v[x].val = LLONG_MAX;
        update(x);
    }

    void build(vector<ll> &a) {
        size = 1;
        while(size <= sz(a)) size *= 2;
        v.assign(size * 4 + 10, node(LLONG_MAX, 0));
        build(a, 0, 0, size);
    }

    void apply_op(node &x, ll op) {
        x.op += op;
        x.val -= op;
    }

    void prop(ll x) {
        if(v[x].op) {
            apply_op(v[2 * x + 1], v[x].op);
            apply_op(v[2 * x + 2], v[x].op);
            v[x].op = 0;
        }
    }
    
    void update(ll x) {
        v[x].val = min(v[2 * x + 1].val,  v[2 * x + 2].val);
    }
    void range_subtract(ll val, ll l, ll r, ll x, ll lx, ll rx) {
        if(lx >= r || rx <= l) return;
        if(l <= lx && rx <= r) {
            apply_op(v[x], val);
            return;
        }
        
        prop(x);
        range_subtract(val, l, r, 2 * x + 1, lx, (lx + rx)/2);
        range_subtract(val, l, r, 2 * x + 2, (lx + rx)/2, rx);
        update(x);   
    }

    void range_subtract(ll val, ll l, ll r) {
        range_subtract(val, l, r, 0, 0, size);
    }

    ll last_zero(ll x, ll lx, ll rx) {
        //cout << lx << ' ' << rx << ' ' << v[2 * x + 2].val << ' ' << v[x].op << '\n';
        if(rx - lx == 1) return lx;
        prop(x);
        ll res = -1;
        if(v[2 * x + 2].val == 0) res = last_zero(2 * x + 2, (lx + rx)/2, rx);
        else res = last_zero(2 * x + 1, lx, (lx + rx)/2);

        update(x);

        return res;
    }

    ll last_zero() {
        return last_zero(0, 0, size);
    }
};

segTree st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<ll> s;
    for(ll i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        s.push_back(a);
    }

    st.build(s);

    for(ll i = 1; i <= n; ++i) {
        ll k = st.last_zero();
        //cout << k << ' ';
        ans[k] = i;
        st.range_subtract(i, k + 1, n);
        st.range_subtract(-100000000000000000, k, k + 1);
    }

    for(ll i = 0; i < n; ++i) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}