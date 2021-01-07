#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, x, y, diam[1007], dist[1007];
vector<ll> adj[1007];
vector<pair<ll, ll>> ans;
vector<ll> res;
bool vis[1007];

bool cmp(ll x, ll y) {
    return diam[x] > diam[y];
}

ll find_dist(ll x, ll par, ll cur) {
    vis[x] = 1;
    ll res = cur;
    for(ll i : adj[x]) {
        if(i == par) continue;
        res = max(res, find_dist(i, x, cur + 1));
    }

    return res;
}

void find_dist(ll x, ll par) {
    for(ll i : adj[x]) {
        if(i == par) continue;
        dist[i] = dist[x] + 1;
        find_dist(i, x);
    }
}

vector<ll> cur;
void dfs(ll x, ll par) {
    vis[x] = 1;
    cur.push_back(x);
    for(ll i : adj[x]) {
        if(i == par) continue;
        dfs(i, x);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < m; ++i) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(ll i = 1; i <= n; ++i) {
        if(!vis[i]) {
            cur.clear();
            dfs(i, -1);
            //memset(dist, 0, sizeof(dist));
            ll center = 1, minDist = LLONG_MAX;
            for(ll i : cur) {
                ll cc = find_dist(i, -1, 0);
                if(cc < minDist) {
                    center = i;
                    minDist = cc;
                }  
            }

            res.push_back(center);
            memset(dist, 0, sizeof(dist));
            find_dist(center, -1);
            ll c = 1;
            for(ll j = 1; j <= n; ++j) if(dist[j] > dist[c]) c = j;
            memset(dist, 0, sizeof(dist));
            find_dist(c, -1);
            for(ll j = 1; j <= n; ++j) diam[center] = max(diam[center], dist[j]);
        }
    }

    sort(res.begin(), res.end(), cmp);

    for(ll i = 1; i < (ll)res.size(); ++i) {
        ans.push_back({res[0], res[i]});
        adj[res[0]].push_back(res[i]);
        adj[res[i]].push_back(res[0]);
    }

    memset(dist, 0, sizeof(dist));
    find_dist(res[0], -1);
    ll c = 1;
    for(ll i = 1; i <= n; ++i) if(dist[i] > dist[c]) c = i;
    memset(dist, 0, sizeof(dist));
    find_dist(c, -1);
    ll a = 0;
    for(ll i = 1; i <= n; ++i) a = max(a, dist[i]);

    cout << a << '\n';
    for(pair<ll, ll> i : ans) cout << i.first << ' ' << i.second << '\n';
}