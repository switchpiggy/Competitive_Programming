#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll h, w, dp[2007][2007];
char s[2007][2007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> h >> w;
    for(ll i = 1; i <= h; ++i) {
        for(ll j = 1; j <= w; ++j) cin >> s[i][j];
    }

    dp[1][1] = 1;
    for(ll i = 1; i <= h; ++i) {
        for(ll j = 1; j <= w; ++j) {
            if(s[i][j] == '#') continue;
            
        }

        //cout << '\n';
    }

    cout << dp[h][w] << '\n';
    return 0;
}