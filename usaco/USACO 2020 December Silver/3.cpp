#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, sy[1007];
vector<ll> adj[1007];
vector<pair<pair<ll, ll>, ll>> vx, vy;
bool vs[1007];

bool cmp(pair<pair<ll, ll>, ll> x, pair<pair<ll, ll>, ll> y) {
    return x.first.second < y.first.second;
}

bool nkill(pair<ll, ll> x, pair<ll, ll> y) {
    if(x.first < y.first || x.second > y.second) return 0;
    if(y.second - x.second >= x.first - y.first) return 0;
    return 1;
}

bool ekill(pair<ll, ll> x, pair<ll, ll> y) {
    if(x.first < y.first || x.second > y.second) return 0;
    if(y.second - x.second <= x.first - y.first) return 0;
    return 1;
}

ll dfs(ll x) {
    ll res = 1;
    vs[x] = 1;
    for(ll i = 0; i < (ll)adj[x].size(); ++i) {
        if(vs[adj[x][i]]) continue;
        res += dfs(adj[x][i]);
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n + 1; ++i) sy[i] = -1;
    for(ll i = 0; i < n; ++i) {
        char c;
        ll a, b;
        cin >> c >> a >> b;
        if(c == 'N') vx.push_back({{a, b}, i});
        else vy.push_back({{a, b}, i});
    }

    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end(), cmp);

    for(ll i = 0; i < (ll)vx.size(); ++i) {
        for(ll j = 0; j < (ll)vy.size(); ++j) {
            if(sy[vy[j].second] == 1) continue;

            if(ekill(vx[i].first, vy[j].first)) {
                adj[vy[j].second].push_back(vx[i].second);
                //cout << 'E' << ' ' << vx[i].second << ' ' << vy[j].second << '\n';
                break;
            }

            if(nkill(vx[i].first, vy[j].first)) {
                sy[vy[j].second] = 1;
                adj[vx[i].second].push_back(vy[j].second);
                //cout << "N " << vy[j].second << ' ' << vx[i].second << '\n';
            } 
        }
    }

    /*for(ll i = 0; i < n; ++i, cout << '\n') {
        for(ll j : adj[i]) cout << j << ' ';
    }*/

    //for(ll i = 0; i < (ll)vy.size(); ++i) cout << vy[i].first.first << ' ' << vy[i].first.second << '\n';

    for(ll i = 0; i < n; ++i) {
        memset(vs, 0, sizeof(vs));
        cout << dfs(i) - 1 << '\n';
    }
}