#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a, b, ans;
vector<pair<ll, ll>> peaks;
bool covered[100007];

bool cmp(pair<ll, ll> x, pair<ll, ll> y) {
    if(x.second == y.second) return x.first > y.first;
    return x.second > y.second;
}

int main() {
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);

    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld %lld", &a, &b);
        peaks.push_back(make_pair(a, b));
    }

    sort(peaks.begin(), peaks.end(), cmp);

    for(ll i = 0; i < n; ++i) {
        if(covered[i]) continue;
        pair<ll, ll> cur = peaks[i];
        for(ll j = i + 1; j < n; ++j) {
            if(covered[j]) continue;
            if((cur.first - (cur.second - peaks[j].second)) <= peaks[j].first && cur.first + (cur.second - peaks[j].second) >= peaks[j].first) {
                ans++;
                covered[j] = 1;
            }
        }        
    }

    printf("%lld\n", n - ans);
    return 0;
}