#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll q, n, r[300007], l[300007], dp[300007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> n;
        vector<ll> v;

        for(ll i = 1; i <= n; ++i) {
            l[i] = LLONG_MAX;
            r[i] = LLONG_MIN;
            dp[i] = 0;
        }

        for(ll i = 0; i < n; ++i) {
            ll a;
            cin >> a;
            v.push_back(a);
            l[a] = min(l[a], i);
            r[a] = max(r[a], i);
        }

        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        dp[(ll)v.size() - 1] = 1;
        ll maxn = 1;
        for(ll i = (ll)v.size() - 2; i >= 0; --i) {
            if(l[v[i + 1]] > r[v[i]]) dp[i] = dp[i + 1] + 1;
            else dp[i] = 1;
            maxn = max(maxn, dp[i]);
        }

        cout << (ll)v.size() - maxn << '\n';
    }

    return 0;
}