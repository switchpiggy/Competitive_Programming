#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x[1007];
vector<pair<ll, ll>> v;

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld", &x[i]);
    }

    for(ll i = 0; i < n - 1; ++i) {
        v.push_back(make_pair((ll)min(x[i], x[i + 1]), (ll)max(x[i], x[i + 1])));
    }

    sort(v.begin(), v.end());

    for(ll i = 0; i < v.size(); ++i) {
        for(ll j = i + 1; j < v.size(); ++j)
            if((v[i].first == v[j].first && v[i].second == v[j].second) || (v[i].first < v[j].first && v[j].first < v[i].second && v[i].second < v[j].second)) {
                printf("yes\n");
                return 0;
            }
    }

    printf("no\n");
    return 0;
}