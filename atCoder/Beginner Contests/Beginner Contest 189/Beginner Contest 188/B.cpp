
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007], b[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll ans = 0;
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for(ll i = 0; i < n; ++i) cin >> b[i];

    for(ll i = 0; i < n; ++i) ans += b[i] * a[i];

    cout << (ans == 0 ? "Yes\n" : "No\n");
    return 0;
}