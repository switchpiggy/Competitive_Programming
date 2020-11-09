#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll adj[507][507], x[507], n, ans[507];
bool added[507];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= n; ++j) {
            cin >> adj[i][j];
        }
    }
    for(ll i = 0; i < n; ++i) cin >> x[i];

    for(ll k = n - 1; k >= 0; --k) {
        added[x[k]] = 1;
        for(ll i = 1; i <= n; ++i) {
            for(ll j = 1; j <= n; ++j) {
                adj[i][j] = min(adj[i][j], adj[i][x[k]] + adj[x[k]][j]);
                if(added[i] && added[j]) ans[k] += adj[i][j];
            }
        }
    }
    
    for(ll i = 0; i < n; ++i) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}