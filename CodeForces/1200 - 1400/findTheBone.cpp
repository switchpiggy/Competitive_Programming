#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, k, a, b, h;
set<ll> holes;

int main() {
    scanf("%lld %lld %lld", &n, &m, &k);
    for(ll i = 0; i < m; ++i) {
        scanf("%lld", &h);
        holes.insert(h);
    }

    if(holes.count(1)) {
        printf("1\n");
        return 0;
    }

    ll cur = 1;

    for(ll i = 0; i < k; ++i) {
        scanf("%lld %lld", &a, &b);

        if(a == cur) cur = b;
        else if(b == cur) cur = a;

        if(holes.count(cur)) {
            printf("%lld\n", cur);
            return 0;
        }
    }
    
    printf("%lld\n", cur);
}