#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, diff[200007], ans[200007];
vector<pair<ll, ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(ll i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        v.push_back(make_pair(a, i));
    }

    for(ll i = 0; i < k; ++i) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        if(v[a].first > v[b].first) {
            diff[a]++;
        } else if(v[b].first > v[a].first) {
            diff[b]++;
        }
    }

    sort(v.begin(), v.end());
    for(ll i = 0; i < n; ++i) {
        ll cur = lower_bound(v.begin(), v.end(), make_pair(v[i].first, 0ll)) - v.begin();
        ans[v[i].second] = cur;
    }

    for(ll i = 0; i < n; ++i) cout << ans[i] - diff[i] << ' ';
    cout << '\n';

    return 0;
}