#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, p[100007], c[100007], ans[100007];

int main() {
    cin >> n >> k;
    for(ll i = 0; i < n; ++i) {
        cin >> p[i];
    }

    for(ll i = 0; i < n; ++i) cin >> c[i];

    vector<pair<ll, pair<ll,ll>>> v;
    for(ll i = 0; i < n; ++i) {
        v.push_back(make_pair(p[i], make_pair(c[i], i)));
    }

    sort(v.begin(), v.end());
    multiset<ll> coins;
    ll sum = 0;

    for(ll i = 0; i < n; ++i) {
        ans[v[i].second.second] = v[i].second.first + sum;
        if(coins.size() < k) {
            sum += v[i].second.first;
            coins.insert(v[i].second.first);
        } else if(coins.size() == k && v[i].second.first > *(coins.begin())) {
            sum -= *(coins.begin());
            sum += v[i].second.first;

            ll cnt = coins.count(*(coins.begin())) - 1;
            ll b = *(coins.begin());
            coins.erase(*(coins.begin()));
            for(ll i = 0; i < cnt; ++i) coins.insert(b);
            coins.insert(v[i].second.first);
        }
    }

    for(ll i = 0; i < n; ++i) cout << ans[i] << ' ';

    return 0;
}