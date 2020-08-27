#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, q, t;
vector<ll> b;

int main() {
    scanf("%lld %lld", &n, &q);
    for(ll i = 0; i < n; ++i) {
        ll temp;
        scanf("%lld", &temp);
        b.push_back(temp);
    }
    
    for(ll i = 1; i < b.size(); ++i) b[i] += b[i - 1];

    for(ll i = 0; i < q; ++i) {
        scanf("%lld", &t);

        ll r = lower_bound(b.begin(), b.end(), t) - b.begin();
        if(b[r] > t) r--;

        printf("%lld\n", r + 2);
    }

    return 0;
}