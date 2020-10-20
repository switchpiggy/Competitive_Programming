#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;
typedef long long int ll;
int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    ll ar[n][m];
    for (ll i = 0; i < n; i ++) {
        for (ll j = 0; j < m ; j ++) {
            cin >> ar[i][j];
        }
    }
    ll mod[n][k];
    for (ll i = 0; i < n; i ++) {
        for (ll j = 0; j < k; j ++) {
            mod[i][j] = -100000000;
        }
    }
    mod[0][0] = 0;
    for (ll i = 0; i < n; i ++) {
        for (ll j = 0; j < m; j ++) {
            mod[i][ar[i][j]%k] = max(mod[i][ar[i][j]%k], ar[i][j]);
            for (ll l = j + 1; l < m; l ++) {
                mod[i][(ar[i][j] + ar[i][l])%k] = max(mod[i][(ar[i][j] + ar[i][l])%k], (ar[i][j] + ar[i][l]));
            }
        }
    }
    for (int i = 1; i < n; i ++) {
        for (int j = 0; j < k; j ++) {
            mod[i][j] = max(mod[i][j],mod[i-1][j]);
        }
    }
    ll dp[n][k];
    for (ll i = 0; i < n; i ++) {
        for (ll j = 0; j < k; j ++) {
            dp[i][j] = -100000000;
        }
    }
    for (ll i = 0; i < k; i ++) {
        dp[0][i] = mod[0][i];
    }
    for (ll i = 1; i < n; i ++) {
        for (ll j = 0; j < k; j ++) {
            for (ll l = 0; l < k; l ++) {
                if (dp[i-1][j] != -100000000 && mod[i][l] != -100000000)
                dp[i][(j+l)%k] = max(dp[i][(j+l)%k], dp[i-1][j] + mod[i][l]);
                
            }
        }
    }
    cout << max((ll)0, dp[n-1][0]) << endl;
    // for (ll i = 0; i < n; i ++) {
    //     for (ll j = 0; j < k; j ++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}