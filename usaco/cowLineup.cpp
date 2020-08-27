#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long int ll;
ll totalDistinct, distinct, a, b, n, ans = INT_MAX;
vector<pair<ll, ll>> v;
map<ll, ll> occ;

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld %lld", &a, &b);
        if(occ[b] == 0) totalDistinct++;
        occ[b]++;
        v.push_back(make_pair(a, b));
    }

    occ.clear();

    sort(v.begin(), v.end());

    ll i = 0, j = 0;
    while(i < (ll)v.size() && j < (ll)v.size()) {
        while(distinct < totalDistinct && j < (ll)v.size()) {
            occ[v[j].second]++;
            if(occ[v[j].second] == 1) distinct++;
            j++;
        }
        ans = min(ans, v[j - 1].first - v[i].first);

        while(distinct == totalDistinct && i < j) {
            occ[v[i].second]--;
            if(occ[v[i].second] == 0) distinct--;
            i++;
        }

        ans = min(ans, v[j - 1].first - v[i - 1].first);
    }

    printf("%lld\n", ans);

    return 0;
}