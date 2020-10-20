#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, grid[1007][1007];
set<ll> rows[1007];
set<ll> cols[1007];
vector<ll> row[1007];
vector<ll> col[1007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= m; ++j) cin >> grid[i][j];
    }

    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= m; ++j) {
            rows[i].insert(grid[i][j]);
            cols[j].insert(grid[i][j]);
        }
    }

    for(ll i = 1; i <= n; ++i) {
        for(auto j : rows[i]) row[i].push_back(j);
    } 

    for(ll j = 1; j <= m; ++j) {
        for(auto i : cols[j]) col[j].push_back(i);
    }

    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= m; ++j) {
            ll f1 = lower_bound(row[i].begin(), row[i].end(), grid[i][j]) - row[i].begin();
            ll f2 = lower_bound(col[j].begin(), col[j].end(), grid[i][j]) - col[j].begin();

            cout << max(f1, f2) + max((ll)col[j].size() - f2, (ll)row[i].size() - f1) << ' ';
        }

        cout << '\n';
    }

    return 0;
}