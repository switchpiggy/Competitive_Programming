#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, p[1000007], dist[107][107];
char a[107][107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= n; ++j) {
            cin >> a[i][j];
            dist[i][j] = LONG_LONG_MAX;
            if(a[i][j] == '1') dist[i][j] = 1;
        }

        dist[i][i] = 0;
    }

    cin >> m;
    for(ll i = 1; i <= m; ++i) cin >> p[i];

    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= n; ++j) {
            for(ll k = 1; k <= n; ++k) {
                if(dist[i][k] == LONG_LONG_MAX || dist[k][j] == LONG_LONG_MAX) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    vector<ll> ans;
    ans.push_back(1);

    for(ll i = 2; i <= m; ++i) {
        if(dist[p[ans.back()]][p[i]] < i - ans.back()) {
            ans.push_back(i - 1);
        }
    }

    /*for(ll i = 1; i <= n; ++i, cout << '\n') {
        for(ll j = 1; j <= n; ++j) cout << dist[i][j] << ' ';
    }*/

    ans.push_back(m);
    cout << (ll)ans.size() << '\n';
    for(ll i = 0; i < (ll)ans.size(); ++i) cout << p[ans[i]] << ' ';
    cout << '\n';
    return 0;
}