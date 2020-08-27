#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a, b;
vector<pair<ll, ll>> v;
vector<ll> adj[200007];
bool visited[200007];

ll dfs(ll x) {
    ll minX = INT_MAX, maxX = 0, minY = INT_MAX, maxY = 0;

    stack<ll> s;
    s.push(x);

    while(!s.empty()) {
        ll t = s.top();
        s.pop();

        visited[t] = 1;

        minX = min(minX, v[t].first);
        maxX = max(maxX, v[t].first);
        minY = min(minY, v[t].second);
        maxY = max(maxY, v[t].second);

        for(ll i = 0; i < adj[t].size(); ++i) {
            if(!visited[adj[t][i]]) {
                s.push(adj[t][i]);
            }
        }
    }

    return 2 * (abs(maxY - minY) + abs(maxX - minX));
}

int main() {
    scanf("%lld %lld", &n, &m);
    v.push_back(make_pair(0, 0));
    for(ll i = 0; i < n; ++i) {
        scanf("%lld %lld", &a, &b);
        v.push_back(make_pair(a, b));
    }
    for(ll i = 0; i < m; ++i) {
        scanf("%lld %lld", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ll ans = 0;
    for(ll i = 1; i <= n; ++i) {
        if(!visited[i]) ans = min(dfs(i), ans);
    }

    printf("%lld\n", ans);

    return 0;
}