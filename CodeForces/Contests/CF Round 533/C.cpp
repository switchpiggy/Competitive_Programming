#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, l, r, dp[200007][3];
const ll MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l >> r; 
    ll zero = (r - l + 1)/3, one = (r - l + 1)/3, two = (r - l + 1)/3;
    for(ll i = l%3; i < l%3 + (r - l + 1)%3; ++i) {
        if(i%3 == 0) zero++;
        else if(i%3 == 1) one++;
        else two++;
    }

    dp[1][0] = zero, dp[1][1] = one, dp[1][2] = two;
    for(ll i = 2; i <= n; ++i) {
        dp[i][0] = (dp[i - 1][0] * zero) + (dp[i - 1][1] * two) + (dp[i - 1][2] * one);
        dp[i][1] = (dp[i - 1][0] * one) + (dp[i - 1][1] * zero) + (dp[i - 1][2] * two);
        dp[i][2] = (dp[i - 1][0] * two) + (dp[i - 1][1] * one) + (dp[i - 1][2] * zero);
        dp[i][0] %= MOD;
        dp[i][1] %= MOD;
        dp[i][2] %= MOD;
    }

    cout << dp[n][0] << '\n';
    return 0;
}