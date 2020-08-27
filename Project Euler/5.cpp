#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        ll lcm = 1;
        for(ll i = 1; i <= n; ++i) lcm = (lcm * i)/__gcd(lcm, i);

        cout << lcm << endl;
    }

    return 0;
}