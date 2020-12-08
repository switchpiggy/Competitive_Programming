#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, fx, fy, bx, by, dp[1007][1007];
string s, t;
vector<pair<ll, ll>> pf, pb;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("radio.in", "r", stdin);
    freopen("radio.out", "w", stdout);
    cin >> n >> m >> fx >> fy >> bx >> by >> s >> t;
    pf.push_back({fx, fy});
    pb.push_back({bx, by});

    for(ll i = 0; i < n; ++i) {
        if(s[i] == 'N') fy++;
        else if(s[i] == 'S') fy--;
        else if(s[i] == 'E') fx++;
        else fx--;
        pf.push_back({fx, fy});
    } 

    for(ll i = 0; i < m; ++i) {
        if(t[i] == 'N') by++;
        else if(t[i] == 'S') by--;
        else if(t[i] == 'E') bx++;
        else bx--;
        pb.push_back({bx, by});
    }

    for(ll i = 0; i <= n; ++i) {
        for(ll j = 0; j <= m; ++j) dp[i][j] = INT_MAX;
    }

    //for(ll i = 0; i <= n; ++i) cout << pf[i].first << ' ' << pf[i].second << '\n';
    //for(ll i = 0; i <= m; ++i) cout << pb[i].first << ' ' << pb[i].second << '\n';

    dp[0][0] = 0;

    for(ll i = 0; i <= n; ++i) {
        for(ll j = 0; j <= m; ++j) {
            if(i + 1 <= n && j + 1 <= m) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + (pf[i + 1].first - pb[j + 1].first) * (pf[i + 1].first - pb[j + 1].first) + (pf[i + 1].second - pb[j + 1].second) * (pf[i + 1].second - pb[j + 1].second));
            if(i + 1 <= n) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + (pf[i + 1].first - pb[j].first) * (pf[i + 1].first - pb[j].first) + (pf[i + 1].second - pb[j].second) * (pf[i + 1].second - pb[j].second));
            if(j + 1 <= m) dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + (pf[i].first - pb[j + 1].first) * (pf[i].first - pb[j + 1].first) + (pf[i].second - pb[j + 1].second) * (pf[i].second - pb[j + 1].second));
        }
    }

    /*for(ll i = 0; i <= n; ++i, cout << '\n') {
        for(ll j = 0; j <= m; ++j) cout << dp[i][j] << ' ';
    }*/

    cout << dp[n][m] << '\n';
    return 0;
}