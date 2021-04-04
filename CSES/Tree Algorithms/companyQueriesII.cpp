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
#define MAXN 200007
ll lift[MAXN][30], d[MAXN], n, q, a, b;
vector<ll> adj[MAXN];

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

ll lca(ll x, ll y) {
    if(d[x] < d[y]) swap(x, y);
    for(ll i = 19; i >= 0; --i) {
        if(d[lift[x][i]] >= d[y]) x = lift[x][i];
    }

    if(x == y) return x;

    for(ll i = 19; i >= 0; --i) {
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(ll i = 2; i <= n; ++i) {
        cin >> a;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }

    d[0] = -1;
    lca_init(1);

    while(q--) {
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }

    return 0;
}