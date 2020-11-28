#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
vector<pair<pair<pair<ll, ll>, ll>, ll>> v;
bool ok[2007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        v.push_back({{{a, b}, c}, i + 1});
    }

    sort(v.begin(), v.end());
    for(ll i = 0; i < n; ++i) {
        if(ok[i]) continue;
        ll cur = -1;
        for(ll j = 0; j < n; ++j) {
            if(ok[j] || i == j) continue;
            if(cur == -1 || (abs(v[j].first.first.first - v[i].first.first.first) + abs(v[j].first.second - v[i].first.second) + abs(v[j].first.first.second - v[i].first.first.second) < abs(v[cur].first.first.first - v[i].first.first.first) + abs(v[cur].first.first.second - v[i].first.first.second) + abs(v[cur].first.second - v[i].first.second))) {
                cur = j;
            }
        }

        ok[cur] = ok[i] = 1;
        cout << v[cur].second << ' ' << v[i].second << '\n';
    }

    return 0;
}