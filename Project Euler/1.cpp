#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        ll a = (n - 1)/3, b = (n - 1)/5, c = (n - 1)/15;
        //cout << a << ' ' << b << ' ' << c << endl;
        cout << 3 * (a * (a + 1))/2 + 5 * (b * (b + 1))/2 - 15 * (c * (c + 1))/2 << endl;
    }

    return 0;
}