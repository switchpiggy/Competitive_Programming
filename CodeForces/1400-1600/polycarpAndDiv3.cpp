#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
ll dp[200007], fin[3], pref[200007];

int main() {
    cin >> s;
    ll n = (ll)s.length();

    fin[1] = fin[2] = -1;
    fin[0] = 0;

    for(ll i = 0; i < n; ++i) pref[i] = s[i] - '0';
    for(ll i = 1; i < n; ++i) pref[i] += pref[i - 1];

    dp[0] = 0;
    for(ll i = 1; i <= n; ++i) {
        ll cur = pref[i - 1]%3;
        dp[i] = dp[i - 1];
        if(fin[cur] != -1) {
            dp[i] = max(dp[i], dp[fin[cur]] + 1);
        }

        fin[cur] = i;
    } 
    
    cout << dp[n] << '\n';

    return 0;
}