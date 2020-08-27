#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, maxs = 0, l[1000007], minDist = INFINITY, cur;
map<ll, ll> occ;

int main() {
    scanf("%lld", &n);

    for(ll i = 0; i < n; ++i) {
        ll temp;
        scanf("%lld", &temp);

        if(!occ[temp]) {
            l[temp] = i;
            occ[temp] = 1;
        } else occ[temp]++;

        if(occ[temp] > maxs) {
            minDist = i - l[temp] + 1;
            cur = l[temp] + 1;
            maxs = occ[temp];
        } else if(occ[temp] == maxs && i - l[temp] + 1 < minDist) {
            minDist = i - l[temp] + 1;
            cur = l[temp] + 1;
        }
    }

    printf("%lld %lld\n", cur, cur + minDist - 1);

    return 0;
}