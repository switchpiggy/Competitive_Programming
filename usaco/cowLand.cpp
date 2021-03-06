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
ll sz[1000007], lift[1000007][18], heavy[1000007], cpar[1000007], clabel[1000007], cur, d[1000007], rlabel[1000007], par[1000007];
vector<ll> adj[1000007];
ll n, q, e[1000007];

struct t {
    ll val, lazy;
    t(ll x, ll y) {
        val = x;
        lazy = y;
    }

    t() {
        val = 0;
        lazy = -1;
    }
};

template<class node> struct segtree {
    ll size;
    vector<node> v;

    void init(ll x) {
        size = 1;
        while(size <= x) size *= 2;
        v.assign(size * 2, node());
    }

    void build(vector<node> &a, ll x, ll lx, ll rx) {
        // cout << lx << ' ' << rx << '\n';
        if(rx - lx == 1) {
            if(lx < sz(a)) v[x] = a[lx];
            else v[x] = node(0, -1);
            return;
        }

        build(a, 2 * x + 1, lx, (lx + rx)/2);
        build(a, 2 * x + 2, (lx + rx)/2, rx);

        lazy_pull(x, lx, rx);
    }

    void build(vector<node> &a) {
        v.clear();
        size = 1;
        while(size <= sz(a)) size *= 2;
        v.assign(size * 2, node());

        build(a, 0, 0, size);
    }

    void apply_op(node &x, ll op) {
        if(op == -1) return;
        x.val = op;
        x.lazy = op;
    }

    node combine(node x, node y) {
        return node(x.val^y.val, -1);
    }

    ll combine_op(ll x, ll y) {
        return x^y;
    }

    void lazy_push(ll x, ll lx, ll rx) {
        if(rx - lx == 1) return;
        apply_op(v[2 * x + 1], v[x].lazy);
        apply_op(v[2 * x + 2], v[x].lazy);
        
        v[x].lazy = -1;
        return;
    }

    void lazy_pull(ll x, ll lx, ll rx) {
        if(rx - lx == 1) return;
        v[x].val = combine_op(v[2 * x + 1].val, v[2 * x + 2].val);
        return;
    }

    ll range_query(ll l, ll r, ll x, ll lx, ll rx) {
        if(lx >= r || rx <= l) return 0;
        if(l <= lx && rx <= r) return v[x].val;

        lazy_push(x, lx, rx);
        return combine_op(range_query(l, r, 2 * x + 1, lx, (lx + rx)/2), range_query(l, r, 2 * x + 2, (lx + rx)/2, rx));
    }

    ll range_query(ll l, ll r) {
        return range_query(l, r, 0, 0, size);
    }

    void range_update(ll l, ll r, ll op, ll x, ll lx, ll rx) {
        if(lx >= r || rx <= l) return;
        if(l <= lx && rx <= r) {
            apply_op(v[x], op);
            //lazy_push(x, lx, rx);
            return;
        }
        
        lazy_push(x, lx, rx);
        range_update(l, r, op, 2 * x + 1, lx, (lx + rx)/2);
        range_update(l, r, op, 2 * x + 2, (lx + rx)/2, rx);
        lazy_pull(x, lx, rx);

        return;
    }

    void range_update(ll l, ll r, ll op) {
        range_update(l, r, op, 0, 0, size);
    }
};

segtree<t> st;

void dfs(ll x, ll p) {
    heavy[x] = 0, sz[x] = 1;
    par[x] = p;
    lift[x][0] = par[x];
    for(ll i = 1; i < 18; ++i) lift[x][i] = lift[lift[x][i - 1]][i - 1];

    for(ll i : adj[x]) {
        if(i == p) continue;
        d[i] = d[x] + 1;
        dfs(i, x);
        sz[x] += sz[i];
        if(sz[i] > sz[heavy[x]]) heavy[x] = i;
    }
}

void dfs1(ll x, ll p) {
    if(heavy[x]) {
        cpar[heavy[x]] = cpar[x];
    }

    for(ll i : adj[x]) {
        if(i == p) continue;
        dfs1(i, x);
    }
}

void dfs2(ll x, ll p) {
    clabel[x] = ++cur;
    rlabel[cur] = x;
    for(ll i : adj[x]) {
        if(i == heavy[x]) {
            dfs2(i, x);
        }
    }

    for(ll i : adj[x]) {
        if(i == p || i == heavy[x]) continue;
        dfs2(i, x);
    }
}

ll lca(ll x, ll y) {
    if(d[x] < d[y]) swap(x, y);
    for(ll i = 17; i >= 0; --i) {
        if(d[lift[x][i]] >= d[y]) x = lift[x][i];
    }

    if(x == y) return x;

    for(ll i = 17; i >= 0; --i) {
        if(lift[x][i] != lift[y][i]) {
            x = lift[x][i];
            y = lift[y][i];
        }
    }

    //cout << x << ' ' << y << '\n';
    return par[x];
}

ll lca_query(ll u, ll v) {
    if(d[u] < d[v]) swap(u, v);
    ll res = 0;
    while(d[u] > d[v]) {
        ll ctop = cpar[u];
        if(d[ctop] <= d[v]) {
            ctop = rlabel[clabel[u] - (d[u] - d[v] - 1)];
        }

        res ^= st.range_query(clabel[ctop], clabel[u] + 1);
        u = par[ctop];
    }

    return res;
}

ll path_query(ll u, ll v) {
    ll x = lca(u, v);
    return lca_query(u, x) ^ lca_query(v, x) ^ st.range_query(clabel[x], clabel[x] + 1);
}

void lca_update(ll u, ll v, ll op) {
    if(d[u] < d[v]) swap(u, v);
    ll res = 0;
    while(d[u] > d[v]) {
        ll ctop = cpar[u];
        if(d[ctop] <= d[v]) {
            ctop = rlabel[clabel[u] - (d[u] - d[v] - 1)];
        }

        st.range_update(clabel[ctop], clabel[u] + 1, op);
        u = par[ctop];
    }

    //return res;
}

void path_update(ll u, ll v, ll op) {
    ll x = lca(u, v);
    lca_update(u, x, op);
    lca_update(v, x, op);
    st.range_update(clabel[x], clabel[x] + 1, op);
}

// segtree<v> st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("cowland.in", "r", stdin);
    freopen("cowland.out", "w", stdout);
    cin >> n >> q;
    for(ll i = 1; i <= n; ++i) cin >> e[i], cpar[i] = i;
    for(ll i = 0; i < n - 1; ++i) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    d[1] = 1;
    dfs(1, 0);
    dfs1(1, 0);
    dfs2(1, 0);
    //cout << lca(1, 5) << '\n';
    // for(ll i = 1; i <= n; ++i) cout << par[i] << ' ';
    // cout << '\n';
    // cout << lca(2, 2) << '\n';

    vector<t> a(n + 1);
    for(ll i = 1; i <= n; ++i) {
        a[clabel[i]].val = e[i];
    }

    st.build(a);
    // for(ll i = 1; i < n; ++i) cout << st.range_query(i, i + 2) << ' ';
    // cout << '\n';
    // cout << lca(2, 3) << '\n';
    // cout << lca(1, 4) << '\n';

    while(q--) {
        ll t, i, j;
        cin >> t >> i >> j;
        if(t == 1) {
            path_update(i, i, j);
        } else {
            cout << path_query(i, j) << '\n';
        }
    }

    return 0;
}