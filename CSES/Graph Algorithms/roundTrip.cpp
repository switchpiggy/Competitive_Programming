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
ll last = -1;
vector<ll> adj[100007];
vector<ll> v;

ll dfs(ll x, ll par) {
    if(vis[x]) {    
        last = x;
        v.push_back(x);
        return 1;
    }

    vis[x] = 1;
    for(ll i : adj[x]) {
        if(par == i) continue;
        ll cur = dfs(i, x);
        if(cur == 1) {
            v.push_back(x);
            if(last == x) return 2;
            return 1;
        } 
        
        if(cur == 2) return 2;
    }

    vis[x] = 1;
    return 0;
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

    // dfs(1, -1);
    for(ll i = 1; i <= n; ++i) {
        if(!vis[i]) {
            dfs(i, -1);
        }

        if(last != -1) break;
    }

    if(last == -1) cout << "IMPOSSIBLE\n";
    else {
        cout << sz(v) << '\n';
        for(ll i : v) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}