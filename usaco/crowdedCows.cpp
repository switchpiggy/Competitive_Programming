#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, d, a, b, ans = 0;
vector<pair<ll, ll>> v;

int main() {
    scanf("%lld %lld", &n, &d);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld %lld", &a, &b);
        v.push_back(make_pair(a, b));
    }

    sort(v.begin(), v.end());

    ll j = 0, k = 0;
    multiset<ll> bef, aft;
    for(ll i = 0; i < n; ++i) {
        while(k < n && v[k].first <= v[i].first + d) {
            aft.insert(v[k].second);
            k++;
        }
        while(j < n && v[j].first + d < v[i].first) {
            bef.erase(bef.find(v[j].second));
            j++;
        }
        bef.insert(v[i].second);
        if(*(--bef.end()) >= 2 * v[i].second && *(--aft.end()) >= 2 * v[i].second) ans++;

        aft.erase(aft.find(v[i].second));
    }

    printf("%lld\n", ans);

    return 0;
}