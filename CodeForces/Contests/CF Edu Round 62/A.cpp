#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[10007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    ll maxn = 0;
    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        maxn = max(maxn, a[i]);
        if(maxn <= i + 1) {
            maxn = 0;
            ans++;
        } else if(i == n - 1) {
            ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}