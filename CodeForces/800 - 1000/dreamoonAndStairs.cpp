#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    ll ans = INT_MAX;
    for(ll i = 0; i <= n; ++i) {
        if((n - i)%2 == 0 && ((n - i)/2 + i)%m == 0) ans = min(ans, (n - i)/2 + i);
    }

    if(ans == INT_MAX) ans = -1;
    cout << ans << '\n';
}