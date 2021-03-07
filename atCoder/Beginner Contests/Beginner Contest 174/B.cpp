#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, d;
vector<pair<ll, ll>> v;

int main() {
    scanf("%lld %lld", &n, &d);
    for(ll i = 0; i < n; ++i) {
        ll x, y;
        scanf("%lld %lld", &x, &y);
        v.push_back(make_pair(x, y));
    } 

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        if(sqrt(v[i].first * v[i].first + v[i].second * v[i].second) <= d) ans++; 
    }

    printf("%lld\n", ans);
    return 0;
}