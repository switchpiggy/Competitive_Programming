#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
ll n;
vector<pair<ll, ll>> v;
 
int main() {
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);

    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        v.push_back(make_pair(a, b));
    }
 
    sort(v.begin(), v.end());
 
    ll prev = -1;
 
    for(ll i = 0; i < v.size(); ++i) {
        ll cur = max(prev, v[i].first);
        prev = cur + v[i].second;
    }
 
    printf("%lld\n", prev);

    return 0;
}