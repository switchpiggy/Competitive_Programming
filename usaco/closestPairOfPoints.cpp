#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x, y;
vector<pair<ll,ll>> v;

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld %lld", &x, &y);
        v.push_back(make_pair(x, y));
    }

    sort(v.begin(), v.end());
    ll curDist = INT_MAX;

    for(ll i = 0; i < n; ++i) {
        for(ll j = i + 1; j < n; ++j) {
            if(v[j].first - v[i].first >= sqrt(curDist)) break;
            curDist = min(curDist, (v[j].first - v[i].first) * (v[j].first - v[i].first) + abs(v[j].second - v[i].second) * abs(v[j].second - v[i].second));
        }
    }

    printf("%lld\n", curDist);

    return 0;
}