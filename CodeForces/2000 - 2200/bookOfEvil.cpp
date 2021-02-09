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
#define mn(x) memset(x, -1, sizeof(x))
#define inf(x) memset(x, 0x3f, sizeof(x))
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define PI 3.14159265358979323846264338
#define flout cout << fixed << setprecision(12)
ll n, m, d, dx[100007], maxd[100007], c[100007];
bool p[100007];
vector<ll> adj[100007];

void dfs1(ll x, ll par) {
    if(p[x]) maxd[x] = 0;

    for(ll i : adj[x]) {
        if(i == par) continue;
        dx[i] = dx[x] + 1;
        dfs1(i, x);
        maxd[x] = max(maxd[x], maxd[i] + 1);
    }

    return;
}

void dfs2(ll x, ll par) {
    ll max1 = -INF, max2 = -INF;
    for(ll i : adj[x]) {
        if(i == par) continue;
        if(maxd[i] >= max1) {
            max2 = max1;
            max1 = maxd[i];
        } else if(maxd[i] >= max2) {
            max2 = maxd[i];
        }
    }

    //sort(all(v));

    for(ll i : adj[x]) {
        if(i == par) continue;
        if(maxd[i] == max1) c[i] = max2 + 2;
        else c[i] = max1 + 2;

        if(p[x]) c[i] = max(c[i], 1ll);
        c[i] = max(c[i], c[x] + 1);
        dfs2(i, x);
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(ll i = 0; i <= 100000; ++i) maxd[i] = -INF;
    for(ll i = 0; i <= 100000; ++i) c[i] = -INF;
    cin >> n >> m >> d;
    for(ll i = 0; i < m; ++i) {
        ll a;
        cin >> a;
        p[a] = 1;
    }

    for(ll i = 0; i < n - 1; ++i) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    c[1] = -INF;
    dfs1(1, -1);
    dfs2(1, -1);

    //for(ll i = 1; i <= n; ++i) cout << c[i] << ' ';
    //cout << '\n';
    //for(ll i = 1; i <= n; ++i) cout << maxd[i] << ' ';
    //cout << '\n';

    ll ans = 0;
    for(ll i = 1; i <= n; ++i) if(c[i] <= d && maxd[i] <= d) ans++;
    cout << ans << '\n';
    return 0;
}