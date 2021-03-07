#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll x;
bool sieve[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> x;

    for(ll i = 2; i <= 200000; ++i) {
        if(sieve[i]) continue;
        for(ll j = i * 2; j <= 200000; j += i) sieve[j] = 1;
    }

    for(ll i = x; i <= 200000; ++i) {
        if(!sieve[i]) {
            cout << i << '\n';
            return 0;
        }
    }
}