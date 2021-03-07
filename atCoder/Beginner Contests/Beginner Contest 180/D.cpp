#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll x, y, a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> x >> y >> a >> b;

    ll ans = 0;
    while(1) {
        __int128 z = x;
        if(z * a >= y || z * a >= z + b) break;
        x *= a;
        ans++;
        //cout << x << '\n';
    }

    //cout << (y - x + b - 1)/b << '\n';

    cout << ans + ((y - 1) - x)/b << '\n';
    return 0;
}