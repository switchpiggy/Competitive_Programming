#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main() {

    ll n;

    cin >> n;

    ll ans = 1;

    ll x = n;

    for(ll i = 2; i * i <= n; ++i) {

        if(x%i == 0) {

            ans *= (ll) i;

            while(x%i == 0) x /= i;

        }

    }

    if(x > 1) ans *= x;

    cout << ans << endl;

}