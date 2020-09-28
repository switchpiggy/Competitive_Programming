#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

bool isPrime(ll x) {
    for(ll i = 2; i * i <= x; ++i) {
        if(x%i == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    cin >> n;

    ll ans = n;

    ll minPrime = n;
    for(ll i = n; i <= n + n/2; ++i) {
        if(isPrime(i)) {
            minPrime = i;
            break;
        }
    }

    cout << minPrime << '\n';

    for(ll i = 1; i < n; ++i) cout << i << ' ' << i + 1 << '\n';
    cout << n << ' ' << 1 << '\n';

    for(ll i = 1; i <= minPrime - n; ++i) {
        cout << i << ' ' << i + n/2 << '\n';
    }

    return 0;
}