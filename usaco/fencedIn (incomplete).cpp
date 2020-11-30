#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll r[2007][2007], d[2007][2007], a, b, n, m;
priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
ll prims() {
    pq.push({0, {0, 0}});
    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> n >> m;
    for(ll i = 0; i < n; ++i) {
        ll c;
        cin >> c;
        for(ll j = 0; j <= m; ++j) {
            r[j][i] = c;
        }
    }

    for(ll i = 0; i < m; ++i) {
        ll c;
        cin >> c;
        for(ll j = 0; j <= n; ++j) {
            d[i][j] = c;
        }
    }


}