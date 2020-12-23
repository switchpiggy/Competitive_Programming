#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll m, a[1007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m;
    for(ll i = 0; i < m; ++i) cin >> a[i];
    sort(a, a + m);

    ll gcd = a[1];
    for(ll i = 2; i < m; ++i) gcd = __gcd(gcd, a[i]);
    
    if(gcd%a[0] != 0) {
        cout << "-1\n";
        return 0;
    }

    cout << 2 * m - 1 << '\n';
    cout << a[0] << ' ';
    for(ll i = 1; i < m; ++i) {
        cout << a[i] << ' ';
        cout << a[0] << ' ';
    }

    return 0;
}