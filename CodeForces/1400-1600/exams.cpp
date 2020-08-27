#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a, b;
vector<pair<ll, ll>> dates;

int main() {
    scanf("%lld", &n);

    for(ll i = 0; i < n; ++i) {
        scanf("%lld %lld", &a, &b);
        dates.push_back(make_pair(a, b));
    }

    sort(dates.begin(), dates.end());
    ll latest = 0;

    for(ll i = 0; i < n; ++i) {
        if(latest <= dates[i].second) latest = dates[i].second;
        else latest = dates[i].first;
    }

    printf("%lld", latest);
}