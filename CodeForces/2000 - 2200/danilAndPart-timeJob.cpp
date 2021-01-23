#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define flout cout << fixed << setprecision(12)
ll n, p[200007], sz[200007], pos[200007];
vector<ll> dfst;
vector<ll> adj[200007];

struct node {
    ll val, op;
    node(ll x, ll y) {
        val = x;
        op = y;
    }
};

void dfs(ll x) {
    sz[x] = 1;
    dfst.push_back(x);
    pos[x] = sz(dfst) - 1;
    for(ll i : adj[x]) {
        if(i == p[x]) continue;
        dfs(i);
        sz[x] += sz[i];
    }
}

struct segTree {
    ll size;
    vector<node> v;

    void init(ll x) {
        size = 1;
        while(size <= x) size *= 2;
        v.assign(size * 2, node(0, 0));
    }

    void range_set(ll l, ll r, ll x, ll lx, ll rx) {
        if(l <= lx && rx <= r) {
            cout << lx << ' ' << rx << '\n';
            v[x].val = rx - lx - v[x].val;
            v[x].op++;
            return;
        }
        if(r <= lx || rx <= l) return;

        range_set(l, r, 2 * x + 1, lx, (lx + rx)/2);
        range_set(l, r, 2 * x + 2, (lx + rx)/2, rx);
        v[x].val = v[2 * x + 1].val + v[2 * x + 2].val;
        if(v[x].op%2 == 1) v[x].val = rx - lx - v[x].val;
    }

    void range_set(ll l, ll r) {
        range_set(l, r, 0, 0, size);
    }

    ll range_sum(ll l, ll r, ll x, ll lx, ll rx) {
        if(l <= lx && rx <= r) {
            cout << lx << ' ' << rx << ' ' << v[x].val << '\n';
            return v[x].val;
        }
        if(r <= lx || rx <= l) return -1;
        ll recl = range_sum(l, r, 2 * x + 1, lx, (lx + rx)/2);
        ll recr = range_sum(l, r, 2 * x + 2, (lx + rx)/2, rx);
        if(v[x].op%2 == 1) {
            if(recl != -1) recl = (lx + rx)/2 - lx - recl;
            if(recr != -1) recr = rx - (lx + rx)/2 - recr;
        }

        cout << lx << ' ' << rx << ' ' << v[x].op << ' ' << (recl != -1 ? recl : 0) + (recr != -1 ? recr : 0) << " op\n";
        return (recl != -1 ? recl : 0) + (recr != -1 ? recr : 0);
    }

    ll range_sum(ll l, ll r) {
        return range_sum(l, r, 0, 0, size);
    }
};

segTree st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    st.init(n);
    for(ll i = 2; i <= n; ++i) {
        cin >> p[i];
        adj[p[i]].push_back(i);
        adj[i].push_back(p[i]);
    }

    dfs(1);

    for(ll i = 1; i <= n; ++i) {
        ll a;
        cin >> a;
        if(a) st.range_set(pos[i], pos[i] + 1);
    }

    //cout << st.range_sum(0, n) << '\n';

    //for(ll i = 1; i <= n; ++i) cout << st.range_sum(pos[i], pos[i] + 1) << ' ';
    //cout << st.range_sum(3, 7) << '\n';

    ll q;
    cin >> q;
    while(q--) {
        string arg;
        ll vx;
        cin >> arg;
        if(arg[0] == 'g') {
            cin >> vx;
            cout << pos[vx] << ' ' << sz[vx] << '\n';
            //cout << pos[vx] << '\n';
            cout << st.range_sum(pos[vx], pos[vx] + sz[vx]) << '\n';
            //for(ll i = 1; i <= n; ++i) cout << st.range_sum(pos[i], pos[i] + 1) << ' ';
            //cout << '\n';
        } else {
            cin >> vx;
            st.range_set(pos[vx], pos[vx] + sz[vx]);
        }
    }   

    return 0; 
}