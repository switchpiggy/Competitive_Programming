#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        ll gcf = 180/__gcd(180ll, n);
        if(2 * n >= 360 - (360/gcf)) cout << 2 * gcf << '\n';
        else cout << gcf << '\n';
    }
}