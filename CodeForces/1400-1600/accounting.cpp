#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a, b;

int main() {
    cin >> a >> b >> n;

    if(b == 0) {
        cout << 0 << endl;
        return 0;
    }

    for(ll i = 0; i <= 1000; ++i) {
        ll cnt = 1;
        for(ll j = 0; j < n; ++j) cnt *= i;

        if(cnt * a == b) {
            cout << i << endl;
            return 0;
        }

        cnt = 1;
        for(ll j = 0; j < n; ++j) cnt *= -i;

        if(cnt * a == b) {
            cout << -i << endl;
            return 0;
        }
    }

    cout << "No solution" << endl;
    return 0;
}