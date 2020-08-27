#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a, b;
vector<pair<ll, pair<ll, ll>>> v;

bool comp(pair<ll, pair<ll, ll>> x, pair<ll, pair<ll, ll>> y) {
    return x.first * y.second.first > y.first * x.second.first;
}

int main() {
    scanf("%lld", &n);

    for(ll i = 0; i < n; ++i) {
        scanf("%lld %lld", &a, &b);

        v.push_back(make_pair(a, make_pair(b, i + 1)));
    }

    sort(v.begin(), v.end(), comp);

    printf("%lld\n", v[0].second.first + v[1].second.first + v[2].second.first);
    printf("%lld\n%lld\n%lld\n", v[0].second.second, v[1].second.second, v[2].second.second);

    return 0;
}