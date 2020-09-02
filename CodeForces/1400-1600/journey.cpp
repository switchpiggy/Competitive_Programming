#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, u, v;
vector<ll> adj[100007];

double dfs(ll v, ll p) {
    double sum = 0;
    for(ll i = 0; i < adj[v].size(); ++i) {
        if(adj[v][i] == p) continue;
        sum += dfs(adj[v][i], v) + 1.0;
    }

    if(sum == 0) return 0.0;

    return sum/((double)adj[v].size() - (double)(p != -1));
}

int main() {
    cin >> n;
    for(ll i = 0; i < n - 1; ++i) { 
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << fixed << setprecision(12) << dfs(1, -1) << endl;
    return 0;
}