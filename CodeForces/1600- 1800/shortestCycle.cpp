#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007], dist[207][207], g[207][207];
const ll maxn = 1e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] == 0) n--, i--;
    }

    if(n > 120) {
        cout << "3\n";
        return 0;
    }

    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= n; j++) {
            if(i == j) continue;
            if(a[i] & a[j]) dist[i][j] = 1;
            else dist[i][j] = maxn;
        }
    }

    memcpy(g, dist, sizeof(dist));

    ll ans = maxn;
    for(ll k = 1; k <= n; k++) {
        for(ll i = 1; i < k; i++) {
            for(ll j = i + 1; j < k; j++) ans = min(ans, g[i][k] + g[k][j] + dist[j][i]);
        }

        for(ll i = 1; i <= n; i++) {
            for(ll j = 1; j <= n; j++) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }

    if(ans == maxn) ans = -1;
    cout << ans << '\n';
    return 0;
}