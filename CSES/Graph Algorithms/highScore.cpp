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
#define mn(x) memset(x, -0x3f, sizeof(x));
#define inf(x) memset(x, 0x3f, sizeof(x))
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define PI 3.14159265358979323846264338
#define flout cout << fixed << setprecision(12)
ll n, m, a, b, x, dist[2507];
vector<pair<pair<ll, ll>, ll>> v;
vector<ll> adj[100007], adj2[100007];
bool bad[100007], vis[100007], r[100007];

bool dfs(ll x) {
    vis[x] = 1;
    if(bad[x] && r[x]) return 1;
    for(ll i : adj[x]) {
        if(vis[i]) continue;
        if(dfs(i)) return 1;
    }

    return 0;
}

void dfs2(ll x) {
    vis[x] = r[x] = 1;
    for(ll i : adj2[x]) {
        if(vis[i]) continue;
        dfs2(i);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    mn(dist);
    for(ll i = 0; i < m; ++i) {
        cin >> a >> b >> x;
        v.push_back({{a, b}, x});
        adj[b].push_back(a);
        adj2[a].push_back(b);
    }
    
    dist[1] = 0;
    for(ll i = 0; i < n - 1; ++i) {
        for(auto j : v) {
            if(dist[j.first.first] != -INF) dist[j.first.second] = max(dist[j.first.second], dist[j.first.first] + j.second);
        }
    }

    for(auto j : v) {
        if(dist[j.first.first] != -INF && dist[j.first.second] < dist[j.first.first] + j.second) {
            bad[j.first.first] = 1;
            dist[j.first.second] = dist[j.first.first] + j.second;
        }
    }

    dfs2(1);
    m0(vis);

    if(dfs(n)) cout << "-1\n";
    else cout << dist[n] << '\n';
    return 0;
}   