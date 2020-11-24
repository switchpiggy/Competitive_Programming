#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    ll ans = 1, cur = 1;
    for(ll i = 1; i < n; ++i) {
        if(a[i] > a[i - 1] * 2) {
            ans = max(ans, cur);
            cur = 1;
        } else cur++;
    }

    ans = max(ans, cur);

    cout << ans << '\n';
    return 0;
}