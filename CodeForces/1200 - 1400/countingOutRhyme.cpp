#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll n, k;
vector<ll> v;

int main() {
    scanf("%lld %lld", &n, &k);
    for(ll i = 1; i <= n; ++i) v.push_back(i);

    ll pos = 0;
    
    while(k--) {
        ll a;
        scanf("%lld", &a);

        ll pos1 = (pos + a)%(v.size());
        pos = pos1%(v.size() - 1);

        printf("%lld ", v[pos1]);
        v.erase(v.begin() + pos1);
    }

    return 0;
}