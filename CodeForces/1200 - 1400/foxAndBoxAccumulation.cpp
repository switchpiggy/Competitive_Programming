#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x[107];

bool check(ll k) {
    for(ll i = 0; i < n; ++i) {
        if(x[i] < i/k) {
            return 0;
        }
    }

    return 1;
}

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) scanf("%lld", &x[i]);

    sort(x, x + n);

    ll l = 1, r = n;

    while(l < r) {
        ll mid = (l + r)/2;
        if(check(mid)) {
            r =  mid;
        } else {
            l = mid + 1;
        }
    }

    printf("%lld", l);
    return 0;
}