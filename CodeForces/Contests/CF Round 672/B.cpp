#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[100007];
map<ll, ll> sigFig;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        sigFig.clear();
        cin >> n;
        for(ll i = 0; i < n; ++i) cin >> a[i];

        ll ans = 0;

        for(ll i = 0; i < n; ++i) {
            ll maxn = 0;
            for(ll j = 0; j <= 30; ++j) {
                if(a[i] & (1 << j)) maxn = j;
            }

            ans += sigFig[maxn];
            sigFig[maxn]++;
        }

        cout << ans << '\n';
    }

    return 0;
}