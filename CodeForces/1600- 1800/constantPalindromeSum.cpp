#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, k, a[200007], diff[400007], occ[400007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> k;
        memset(occ, 0, sizeof(occ[0]) * (2 * k + 1));
        memset(diff, 0, sizeof(diff[0]) * (2 * k + 1));
        for(ll i = 0; i < n; ++i) cin >> a[i];
        for(ll i = 0; i < n/2; ++i) {
            diff[min(a[i], a[n - i - 1]) + 1]++;
            diff[max(a[i], a[n - i - 1]) + k + 1]--;
            occ[a[i] + a[n - i - 1]]++;
        }

        for(ll i = 1; i <= 2 * k + 1; ++i) diff[i] += diff[i - 1];

        ll ans = INT_MAX;
        for(ll i = 1; i <= 2 * k; ++i) {
            ans = min(ans, (diff[i] - occ[i]) + 2 * (n/2 - diff[i]));
        }

        cout << max(ans, 0ll) << '\n';
    }

    return 0;
}