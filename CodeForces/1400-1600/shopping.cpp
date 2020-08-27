#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, k, pos[107];

int main() {
    cin >> n >> m >> k;
    for(ll i = 0; i < k; ++i) {
        ll temp;
        cin >> temp;
        pos[temp] = i + 1;
    }

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) {
            ll order;
            cin >> order;

            ans += pos[order];

            ll cur = pos[order];
            for(ll a = 1; a <= k; ++a) {
                if(pos[a] < cur) pos[a]++;
            }

            pos[order] = 1;

            //for(ll a = 1; a <= k; ++a) cout << pos[a] << ' ';
            //cout << endl;
        }
    }

    cout << ans << endl;
    return 0;
}