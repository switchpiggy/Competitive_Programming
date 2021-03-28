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
ll n, m, q, a, b, p[300007], d[300007], r[300007], dist[300007];
vector<ll> adj[300007];
bool vis[300007];

ll get(ll x) {return p[x] = (p[x] == x ? x : get(p[x]));}

bool uni(ll x, ll y, bool ok = 0) {
    x = get(x);
    y = get(y);
    if(x == y) return 0;

    if(r[x] == r[y]) r[x]++;
    if(r[x] > r[y]) swap(x, y);
    p[x] = y;
    if(ok) d[y] = max({d[x], d[y], (d[x] + 1)/2 + (d[y] + 1)/2 + 1});
    return 1;
}

ll dfs(ll x, ll par = -1) {
    vis[x] = 1;
    dist[x] = 0;
    ll maxn = x;
    for(ll i : adj[x]) {
        if(i == par) continue;
        ll q = dfs(i, x);
        if(dist[i] + 1 > dist[x]) {
            dist[x] = dist[i] + 1;
            maxn = q;
        }
    }

    return maxn;
}   

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q;

    iota(p, p + n + 1, 0);
    for(ll i = 0; i < m; ++i) {
        // for(ll i = 1; i <= n; ++i) cout << d[get(i)] << ' ';
        // cout << '\n';
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        uni(a, b);
    }

    for(ll i = 1; i <= n; ++i) {
        // cout << get(i) << ' ' << vis[get(i)] << '\n';
        if(!vis[get(i)]) {
            ll fst = dfs(get(i));
            ll nxt = dfs(fst);
            // cout << fst << ' ' << nxt << '\n';
            d[get(i)] = dist[nxt] + dist[fst];
        }
    }

    // cout << '\n';

    while(q--) {
        // for(ll i = 1; i <= n; ++i) cout << d[get(i)] << ' ';
        // cout << '\n';
        ll t, x, y;
        cin >> t >> x;
        if(t == 1) {
            // for(ll i = 1; i <= n; ++i) cout << d[get(x)] << ' ';
            cout << d[get(x)] << '\n';
        } else {
            cin >> y;
            uni(x, y, 1);
        }
    }

    return 0;
}