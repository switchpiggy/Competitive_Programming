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
#define flout cout << fixed << setprecision(12)
ll n, q, pos[200007], sz[200007];
vector<ll> adj[200007];
vector<ll> d;

void dfs(ll x, ll p) {
    sz[x] = 1;
    pos[x] = sz(d);
    d.push_back(x);
    for(ll i : adj[x]) {
        if(i == p) continue;
        dfs(i, x);
        sz[x] += sz[i];
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(ll i = 2; i <= n; ++i) {
        ll x;
        cin >> x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }

    dfs(1, -1);
    //for(ll i : d) cout << i << ' ';
    //cout << '\n';
    while(q--) {
        ll x, y;
        cin >> x >> y;
        if(pos[x] + y - 1 >= sz(d) || y > sz[x]) {
            cout << "-1\n";
        } else cout << d[pos[x] + y - 1] << '\n';
    }

    return 0;
}