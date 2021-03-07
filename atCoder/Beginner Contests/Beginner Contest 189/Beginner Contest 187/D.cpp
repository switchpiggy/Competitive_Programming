#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
vector<pair<ll, ll>> v;
bool cmp(pair<ll, ll> x, pair<ll, ll> y) {
    return x.second + 2 * x.first > y.second + 2 * y.first;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll res = 0;
    for(ll i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        v.push_back({x, y});
        res += x;
    }

    sort(v.begin(), v.end(), cmp);

    ll cnt = 0, sum = 0;
    for(ll i = 0; i < n; ++i) {
        if(sum > res) break;
        cnt++;
        res -= v[i].first;
        sum += v[i].first + v[i].second;
    }

    cout << cnt << '\n';    
}