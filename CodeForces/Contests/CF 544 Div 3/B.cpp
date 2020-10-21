#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, d[200007], mod[107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin >> n >> k;
    for(ll i = 0; i < n; ++i) cin >> d[i];

    for(ll i = 0; i < n; ++i) {
        mod[d[i]%k]++;
    }

    ll ans = 2 * (mod[0]/2);

    for(ll i = 1; i <= k/2; ++i) {
        if(i == k/2 && k%2 == 0) {
            ans += 2 * (mod[i]/2);
            continue;
        }
        ans += 2 * min(mod[i], mod[k - i]);
    }

    cout << ans << '\n';
    return 0;
}