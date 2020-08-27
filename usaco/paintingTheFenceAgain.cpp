#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a, b;
vector<pair<ll, ll>> v;

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld %lld", &a, &b);
        v.push_back(make_pair(a, b));
    }

    sort(v.begin(), v.end());

    ll i = 0;

    while(i < n) {
        ll start = v[i].first, end = v[i].second;
        while(v[i].second >= v[i + 1].first && i + 1 < n) {
        	i++;
        	end = max(v[i].second, end);
        }
        printf("%lld %lld\n", start, end);
        i++;
    }

    return 0;
}