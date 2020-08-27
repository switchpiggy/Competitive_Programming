#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, k, u, v;
bool visited[1007];
vector<ll> adj[1007];
ll gov[1007];
vector<ll> ans;

void dfs(ll x) {
    ll cnt = 0;

    stack<ll> s;
    s.push(x);

    while(!s.empty()) {
        ll t = s.top();
        s.pop();

        for(ll i = 0; i < adj[t].size(); ++i) {
            if(!visited[adj[t][i]]) {
                
                s.push(adj[t][i]);
                visited[adj[t][i]] = 1;
            }
        }

        ++cnt;
    }

    ans.push_back(cnt);

    
}

int main() {
    scanf("%lld %lld %lld", &n, &m, &k);
    for(ll i = 1; i <= k; ++i) scanf("%lld", &gov[i]);

    for(ll i = 1; i <= m; ++i) {
        scanf("%lld %lld", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(ll i = 1; i <= k; ++i) {
        visited[gov[i]] = 1;
        dfs(gov[i]);
    }

    ll res = 0;

    for(ll i = 1; i <= n; ++i) if(!visited[i]) ++res;
    
    sort(ans.begin(), ans.end());

    ans[ans.size() - 1] += res;

    res = 0;

    for(ll i = 0; i < ans.size(); ++i) {
        res += (ans[i] * (ans[i] - 1))/2;
    }

    res -= m;

    printf("%lld\n", res);

    return 0;
}