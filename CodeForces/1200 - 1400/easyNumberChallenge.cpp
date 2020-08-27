#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b, c, dp[1000007], ans;

const ll mod = 1073741824;

int main() {
    scanf("%lld %lld %lld", &a, &b, &c);

    for(ll i = 1; i <= 1000000; ++i) {
        for(ll j = i; j <= 1000000; j += i) {
            dp[j]++;
        }
    }

    for(ll i = 1; i <= a; ++i) {
        for(ll j = 1; j <= b; ++j) {
            for(ll k = 1; k <= c; ++k) {
                ans += dp[i * j * k];
            }
        }
    }
    

    printf("%lld\n", ans);

    return 0;
}