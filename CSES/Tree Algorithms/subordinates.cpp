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

void dfs(ll x, ll par = -1) {
    sz[x] = 1;
    for(ll i : adj[x]) {
        if(par == i) continue;
        dfs(i, x);
        sz[x] += sz[i];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 2; i <= n; ++i) {
        ll x;
        cin >> x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }

    dfs(1);

    for(ll i = 1; i <= n; ++i) cout << sz[i] - 1 << ' ';
    cout << '\n';
    return 0;
}