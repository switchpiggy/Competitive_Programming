#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

ll n;
ld dp[3007];

int main() {
    memset(dp, 0.0, sizeof(dp));
    cin >> n;

    dp[0] = 1;
    for(ll i = 0; i < n; ++i) {
        ld temp;
        cin >> temp;

        for(ll j = i + 1; j >= 0; --j) {
            if(j == 0) dp[j] = dp[j] * (1.0 - temp);
            else dp[j] = dp[j - 1] * temp + dp[j] * (1.0 - temp);
        }
    }

    //for(ll i = 0; i <= n; ++i) cout << dp[i] << ' ';

    ld ans = 0;
    for(ll i = 0; i <= n; ++i) {
        if(i > n - i) ans += dp[i];
    }

    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}