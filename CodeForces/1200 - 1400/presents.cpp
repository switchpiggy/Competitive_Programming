#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, c;
bool res[407];

int main() {
    scanf("%lld %lld %lld", &n, &k, &c);
    res[0] = 1;
    for(ll i = 0; i < c; ++i) {
        ll temp;
        scanf("%lld", &temp);
        res[temp] = 1;
    }

    for(ll i = 0; i <= n - k; ++i) {
        if(!res[i]) continue;
        ll j = i + 1;
        while(j <= i + k && !res[j]) j++;
        if(j > i + k) res[i + k] = 1;
    }

    ll cnt = 0;
    for(ll i = 1; i <= n; ++i) if(res[i]) cnt++;

    printf("%lld\n", cnt);
    return 0;
}