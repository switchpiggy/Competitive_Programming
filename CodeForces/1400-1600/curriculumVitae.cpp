#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, s[107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> s[i];

    ll ans = 0;
    for(ll i = 0; i <= n; ++i) {
        ll res = 0;
        for(ll j = 0; j < i; ++j) if(s[j] == 1) res++;
        for(ll j = i; j < n; ++j) if(s[j] == 0) res++;

        ans = max(ans, n - res);
    }

    cout << ans << '\n';
    return 0;
}