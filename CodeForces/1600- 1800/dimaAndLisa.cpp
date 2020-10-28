#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

bool prime(ll x) {
    for(ll i = 2; i * i <= x; ++i) {
        if(x%i == 0) return 0;
    }

    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    if(prime(n)) {
        cout << 1 << '\n' << n << '\n';
        return 0;
    }

    n -= 3;
    for(ll i = 2;; ++i) {
        if(prime(i) && prime(n - i)) {
            cout << 3 << '\n' << 3 << ' ' << i << ' ' << n - i << '\n';
            return 0;
        }
    }

    return 0;
}