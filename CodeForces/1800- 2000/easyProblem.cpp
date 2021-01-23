#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define benq queue
#define pbenq priority_queue
#define all(x) (x.begin(), x.end())
ll n, a[100007], dp[100007][5];
string s;
string t = "hard";

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    //dp[0][0] = 0;
    for(ll i = 0; i <= n; ++i) {
        for(ll j = 0; j < 4; ++j) dp[i][j] = LLONG_MAX;
    }

    dp[0][0] = 0;

    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < 4; ++j) {
            if(dp[i][j] == LLONG_MAX) continue;
            if(s[i] == t[j]) {
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + a[i]);
            } else {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            }
        }
    }

    cout << min({dp[n][0], dp[n][1], dp[n][2], dp[n][3]}) << '\n';
    return 0;
}