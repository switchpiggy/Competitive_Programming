#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
bool visited[1007];
vector<ll> adj[1007];
vector<pair<ll, ll>> v;
vector<ll> t;
set<pair<ll, ll>> s;

void dfs(ll x, ll p) {
    //visited[x] = 1;
    for(ll i = 0; i < (ll)adj[x].size(); ++i) {
        if(adj[x][i] == p) continue;
        if(visited[adj[x][i]]) {
            if(s.find({x, adj[x][i]}) == s.end() && s.find({adj[x][i], x}) == s.end()) v.push_back({x, adj[x][i]});
            s.insert({x, adj[x][i]});
        } else {
            visited[adj[x][i]] = 1;
            dfs(adj[x][i], x);
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n - 1; ++i) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(ll i = 1; i <= n; ++i) {
        if(!visited[i]) {
            visited[i] = 1;
            dfs(i, -1);
            t.push_back(i);
        }
    }

    cout << (ll)t.size() - 1 << '\n';
    for(ll i = 0; i < (ll)t.size() - 1; ++i) {
        cout << v[i].first << ' ' << v[i].second << ' ' << t[i] << ' ' << t[i + 1] << '\n';
    }

    //for(ll i = 0; i < (ll)v.size(); ++i) cout << v[i].first << ' ' << v[i].second << '\n';

    return 0;
}