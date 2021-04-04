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
ll n, k, x, y, dist[1000007];
vector<ll> adj[1000007];
multiset<ll> st[1000007];

void dfs(ll x, ll p = -1) {
    if(sz(adj[x]) == 1) {
        st[x].insert(dist[x]);
        return;
    }

    ll maxn = -1;
    for(ll i : adj[x]) {
        if(i == p) continue;
        dist[i] = dist[x] + 1;
        dfs(i, x);
        if(maxn == -1 || sz(st[maxn]) < sz(st[i])) maxn = i;
    }

    swap(st[maxn], st[x]);

    for(ll i : adj[x]) {
        if(i == p || i == maxn) continue;
        for(auto j : st[i]) {
            ll cur = k + 2 * dist[x] - j;
            auto l = st[x].upper_bound(cur);
            if(l == st[x].begin()) {
                st[x].insert(j);
            } else {
                l--;
                st[x].insert(max(*l, j));
                st[x].erase(l);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(ll i = 0; i < n - 1; ++i) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(ll i = 1; i <= n; ++i) {
        if(sz(adj[i]) > 1) {
            dfs(i);
            cout << sz(st[i]) << '\n';
            break;
        }
    }

    return 0;
}