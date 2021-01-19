#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
multiset<ll> s;
ll dp[100007];
ll n, c, a[100007], pref[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);    
    cin >> n >> c;
    for(ll i = 1; i <= n; ++i) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    
    dp[0] = 0;
    for(ll i = 1; i <= n; ++i) dp[i] = LLONG_MAX;
    for(ll i = 1; i <= n; ++i) {
        s.insert(a[i]);
        if((ll)s.size() > c) {
            s.erase(s.find(a[i - c]));
        }

        dp[i] = min(dp[i], dp[i - 1] + a[i]);
        if(i >= c) dp[i] = min(dp[i], dp[i - c] + pref[i] - pref[i - c] - *s.begin());
    }

    cout << dp[n] << '\n';
    return 0;
}