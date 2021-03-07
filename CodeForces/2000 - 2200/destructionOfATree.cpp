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
ll n, sz[200007];
vector<ll> adj[200007];
vector<ll> v;

void dfs1(ll x, ll par) {
    sz[x] = 1;
    for(ll i : adj[x]) {
        if(i == par) continue;
        dfs1(i, x);
        sz[x] += sz[i];
    }

    return;
}

void dfs2(ll x, ll par) {
    for(ll i : adj[x]) {
        if(i == par) continue;
        if(sz[i]%2 == 0) dfs2(i, x);
    }

    v.push_back(x);

    for(ll i : adj[x]) {
        if(i == par) continue;
        if(sz[i]%2 == 1) dfs2(i, x);
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll r;
    for(ll i = 1; i <= n; ++i) {
        ll p;
        cin >> p;
        if(!p) r = i;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }

    if(n%2 == 0) {
        cout << "NO\n";
        return 0;
    }

    dfs1(r, 0);
    dfs2(r, 0);
    cout << "YES\n";
    for(ll i : v) cout << i << '\n';
    return 0;
}