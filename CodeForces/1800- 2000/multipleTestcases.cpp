#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, m[200007], c[200007], occ[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(ll i = 0; i < n; ++i) {
        cin >> m[i];
        occ[m[i]]++;
    }
    for(ll i = 0; i < k; ++i) cin >> c[i];

    ll ans = INT_MIN;
    for(ll i = k; i >= 1; --i) {
        occ[i] += occ[i + 1];
        ans = max(ans, (occ[i] + c[i - 1] - 1)/c[i - 1]);
    }

    sort(m, m + n);

    vector<vector<ll>> res(ans, vector<ll>());
    for(ll i = 0; i < n; ++i) {
        res[i%ans].push_back(m[i]);
    }

    cout << ans << '\n';
    for(ll i = 0; i < ans; ++i, cout << '\n') {
        cout <<  (ll)res[i].size() << ' ';
        for(ll j = 0; j < (ll)res[i].size(); ++j) cout << res[i][j] << ' ';
    }

    return 0;
}