#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> v;

    if(v >= n - 1) {
        cout << n - 1 << '\n';
        return 0;
    }

    ll ans = v;
    for(ll i = 2; i <= n; ++i) {
        if(v - 1 >= n - i) break;
        else {
            ans += i;
        }
    }

    cout << ans << '\n';
    return 0;
}