#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b, c;
long double dp[107][107][107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> c;
    cout << fixed << setprecision(12);
    for(ll i = 100; i >= 0; --i) {
        for(ll j = 100; j >= 0; --j) {
            for(ll k = 100; k >= 0; --k) {
                if(i == 100 || j == 100 ||k == 100) {
                    dp[i][j][k] = 0;
                    continue;
                }

                dp[i][j][k] = (i/(long double)(i + j + k)) * (dp[i + 1][j][k] + 1) + (j/(long double)(i + j + k)) * (dp[i][j + 1][k] + 1) + (k/(long double)(i + j + k)) * (dp[i][j][k + 1] + 1);
            }
        }
    }

    cout << dp[a][b][c] << '\n';
    return 0;
}