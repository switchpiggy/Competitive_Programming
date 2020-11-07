#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[200007];
map<ll, ll> dp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    for(ll i = 0; i < n; ++i) {
        if(a[i] > 1) dp[a[i]] = max(dp[a[i]], dp[a[i] - 1] + 1);
        else dp[a[i]] = 1;
    }

    ll maxn = 0, cur = 0;
    for(ll i = 0; i < n; ++i) {
        if(dp[a[i]] > maxn) {
            maxn = dp[a[i]];
            cur = a[i];
        }
    }

    vector<ll> res;
    for(ll i = n - 1; i >= 0; --i) {
        if(cur == 0) break;
        if(a[i] == cur) {
            res.push_back(i + 1);
            cur--;
        }
    }

    reverse(res.begin(), res.end());

    cout << (ll)res.size() << '\n';
    for(ll i : res) cout << i << ' ';
    cout << '\n';

    return 0;
}