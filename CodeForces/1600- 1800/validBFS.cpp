#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, z, y, a[200007], pos[200007];
vector<ll> adj[200007];
bool visited[200007];
vector<ll> res;

bool cmp(ll x, ll y) {
    return pos[x] < pos[y];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n - 1; ++i) {
        cin >> z >> y;
        adj[z].push_back(y);
        adj[y].push_back(z);
    }

    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    for(ll i = 1; i <= n; ++i) {
        sort(adj[i].begin(), adj[i].end(), cmp);
    }

    vector<ll> res;
    queue<ll> q;
    q.push(1);
    res.push_back(1);
    visited[1] = 1;

    while(!q.empty()) {
        ll t = q.front();
        q.pop();

        for(ll i = 0; i < (ll)adj[t].size(); ++i) {
            if(!visited[adj[t][i]]) {
                q.push(adj[t][i]);
                res.push_back(adj[t][i]);
                visited[adj[t][i]] = 1;
            }
        }
    }

    for(ll i = 0; i < n; ++i) {
        if(res[i] != a[i]) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    return 0;
}