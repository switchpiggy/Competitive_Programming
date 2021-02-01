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
#define INF 0x3f3f3f3f3f3f3f3f
#define PI 3.141592653589793238
#define MOD 1000000007 
#define flout cout << fixed << setprecision(12)
ll n, a[200007], b[200007], c[200007], l[200007], r[200007], ans;
vector<ll> adj[200007];

void dfs(ll x, ll p) {
    if(b[x] != c[x]) {
        if(b[x]) l[x]++;
        else r[x]++;
    }

    for(ll i : adj[x]) {
        if(i == p) continue;
        a[i] = min(a[i], a[x]);
        dfs(i, x);
        l[x] += l[i];
        r[x] += r[i];
    }

    if(l[x] || r[x]) {
        ll cur = min(l[x], r[x]);
        l[x] -= cur;
        r[x] -= cur;
        ans += 2 * cur * a[x];
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }

    for(ll i = 0; i < n - 1; ++i) {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, -1);

    if(r[1] || l[1]) ans = -1;
    cout << ans << '\n';
    return 0;
}