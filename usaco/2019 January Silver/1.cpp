#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, maxn, a, b;
map<ll, ll> deg;

int main() {
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);

    scanf("%lld", &n);
    for(ll i = 0; i < n - 1; ++i) {
        scanf("%lld %lld", &a, &b);
        deg[a]++;
        deg[b]++;
    }

    for(auto i = deg.begin(); i != deg.end(); ++i) {
        if(i->second > maxn) maxn = i->second;
    }

    printf("%lld\n", maxn + 1);
    return 0;
}