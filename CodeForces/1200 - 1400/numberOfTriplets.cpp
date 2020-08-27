#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a, b;
vector<pair<ll, ll>> v;
set<pair<ll, ll>> s;

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld %lld", &a, &b);
        v.push_back(make_pair(a + 1000, b + 1000));
        s.insert(make_pair(a + 1000, b + 1000));
    }

    sort(v.begin(), v.end());
    ll res = 0;

    for(ll i = 0; i < n; ++i) {
        for(ll j = i + 1; j < n; ++j) {
            if(abs(v[j].first - v[i].first)%2 == 0 && abs(v[j].second - v[i].second)%2 == 0) {
                if(s.find(make_pair(v[i].first + (v[j].first - v[i].first)/2, v[i].second + (v[j].second - v[i].second)/2)) != s.end()) res++;
            }
        }
    }

    printf("%lld\n", res);
    return 0;
}