#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll x, y;
map<pair<ll, ll>, ll> dp;

ll solve(ll x, ll y) {
    if(dp[{x, y}]) return dp[{x, y}];
    if(x >= y) return x - y;
    if(y%2 == 0) return dp[{x, y}] = min(y - x, 1 + solve(x, y/2));
    return dp[{x, y}] = min(y - x, min(2 + solve(x, y/2), 2 + solve(x, (y + 1)/2)));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> x >> y;
    
    cout << solve(x, y) << '\n';
    return 0;
}