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
#define MAXN 100007
ll par[MAXN], sz[MAXN], best[MAXN], n, m, a, b, d[MAXN], lift[MAXN][20];
bool v[MAXN];
vector<ll> adj[MAXN];

void sz_init(ll x, ll p = -1) {
    if(v[x]) {
        sz[x] = 0;
        return;
    }

    sz[x] = 1;
    for(ll i : adj[x]) {
        if(i == p) continue;
        sz_init(i, x);
        sz[x] += sz[i];
    }

    return;
}

void lca_init(ll x, ll p = 0) {
    lift[x][0] = p;
    for(ll i = 1; i < 20; ++i) {
        lift[x][i] = lift[lift[x][i - 1]][i - 1];
    }

    for(ll i : adj[x]) {
        if(i == p) continue;
        d[i] = d[x] + 1;
        lca_init(i, x);
    }
}

ll find_centroid(ll x, ll p, ll tot) {
    for(ll i : adj[x]) {
        if(i != p && !v[i] && sz[i] > tot/2) {
            return find_centroid(i, x, tot);
        }
    }

    return x;
}

void cd_init(ll x, ll p = -1) {
    sz_init(x);
    
    ll cent = find_centroid(x, -1, sz[x]);
    v[cent] = 1;
    par[cent] = p;

    for(ll i : adj[cent]) {
        if(!v[i]) {
            cd_init(i, cent);
        }
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

    return lift[x][0];
}

ll dist(ll x, ll y) {
    ll z = lca(x, y);
    return d[x] + d[y] - 2 * d[z];
}

ll query(ll v) {
    ll res = best[v];
    ll cur = v;
    while(par[cur] != -1) {
        cur = par[cur];
        res = min(res, best[cur] + dist(cur, v));
    }

    return res;
}

void update(ll v) {
    best[v] = 0;
    ll cur = v;
    while(par[cur] != -1) {
        cur = par[cur];
        // cout << "Dist: " << v << ' ' << cur << ' ' << dist(v, cur) << '\n';
        best[cur] = min(best[cur], dist(v, cur));
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    inf(best);
    cin >> n >> m;
    for(ll i = 0; i < n - 1; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // d[1] = 1;
    lca_init(1);
    cd_init(1);
    // for(ll i = 1; i <= n; ++i) cout << par[i] << ' ';
    // cout << '\n';
    update(1);
    while(m--) {
        cin >> a >> b;
        if(a == 2) {
            // for(ll i = 1; i <= n; ++i) cout << best[i] << ' ';
            // cout << '\n';
            cout << query(b) << '\n';
        } else update(b);
    }

    return 0;
}