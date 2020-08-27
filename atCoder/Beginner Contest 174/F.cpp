#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, q, l, r, pref[500007], temp;
map<ll, ll> occ;

int main() {
    ll dist = 0;
    scanf("%lld %lld", &n, &q);
    for(ll i = 1; i <= n; ++i){
        scanf("%lld", &temp);
        occ[temp]++;
        if(occ[temp] == 1) dist++;
        pref[i] = dist;
    }

    for(ll i = 0; i < q; ++i) {
        scanf("%lld %lld", &l, &r);
        printf("%lld\n", pref[r] - pref[l - 1]);
    }
}