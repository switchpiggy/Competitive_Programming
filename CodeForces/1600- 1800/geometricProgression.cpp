#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
map<ll, ll> occ, cur;
ll n, k, a[200007];

int main() {
    ios_base::sync_with_stdio(0);
        cin.tie(0);

    cin >> n >> k;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        occ[a[i]]++;
    }

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        if(a[i]%k != 0) {
            cur[a[i]]++;
            continue;
        }

        //cout << cur[a[i]/k] << ' ' << occ[a[i] * k] << '\n';
        ans += (cur[a[i]/k]) * (occ[a[i] * k] - cur[a[i] * k] - (a[i] == a[i]/k));
        cur[a[i]]++;
    }

    cout << ans << '\n';
    return 0;
}