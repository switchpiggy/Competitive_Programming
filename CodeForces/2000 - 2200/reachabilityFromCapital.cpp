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
ll n, m, s, cnt[5007];
bool g[5007], vis[5007];
vector<ll> adj[5007];

void dfs(ll x) {
    if(!g[x]) {
        cnt[x] = 1;
    }

    vis[x] = 1;
    for(ll i : adj[x]) {
        if(!vis[i]) {
            dfs(i);
            cnt[x] += cnt[i];
        }
    }
}

void dfs2(ll x) {
    g[x] = 1;
    vis[x] = 1;

    for(ll i : adj[x]) {
        if(!vis[i]) {
            dfs2(i);
        }
    }
}

bool comp(ll x, ll y) {
    return cnt[x] > cnt[y];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> s;
    for(ll i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    benq<ll> ben;
    ben.push(s);

    while(!ben.empty()) {
        ll f = ben.front();
        ben.pop();

        g[f] = 1;
        for(ll i : adj[f]) {
            if(!g[i]) {
                g[i] = 1;
                ben.push(i);
            }
        }
    }

    vector<ll> v;
    for(ll i = 1; i <= n; ++i) {
        if(g[i]) continue;
        //cout << i << ' ';
        v.push_back(i);
        m0(vis);
        dfs(i);
    }

    ll ans = 0;
    sort(all(v), comp);
    for(ll i = 0; i < sz(v); ++i) {
        if(g[v[i]]) continue;
        m0(vis);
        dfs2(v[i]);
        //cout << v[i] << ' ';
        ans++;
    }

    //cout << cnt[5] << '\n';

    cout << ans << '\n';
    return 0;
}