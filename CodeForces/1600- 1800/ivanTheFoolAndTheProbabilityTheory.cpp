#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, f[100007];

const ll MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    f[0] = 1, f[1] = 1;
    for(ll i = 2; i <= 100000; ++i) f[i] = (f[i - 1] + f[i - 2])%MOD;

    cin >> n >> m;
    cout << (2 * (f[n] + f[m] - 1)%MOD)%MOD << '\n';
    return 0;
}