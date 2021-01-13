#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benqueue queue
ll n, nxt[207], cnt, len[207], id[207], dist[207];
bool vis[207];

ll lcm(ll x, ll y) {
    return (x * y)/__gcd(x, y);
}

void cycle(ll x, ll y) {
    len[cnt]++;
    id[y] = cnt;
    if(y == x) return;
    cycle(x, nxt[y]);
}

bool cycle2(ll x, ll y, ll cur) {
    //len[cnt]++;
    //id[y] = cnt;
    if(y == x) return 1;
    if(cur > n) return 0;
    return cycle2(x, nxt[y], cur + 1);
}

void find_dist(ll x) {
    vis[x] = 1;
    if(id[x]) {
        dist[x] = 0;
        return;
    }

    find_dist(nxt[x]);
    dist[x] = dist[nxt[x]] + 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; ++i) cin >> nxt[i];

    for(ll i = 1; i <= n; ++i) {
        if(!id[i]) {
            if(nxt[i] == i) {
                id[i] = ++cnt;
                len[cnt] = 1;
                continue;
            } 

            if(cycle2(i, nxt[i], 0)) {
                ++cnt;
                cycle(i, nxt[i]);
            }
        }
    }

    memset(vis, 0, sizeof(vis));
    for(ll i = 1; i <= n; ++i) {
        if(!vis[i]) {
            find_dist(i);
        }
    }

    //for(ll i = 1; i <= n; ++i) cout << id[i] << ' ';

    ll lcd = 1;
    for(ll i = 1; i <= n; ++i) {
        if(len[i]) lcd = lcm(lcd, len[i]);
    }

    ll ans = lcd;
    for(ll i = 1; i <= n; ++i) {
        while(ans < dist[i]) ans += lcd;
    }

    cout << ans << '\n';
    return 0;
}