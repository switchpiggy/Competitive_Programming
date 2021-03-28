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
ll n, m, a, b;
bool vis[100007];
vector<ll> adj[100007];

void dfs(ll x) {
    vis[x] = 1;
    for(ll i : adj[x]) {
        if(vis[i]) continue;
        dfs(i);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<ll> res;
    for(ll i = 1; i <= n; ++i) {
        if(!vis[i]) {
            dfs(i);
            res.push_back(i);
        }
    }

    cout << sz(res) - 1 << '\n';
    for(ll i = 0; i < sz(res) - 1; ++i) cout << res[i] << ' ' << res[i + 1] << '\n';
    return 0;
}