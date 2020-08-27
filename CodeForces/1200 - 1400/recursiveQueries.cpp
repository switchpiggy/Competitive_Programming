#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll q, l, r, k, arr[10][1000007];

ll f(ll x) {
    if(x < 10) return x;
    ll prod = 1;
    while(x) {
        if(x%10) prod *= x%10;
        x /= 10;
    }

    return f(prod);
}

int main() {
    scanf("%lld", &q);

    for(ll i = 1; i <= 1000000; ++i) {
        arr[f(i)][i]++;
    }
    for(ll i = 1; i < 10; ++i) {
        for(ll j = 1; j <= 1000000; ++j) {
            arr[i][j] += arr[i][j - 1];
        }
    }

    while(q--) {
        scanf("%lld %lld %lld", &l, &r, &k);
        printf("%lld\n", arr[k][r] - arr[k][l - 1]);
    }

}