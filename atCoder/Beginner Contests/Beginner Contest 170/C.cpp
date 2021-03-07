#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll x, n, temp;
set<ll> p;

int main() {
    scanf("%lld %lld", &x, &n);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld", &temp);
        p.insert(temp);
    }

    ll range = 0;
    while(x + range <= 101 || x - range >= 0) {
        if(x - range >= 0 && p.find(x-range) == p.end()) {
            printf("%lld\n", x - range);
            return 0;
        } 
        if(p.find(x + range) == p.end()) {
            printf("%lld\n", x + range);
            return 0;
        }
        range++;
    }
}