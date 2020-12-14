#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, a, b, f[5000007];
bool sieve[5000007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(ll i = 2; i <= 5000000; ++i) {
        if(sieve[i]) continue;
        f[i]++;
        for(ll j = i * 2; j <= 5000000; j += i) {
            sieve[j] = 1;
            f[j] = f[j/i] + 1;
        }
    }

    for(ll i = 2; i <= 5000000; ++i) f[i] += f[i - 1];

    cin >> t;
    while(t--) {
        cin >> a >> b;
        cout << f[a] - f[b] << '\n';
    }

    return 0;
}