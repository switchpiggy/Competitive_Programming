#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007];

#define INF 9223372036854775807;

int main() {
    cin >> n;

    ll ans = INF

    for(ll i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);

    ll limit = pow(1e18, 1.0/n);

    ll res = 0;
    for(ll c = 1; c <= limit; ++c) {
        res++;
        ll cnt = 0, cur = 1;
        for(ll i = 0; i < n; ++i) {
            cnt += abs(a[i] - cur);
            cur *= c;
        }

        //cout << c << endl;

        ans = min(cnt, ans);
    }

    cout << ans << endl;

    return 0;
}