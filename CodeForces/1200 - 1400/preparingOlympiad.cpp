#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll l, r, n, x, c[17];

int main() {
    scanf("%lld %lld %lld %lld", &n, &l, &r, &x);
    for(ll i = 0; i < n; ++i) scanf("%lld", &c[i]);

    ll mask = 1 << n, res = 0;

    for(ll i = 0; i < mask; ++i) {
        ll sum = 0, maxn = 0, minn = 1e6;
        for(ll j = 0; j < n; ++j) {
            if(i & (1 << j)) {
                sum += c[j];
                maxn = max(maxn, c[j]);
                minn = min(minn, c[j]);
            }
        }
        if((maxn - minn) >= x && sum <= r && sum >= l) res++;
    }

    printf("%lld\n", res);
    return 0;
}