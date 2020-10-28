#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b, c, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) {
        ll x, y, z;
        cin >> x >> y >> z;
        a += x;
        b += y;
        c += z;
    }

    if(!a && !b && !c) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}