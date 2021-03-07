#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k;
vector<ll> pos;
vector<ll> neg;

bool cmp(ll x, ll y) {
    return abs(x) > abs(y);
}

int main() {
    scanf("%lld %lld", &n, &k);
    for(ll i = 0; i < n; ++i) {
        ll temp;
        scanf("%lld", &temp);
        if(temp > 0) pos.push_back(temp);
        if(temp < 0) neg.push_back(temp);
    }

    sort(pos.begin(), pos.end(), cmp);
    sort(neg.begin(), neg.end(), cmp);

    ll p = 0, nn = 0, prod = 1;
    while(p < pos.size() && nn < neg.size() && p + n <= k) {
        if(abs(neg[nn]) > pos[p] && nn + 1 < neg.size()) {
            prod *= neg[nn];
            prod *= neg[nn + 1];
            nn += 2;
        } else {
            prod *= pos[p];
            p++;
        }
    }

    printf("%lld\n", prod);
    return 0;
}