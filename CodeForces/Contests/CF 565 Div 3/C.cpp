#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, dp[7];
vector<ll> v;
map<ll, ll> pos;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    pos[4] = 1, pos[8] = 2, pos[15] = 3, pos[16] = 4, pos[23] = 5, pos[42] = 6;

    cin >> n;
    for(ll i = 0; i < n; ++i) {
        ll temp;
        cin >> temp;
        v.push_back(pos[temp]);
    }

    if(v[0] == 1) dp[1] = 1;
    for(ll i = 1; i < (ll)v.size(); ++i) {

        if(v[i] == 1) {
            dp[1]++;
        } else if(dp[v[i] - 1]) {
            dp[v[i]]++;
            dp[v[i] - 1]--;
        }
    }

    /*for(ll i = 0; i < (ll)v.size(); ++i) {
        for(ll j = 1; j <= 6; ++j) {
            cout << dp[i][j] << ' ';
        }

        cout << '\n';
    } */

    cout << n - 6 * dp[6] << '\n';
    return 0;
}