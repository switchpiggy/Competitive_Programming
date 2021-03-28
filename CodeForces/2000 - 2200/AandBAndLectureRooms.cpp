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
ll n, m, lift[100007][18], d[100007], sz[100007];
vector<ll> adj[100007];

void dfs(ll x, ll p = 0) {
    lift[x][0] = p;
    sz[x] = 1;
    for(ll i = 1; i < 18; ++i) lift[x][i] = lift[lift[x][i - 1]][i - 1];

    for(ll i : adj[x]) {
        if(i == p) continue;
        d[i] = d[x] + 1;
        dfs(i, x);
        sz[x] += sz[i];
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

ll get(ll x, ll k) {
    ll ans = x;
    for(ll i = 17; i >= 0; --i) {
        if((1 << i) <= k) {
            ans = lift[ans][i];
            k -= (1 << i);
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n - 1; ++i) {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1);

    // for(ll i = 1; i <= n; ++i) cout << d[i] << ' ';

    cin >> m;
    while(m--) {
        ll x, y;
        cin >> x >> y;

        if(x == y) {
            cout << n << '\n';
            continue;
        }
        
        ll cur = lca(x, y), res = 0;
        
        if((d[x] + d[y] - 2 * d[cur])%2 == 1) {
            cout << "0\n";
            continue;
        }

        if(d[x] - d[cur] == d[y] - d[cur]) {
            ll x1 = get(x, d[x] - d[cur] - 1), x2 = get(y, d[y] - d[cur] - 1);
            cout << n - sz[x1] - sz[x2] << '\n';
            continue;
        }

        if(d[x] > d[y]) swap(x, y);

        ll cur2 = get(y, (d[x] + d[y] - 2 * d[cur])/2), y2 = get(y, (d[x] + d[y] - 2 * d[cur])/2 - 1);
        cout << sz[cur2] - sz[y2] << '\n';
    }

    return 0;
}