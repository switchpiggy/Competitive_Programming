#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[200007], odd[200007], even[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 1; i <= n; ++i) cin >> a[i];

    for(ll i = 1; i <= n; ++i) {
        if(i%2 == 1) odd[i] += a[i];
        else even[i] += a[i];
    }

    for(ll i = 1; i <= n; ++i) {
        odd[i] += odd[i - 1];
        even[i] += even[i - 1];
    }

    ll ans = 0;
    for(ll i = 1; i <= n; ++i) {
        if(even[i - 1] + (odd[n] - odd[i]) == odd[i - 1] + (even[n] - even[i])) ans++;
    }

    cout << ans << '\n';
    return 0;
}