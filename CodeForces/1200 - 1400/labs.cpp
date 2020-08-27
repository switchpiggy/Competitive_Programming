#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[307][307];

int main() {
    ll cur = 1;
    scanf("%lld", &n);

    for(ll i = 1; i <= n; ++i) {
        if(i%2) {
            for(ll j = n; j >= 1; --j) {
                a[j][i] = cur++;
            }
        } else {
            for(ll j = 1; j <= n; ++j) {
                a[j][i] = cur++;
            }
        }
    }

    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= n; ++j) printf("%lld ", a[i][j]);
        printf("\n");
    }

    return 0;
}