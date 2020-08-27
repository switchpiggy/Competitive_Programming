#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, temp;
set<ll> x;

bool check(ll cur) {
    ll a = k;
    set<ll> v = x;
    while(a && !v.empty()) {
        a--;
        ll f = *(v.begin());
        while(*(v.begin()) >= f && *(v.begin()) <= f + 2 * cur) v.erase(*(v.begin()));
    }

    if(v.empty()) return 1;
    return 0;
}

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    scanf("%lld %lld", &n, &k);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld", &temp);
        x.insert(temp);
    }

    ll l = 0, r = n;
    while(l < r) {
        ll mid = (l + r)/2;
        if(check(mid)) {
            r = mid;
        } else l = mid + 1;
    }

    printf("%lld\n", l);
    return 0;
}