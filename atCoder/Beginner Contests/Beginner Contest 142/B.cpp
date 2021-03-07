#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, h[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        cin >> h[i];
        if(h[i] >= k) ans++;
    }

    cout << ans << '\n';
    return 0;
}