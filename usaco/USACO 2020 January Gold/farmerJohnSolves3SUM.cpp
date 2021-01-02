#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, q, a[5007], res[5007][5007];

void fileIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    return;
}

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fileIO("threesum");
    cin >> n >> q;

    for(ll i = 0; i < n; ++i) cin >> a[i];

    for(ll i = 0; i < n; ++i) {
        gp_hash_table<int, int> h({}, {}, {}, {}, {1 << 14});
        for(ll j = i + 1; j < n; ++j) {
            //gp_hash_table<int, int> h({}, {}, {}, {}, {1 << 13});
            ll cur = -a[i] - a[j];
            auto itr = h.find(cur);
            if(itr != h.end()) res[i][j] = itr->second;
            h[a[j]]++;
        }
    }

    for(ll i = n - 1; i >= 0; --i) {
        for(ll j = 0; j < n; ++j) res[i][j] += res[i + 1][j] + res[i][j - 1] - res[i + 1][j - 1];
    }

    for(ll i = 0; i < q; ++i) {
        ll x, y;
        cin >> x >> y;
        cout << res[x - 1][y - 1] << '\n';
    }

    return 0;
}