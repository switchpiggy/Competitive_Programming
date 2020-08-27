#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x, y;
map<ll, ll> occ;

int main() {
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld %lld", &x, &y);
        occ[y] += x;
    }

    auto i = occ.end();
    i--;
    auto j = occ.begin();
    ll res = 0;

    while(i != j && i != occ.begin() && j != occ.end()) {
        if(i->second == 0){
            i--;
            continue;
        }

        if(j->second == 0) {
            j++;
            continue;
        }

        ll mins = min(i->second, j->second);
        i->second -= mins;
        j->second -= mins;

        res = max(res, i->first + j->first);
        if(!i->second) i--;
        if(!j->second) j++;
    }

    if(i->second) {
        res = max(res, i->first * 2);
        i->second = 0;
    }

    if(j->second) {
        res = max(res, j->first * 2);
    }

    printf("%lld\n", res);
    return 0;
}