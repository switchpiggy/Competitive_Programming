#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
ll occ[26], dp[27][27];

int main() {
    cin >> s;

    for(ll i = 0; i < s.length(); ++i) {
        ll cur = s[i] - 'a';
        for(ll j = 0; j < 26; ++j) {
            dp[j][cur] += occ[j];
        }
        occ[cur]++;
    }

    ll ans = 0;
    for(ll i = 0; i < 26; ++i) ans = max(ans, occ[i]);

    for(ll i = 0; i < 26; ++i) {
        for(ll j = 0; j < 26; ++j) {
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << endl;
    return 0;
}