#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, c[100007], dp[100007][2];
vector<string> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> c[i];
    }

    for(ll i = 0; i <= n; ++i) dp[i][0] = dp[i][1] = LLONG_MAX;
    dp[0][0] = 0;

    for(ll i = 0; i < n; ++i) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    string prev = "", prevrev = "";
    for(ll i = 0; i < n; ++i) {
        string cur = v[i], rev = v[i];
        reverse(rev.begin(), rev.end());
        if(cur >= prev) dp[i + 1][0] = min(dp[i + 1][0], dp[i][0]);
        if(rev >= prev) dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + c[i]);
        if(rev >= prevrev) dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + c[i]);
        if(cur >= prevrev) dp[i + 1][0] = min(dp[i + 1][0], dp[i][1]);
        prevrev = rev;
        prev = cur;
    }

    if(dp[n][0] == LLONG_MAX && dp[n][1] == LLONG_MAX) cout << "-1\n";
    else cout << min(dp[n][0], dp[n][1]) << '\n';
    return 0;
}