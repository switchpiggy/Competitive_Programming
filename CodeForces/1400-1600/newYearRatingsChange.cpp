#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll n;
pair<ll, ll> a[300005];

bool comp(pair<ll, ll> x, pair<ll, ll> y) {
    return x.second < y.second;
}

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld", &a[i].first);
        a[i].second = i;
    }

    sort(a, a + n);

    ll cur = 0;
    for(ll i = 0; i < n; ++i) {

        if(a[i].first > cur) {
            cur = a[i].first + 1;
        } else {
            a[i].first = cur;
            cur++;
        }

    }

    sort(a, a + n, comp);
    for(ll i = 0; i < n; ++i) printf("%lld ", a[i].first);

    return 0;
}