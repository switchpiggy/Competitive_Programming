#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);   
    cin >> n;
    ll ans = LLONG_MAX;
    for(ll i = 1; i * i * i <= n; ++i) {
        if(n%i != 0) continue;
        ll k = n/i;
        for(ll j = 1; j * j <= k; ++j) {
            if(k%j) continue;
            ans = min(ans, i * j + i * (k/j) + (k/j) * j);
        }
    } 

    cout << 2 * ans << '\n';
    return 0;
}