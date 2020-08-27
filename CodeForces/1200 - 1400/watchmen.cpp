#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x, y, res;
map<pair<ll, ll>, ll> occ;
map<ll, ll> xx, yy;

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld %lld", &x, &y);
        occ[make_pair(x, y)]++;
        xx[x]++;
        yy[y]++;
    }

    for(auto i = xx.begin(); i != xx.end(); ++i) {
        res += ((i->second) * (i->second - 1))/2;
    }
    for(auto i = yy.begin(); i != yy.end(); ++i) {
        res += ((i->second) * (i->second - 1))/2; 
    }

    for(auto i = occ.begin(); i != occ.end(); ++i) {
        if(i->second <= 1) continue;
        res -= ((i->second) * (i->second - 1))/2;
    }

    printf("%lld\n", res);
    return 0;
}