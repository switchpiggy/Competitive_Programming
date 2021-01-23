#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define flout cout << fixed << setprecision(12)
ll n, q, a, b, s, vi[200007], pos[200007], sz[200007], x;
vector<ll> t;
vector<ll> adj[200007];

void dfs(ll x, ll p) {
    //cout << p << ' ' << x << '\n';
    t.push_back(x);
    pos[x] = sz(t);

    for(ll i : adj[x]) {
        if(i == p || pos[i]) continue;
        dfs(i, x);    
    }
}

void find_sz(ll x, ll p) {
    sz[x] = 1;
    for(ll i : adj[x]) {
        if(i == p) continue;
        find_sz(i, x);
        sz[x] += sz[i];
    }
}

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

segTree st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    st.init(n + 1);
    for(ll i = 1; i <= n; ++i) {
        cin >> vi[i];
    }
    for(ll i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    /*for(ll i = 1; i <= n; ++i, cout << '\n') {
        for(ll j : adj[i]) cout << j << ' ';
    }*/

    dfs(1, -1);
    find_sz(1, -1);

    for(ll i = 1; i <= n; ++i) {
        //cout << sz[i] << ' ';
        st.set(pos[i], vi[i]);
    }

    //for(ll i : t) cout << i << " ";

    while(q--) {
        ll tq;
        cin >> tq;
        if(tq == 1) {
            cin >> s >> x;
            st.set(pos[s], x);
        } else {
            cin >> s;
            cout << st.range_sum(pos[s], pos[s] + sz[s]) << '\n';
        }
    }

    return 0;
}