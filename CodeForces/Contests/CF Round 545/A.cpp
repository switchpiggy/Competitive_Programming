#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
map<ll, ll> occ;
ll n, t[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> t[i];

    ll ans = INT_MIN;
    vector<ll> v;
    ll cnt = 1;
    for(ll i = 1; i < n; ++i) {
        if(t[i] == t[i - 1]) cnt++;
        else {
            v.push_back(cnt);
            cnt = 1;
        }
    }

    v.push_back(cnt);

    for(ll i = 0; i < (ll)v.size() - 1; ++i) {
        ans = max(ans, 2 * min(v[i], v[i + 1]));
    }

    cout << ans << '\n';
    return 0;
}