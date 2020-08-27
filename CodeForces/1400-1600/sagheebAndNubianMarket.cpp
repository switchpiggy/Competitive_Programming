#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, s, a[100005], b[100005];

ll getAns(ll k) {
    for(ll i = 0; i < n; ++i) {
        b[i] = a[i] + (i + 1)*k;
    }

    sort(b, b + n);
    ll ans = 0;

    for(ll i = 0; i < k; ++i) ans += b[i];
    return ans;
}

int main() {
    scanf("%lld %lld", &n, &s);
    for(ll i = 0; i < n; ++i) scanf("%lld", &a[i]);

    ll l = 0, r = n + 1;
    while(l < r - 1) {
        ll m = (l + r)/2;

        if(getAns(m) <= s) {
            l = m;
        } else {
            r = m;
        }
    }

    printf("%lld %lld\n", l, getAns(l));
}