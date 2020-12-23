#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a, b, k, f, dp[307][307], sum[307];
map<pair<string, string>, ll> id;
pair<string, string> p;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> a >> b >> k >> f;
    ll num = 1;
    for(ll i = 0; i < n; ++i) {
        string s, t;
        cin >> s >> t;
        ll cur = ((i && p.second == s) ? b : a);
        if(!id[{t, s}] && !id[{s, t}]) id[{s, t}] = id[{t, s}] = num++;
        sum[id[{s, t}]] += cur;
        p.first = s, p.second = t;
    }

    for(ll i = 0; i <= num; ++i) {
        for(ll j = 0; j <= k; ++j) dp[i][j] = INT_MAX;
    }
    
    dp[0][0] = 0;

    for(ll i = 0; i < num; ++i) {
        for(ll j = 0; j <= k; ++j) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + sum[i + 1]);
            if(j + 1 <= k) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + f);
        }
    }

    ll ans = LLONG_MAX;
    for(ll i = 0; i <= k; ++i) ans = min(ans, dp[num][i]);
    cout << ans << '\n';
    return 0;
}