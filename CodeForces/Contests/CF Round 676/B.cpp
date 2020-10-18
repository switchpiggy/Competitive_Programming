#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, t;
char grid[207][207];
vector<pair<ll, ll>> ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;

    while(t--) {
        cin >> n;
        for(ll i = 0; i < n; ++i) {
            for(ll j = 0; j < n; ++j) cin >> grid[i][j];
        }

        ans.clear();
        if((grid[0][1] == '0' && grid[1][0] == '0') || (grid[0][1] == grid[1][0] && grid[1][0] == '1')) {
            if(grid[n - 1][n - 2] == grid[0][1]) ans.push_back({n - 1, n - 2});
            if(grid[n - 2][n - 1] == grid[0][1]) ans.push_back({n - 2, n - 1});
        } else {
            ll zero = 0, one = 0;
            if(grid[n - 2][n - 1] == '0') zero++;
            else one++;
            if(grid[n - 1][n - 2] == '0') zero++;
            else one++;

            char cur, cur2;
            if(zero >= one) {
                cur = '0';
                cur2 = '1';
            } else {
                cur = '1';
                cur2 = '0';
            }

            if(grid[n - 2][n - 1] != cur) ans.push_back({n - 2, n - 1});
            if(grid[n - 1][n - 2] != cur) ans.push_back({n - 1, n - 2});
            if(grid[1][0] != cur2) ans.push_back({1, 0});
            if(grid[0][1] != cur2) ans.push_back({0, 1}); 
        }

        cout << (ll)ans.size() << '\n';
        for(pair<ll, ll> x : ans) cout << x.first + 1 << ' ' << x.second + 1 << '\n';
    }

    return 0;
}