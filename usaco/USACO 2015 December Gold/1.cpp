#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
bool used[100007];
vector<ll> x, y;
set<ll> s, t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        used[a] = 1;
        y.push_back(a);
    }

    for(ll i = 1; i <= 2 * n; ++i) {
        if(!used[i]) x.push_back(i);
    }

    sort(x.begin(), x.end(), greater<ll>());
    vector<ll> large(x.begin(), x.begin() + n/2), small(x.begin() + n/2, x.end());

    for(ll i = 0; i < n/2; ++i) s.insert(large[i]), t.insert(-small[i]);

    large.clear();
    small.clear();

    for(ll i = 0; i < n; ++i) {
        if(i < n/2) large.push_back(y[i]);
        else small.push_back(-y[i]);
    }

    sort(large.begin(), large.end(), greater<ll>());
    sort(small.begin(), small.end());

    ll ans = 0;
    for(ll i = 0; i < (ll)large.size(); ++i) {
        auto k = s.lower_bound(large[i]);
        if(k == s.end()) s.erase(*s.begin());
        else {
            ans++;
            s.erase(*k);
        }
    }

    for(ll i = 0; i < (ll)small.size(); ++i) {
        auto k = t.lower_bound(small[i]);
        if(k == t.end()) t.erase(*t.begin());
        else {
            ans++;
            t.erase(*k);
        }
    }

    cout << ans << '\n';
    return 0;
}