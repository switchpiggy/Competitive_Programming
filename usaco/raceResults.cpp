#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
vector<pair<ll, pair<ll, ll>>> v;

bool comp(pair<ll, pair<ll, ll>> x, pair<ll, pair<ll, ll>> y) {
    return (x.first * 3600) + (x.second.first * 60) + x.second.second < (y.first * 3600) + (y.second.first * 60) + y.second.second;
}

int main() {
    

    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);

        v.push_back(make_pair(a, make_pair(b, c)));
    }

    sort(v.begin(), v.end(), comp);

    for(ll i = 0; i < n; ++i) {
        printf("%lld:%lld:%lld\n", v[i].first, v[i].second.first, v[i].second.second);
    }

    return 0;
}