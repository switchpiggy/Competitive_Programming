#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, l, r, cnt[400007], ans[200007];
vector<ll> cc;
vector<pair<ll, ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> l >> r;
        cc.push_back(l);
        cc.push_back(r + 1); 
        v.push_back({l, r + 1});
    }

    sort(cc.begin(), cc.end());
    cc.resize(unique(cc.begin(), cc.end()) - cc.begin());
    
    for(ll i = 0; i < n; ++i) {
        l = lower_bound(cc.begin(), cc.end(), v[i].first) - cc.begin();
        r = lower_bound(cc.begin(), cc.end(), v[i].second) - cc.begin();
        cnt[l]++;
        cnt[r]--;
    }

    for(ll i = 0; i < (ll)cc.size() - 1; ++i) {
        if(i) cnt[i] += cnt[i - 1];
        ans[cnt[i]] += cc[i + 1] - cc[i];
    }

    for(ll i = 1; i <= n; ++i) cout << ans[i] << ' ';
    return 0;
}