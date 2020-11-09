#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[2007], pref[2007][27];
vector<pair<ll, ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        v.clear();
        cin >> n;
        memset(pref, 0, sizeof(pref[0][0]) * (n + 1) * 27);
        for(ll i = 1; i <= n; ++i) {
            cin >> a[i];
            pref[i][a[i]]++;
        }

        for(ll i = 1; i <= n; ++i) {
            for(ll j = 1; j <= 26; ++j) pref[i][j] += pref[i - 1][j];
        }
        
        ll ans = 0;
        for(ll i = 1; i <= n; ++i) {
            for(ll j = i; j <= n; ++j) {
                ll cnt = 0, cnt2 = 0;
                for(ll k = 1; k <= 26; ++k) cnt = max(cnt, pref[j][k] - pref[i - 1][k]);
                for(ll k = 1; k <= 26; ++k) {
                    cnt2 = max(cnt2, min(pref[i - 1][k], pref[n][k] - pref[j][k]));
                }

                ans = max(ans, cnt2 * 2 + cnt);
            }
        }

        cout << ans << '\n';
    }

    return 0;
}