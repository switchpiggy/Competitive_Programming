#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll k, c[1007], pascal[1007][1007];

const ll MOD = 1e9 + 7;

void generate() {
    for(ll i = 0; i < 1003; ++i) {
        for(ll j = 0; j <= i; ++j) {
            if(j == 0 || j == i) {
                pascal[i][j] = 1;
                continue;
            }

            pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];
            pascal[i][j] %= MOD;
        }
    }

    return;
}

ll choose(ll n, ll r) {
    return pascal[n][r];
}

int main() {
    generate();
    cin >> k;
    for(ll i = 0; i < k; ++i) cin >> c[i];

    ll ans = 0, res = 1;
    for(ll i = 0; i < k; ++i) {
        res *= choose(ans + c[i] - 1, c[i] - 1);
        res %= MOD;
        ans += c[i];
    }

    cout << res << '\n';
    return 0;
}