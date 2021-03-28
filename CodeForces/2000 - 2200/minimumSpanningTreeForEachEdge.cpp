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
ll n, m, u, v, w, r[200007], p[200007], q[200007];
vector<pair<ll, ll>> adj[200007];
vector<pair<ll, pair<ll, ll>>> e;
set<pair<ll, ll>> mst;
map<pair<ll, ll>, ll> ind;
map<ll, ll> weight;
ll lift[200007][20], liftmax[200007][20], d[200007];

void lca_init(ll x, ll p = 0) {
    lift[x][0] = p, liftmax[x][0] = weight[x];
    for(ll i = 1; i < 20; ++i) {
        lift[x][i] = lift[lift[x][i - 1]][i - 1];
        // liftmax[x][i] = max(liftmax[x][i - 1], liftmax[lift[x][i - 1]][i - 1]);
    }

    for(ll i = 1; i < 20; ++i) {
        liftmax[x][i] = max(liftmax[x][i - 1], liftmax[lift[x][i - 1]][i - 1]);
    }

    for(auto i : adj[x]) {
        if(i.first == p) continue;
        d[i.first] = d[x] + 1;
        weight[i.first] = i.second;
        lca_init(i.first, x);
    }
}

pair<ll, ll> lca(ll x, ll y) {
    ll maxn = 0;
    if(d[x] < d[y]) swap(x, y);
    for(ll i = 19; i >= 0; --i) {
        if(d[lift[x][i]] >= d[y]) maxn = max(maxn, liftmax[x][i]), x = lift[x][i];
    }

    if(x == y) return {x, maxn};

    for(ll i = 19; i >= 0; --i) {
        if(lift[x][i] != lift[y][i]) {
            maxn = max({maxn, liftmax[x][i], liftmax[y][i]});
            x = lift[x][i];
            y = lift[y][i];
        }
    }

    maxn = max({maxn, weight[x], weight[y]});
    return {lift[x][0], maxn};
}

ll get(ll x) {return p[x] = (p[x] == x ? x : get(p[x]));}
bool uni(ll x, ll y) {
    x = get(x);
    y = get(y);
    if(x == y) return 0;

    if(r[x] == r[y]) r[x]++;
    if(r[x] > r[y]) swap(x, y);
    p[x] = y;

    return 1;
}

ll kruskal() {
    ll res = 0;
    sort(all(e));
    for(auto i : e) {
        if(uni(i.second.first, i.second.second)) {
            res += i.first;
            mst.insert(i.second);
            adj[i.second.second].push_back({i.second.first, i.first});
            adj[i.second.first].push_back({i.second.second, i.first});
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    iota(p, p + n + 1, 0);
    for(ll i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        e.push_back({w, {u, v}});
        ind[{u, v}] = i;
    }

    ll ans = kruskal();
    lca_init(1);
    for(auto i : e) {
        if(mst.find(i.second) != mst.end()) {
            q[ind[i.second]] = ans;
            continue;
        }

        ll cur = ans + i.first - lca(i.second.first, i.second.second).second;
        q[ind[i.second]] = cur;
    }

    for(ll i = 0; i < m; ++i) cout << q[i] << '\n';
    // cout << ans << '\n';
    return 0;
}