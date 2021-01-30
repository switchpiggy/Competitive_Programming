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
ll n, k, p[100007], cnt[100007], cycle[100007], csz[100007];
vector<pair<ll, ll>> adj[100007];
bool v[100007];
ll g = 1;

bool comp(pair<ll, ll> x, pair<ll, ll> y) {
    return x.second < y.second;
}

bool find_cycle(ll x, ll y, ll t) {
    v[x] = 1;
    if(adj[x].empty()) return 0;
    sort(all(adj[x]), comp);
    bool ok = 0;
    if(adj[x].back().second > t) ok = 1;

    for(pair<ll, ll> i : adj[x]) {
        if((ok && i.second <= t)) continue;
        if(i.first == y) {
            csz[g]++;
            return 1;
        }
        if(!v[i.first] && find_cycle(i.first, y, i.second)) {
            csz[g]++;
            return 1;
        }

        break;
    }

    return 0;
}   

void dfs(ll x) {
    v[x] = 1;
    p[x] = g;
    cnt[g]++;
    for(pair<ll, ll> i : adj[x]) {
        if(v[i.first]) continue;
        dfs(i.first);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(ll i = 0; i < k; ++i) {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back({y, i + 1});
        adj[y].push_back({x, i + 1});
    }

    for(ll i = 1; i <= n; ++i) {
        m0(v);
        if(sz(adj[i]) == 2 && find_cycle(i, i, -1)) {
            cycle[i] = g;
            g++;
        }
    }

    m0(v);
    g = 1;
    for(ll i = 1; i <= n; ++i) {
        if(cycle[i] || v[i]) continue;
        dfs(i);
        g++;
    }

    for(ll i = 1; i <= n; ++i) {
        if(cycle[i]) cout << csz[cycle[i]] << '\n';
        else cout << cnt[p[i]] << '\n';
    }

    return 0;
}