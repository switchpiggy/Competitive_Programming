#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, u, v, p[200007], sz[200007], maxe[200007], mine[200007];

ll get(ll x) {return p[x] = (p[x] == x ? x : get(p[x]));}

void uni(ll x, ll y) {
    x = get(x);
    y = get(y);
    if(x == y) return;
    if(sz[x] > sz[y]) swap(x, y);
    maxe[y] = max(maxe[y], maxe[x]);
    mine[y] = min(mine[y], mine[x]);
    p[x] = y;
    sz[y] += sz[x];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    iota(p + 1, p + n + 1, 1);
    iota(maxe + 1, maxe + n + 1, 1);
    iota(mine + 1, mine + n + 1, 1);
    
    for(ll i = 1; i <= n; ++i) sz[i] = 1;

    for(ll i = 0; i < m; ++i) {
        cin >> u >> v;
        uni(u, v);
    }

    ll ans = 0;
    for(ll i = 1; i <= n; ++i) {
        ll cur = get(i);
        //cout << sz[cur] << ' ';
        //cout << mine[cur] << ' ' << maxe[cur] << '\n';
        if(sz[cur] < maxe[cur] - mine[cur] + 1) {
            for(ll j = mine[cur]; j <= maxe[cur]; ++j) {
                if(get(j) != get(cur)) {
                    uni(j, cur);
                    ans++;
                    //cout << i << ' ' << cur << ' ' << j << '\n';
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}