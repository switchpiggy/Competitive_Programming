#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    if(b - a >= 10) {
        cout << "0\n";
        return 0;
    }

    ll ans = 1;
    for(ll i = a + 1; i <= b; ++i) {
        ans *= i;
        ans %= 10;
    }

    cout << ans << '\n';
    return 0;
}