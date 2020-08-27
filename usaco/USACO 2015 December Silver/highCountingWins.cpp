#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, temp;
set<ll> e, b;

int main() {
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld", &temp);
        e.insert(temp);
    } 
    for(ll i = 1; i <= 2 * n; ++i) {
        if(!e.count(i)) {
            b.insert(i);
        }
    }

    ll ans = 0;
    for(auto i = e.begin(); i != e.end(); ++i) {
        auto j = b.lower_bound(*i);
        if(*j > *i) {
            b.erase(*j);
            ans++;
        } else {
            b.erase(*(b.begin()));
        }
    }

    printf("%lld\n", ans);
    return 0;
}