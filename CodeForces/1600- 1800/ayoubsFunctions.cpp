#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, m;

ll fact(ll x) {
    ll ans = 1;
    for(ll i = 1; i <= x; ++i) ans *= i;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> m;
        cout << (n * (n + 1))/2 - ((((n - m)/(m + 1)) * ((n - m)/(m + 1) + 1))/2 * (m + 1) + ((n - m)/(m + 1) + 1) * ((n - m)%(m + 1))) << '\n';
    }

    return 0;
}