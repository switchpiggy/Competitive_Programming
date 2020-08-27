#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, x, y;
vector<pair<ll, ll>> v;

void no() {
    printf("-1\n");
    exit(0);
}

int main() {
    scanf("%lld %lld", &n, &k);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld %lld", &x, &y);
        v.push_back(make_pair(x, y));
    }

    sort(v.begin(), v.end());

    vector<pair<ll, ll>> res;
    set<ll> s;

    for(ll i = 0; i < n; ++i) {
        s.clear();
        for(ll j = i + 1; j < n; ++j) {
            if(v[j].first - v[i].first < k && abs(v[j].second - v[i].second) < k) {
                s.insert(j);
            } else if(v[j].first - v[i].first >= k) break;
        }
        if(s.size() > 1) no();
        else if(s.size()) res.push_back(make_pair(i, *(s.begin())));
    }

    if(res.size() > 1) no();
    else if(!res.size()) printf("0\n");
    else printf("%lld\n", abs(v[res[0].first].first + k - v[res[0].second].first) * abs(v[res[0].second].second + k - v[res[0].first].second));

    return 0;
}