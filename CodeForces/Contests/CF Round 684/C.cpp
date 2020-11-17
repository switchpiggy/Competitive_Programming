#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, m;
char grid[107][107];
vector<pair<ll, ll>> v;

void solve(ll x, ll y) {
    ll oneCount = 0;
    for(ll i = x; i <= x + 1; ++i) {
        for(ll j = y; j <= y + 1; ++j) if(grid[i][j] == '1') oneCount++;
    }

    //cout << oneCount << '\n';

    if(!oneCount) return;

    if(oneCount%3 == 2) {
        bool ok = 0;
        for(ll i = x; i <= x + 1; ++i) {
            for(ll j = y; j <= y + 1; ++j) {
                if(grid[i][j] == '1') {
                    oneCount--;
                    grid[i][j] = '0';
                    if(i == x && j == y) {
                        v.push_back({x, y});
                        v.push_back({x + 1, y});
                        v.push_back({x, y + 1});
                        //oneCount += (grid[x + 1][y] == '0') + (grid[x][y + 1] == '0');
                        grid[x + 1][y] = (1 - (grid[x + 1][y] - '0')) + '0';
                        grid[x][y + 1] = (1 - (grid[x][y + 1] - '0')) + '0';
                    } else if(i == x + 1 && j == y) {
                        v.push_back({x + 1, y});
                        v.push_back({x, y});
                        v.push_back({x + 1, y + 1});
                        //oneCount += (grid[x][y] == '0') + (grid[x + 1][y + 1] == '0');
                        grid[x][y] = (1 - (grid[x][y] - '0')) + '0';
                        grid[x + 1][y + 1] = (1 - (grid[x + 1][y + 1] - '0')) + '0';
                    } else if(i == x && j == y + 1) {
                        v.push_back({x + 1, y + 1});
                        v.push_back({x, y});
                        v.push_back({x, y + 1});
                        //oneCount += (grid[x][y] == '0') + (grid[x + 1][y + 1] == '0');
                        grid[x][y] = (1 - (grid[x][y] - '0')) + '0';
                        grid[x + 1][y + 1] = (1 - (grid[x + 1][y + 1] - '0')) + '0';
                    } else {
                        v.push_back({x + 1, y + 1});
                        v.push_back({x + 1, y});
                        v.push_back({x, y + 1});
                        //oneCount += (grid[x][y + 1] == '0') + (grid[x + 1][y] == '0');
                        grid[x + 1][y] = (1 - (grid[x + 1][y] - '0')) + '0';
                        grid[x][y + 1] = (1 - (grid[x][y + 1] - '0')) + '0';
                    }

                    ok = 1;
                    break;
                }
            }

            if(ok) break;
        }
    }

    oneCount = 0;
    for(ll i = x; i <= x + 1; ++i) {
        for(ll j = y; j <= y + 1; ++j) {
            if(grid[i][j] == '1') oneCount++;
        }
    }

    //cout << oneCount << ' ';

    if(oneCount%3 == 0) {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
        for(ll i = x; i <= x + 1; ++i) {
            for(ll j = y; j <= y + 1; ++j) {
                if(grid[i][j] == '1') {
                    v.push_back({i, j});
                    grid[i][j] = '0';
                }
            }
        }
    } else {
        if(oneCount == 4) {
            v.push_back({x, y});
            v.push_back({x + 1, y});
            v.push_back({x, y + 1});
            v.push_back({x + 1, y + 1});
            v.push_back({x + 1, y});
            v.push_back({x, y + 1});
            v.push_back({x, y});
            v.push_back({x + 1, y});
            v.push_back({x + 1, y + 1});
            v.push_back({x, y + 1});
            v.push_back({x, y});
            v.push_back({x + 1, y + 1});
        } else {
            if(grid[x + 1][y + 1] == '1') {
                v.push_back({x + 1, y + 1});
                v.push_back({x + 1, y});
                v.push_back({x, y + 1});
                v.push_back({x + 1, y + 1});
                v.push_back({x + 1, y});
                v.push_back({x, y});
                v.push_back({x, y + 1});
                v.push_back({x, y});
                v.push_back({x + 1, y + 1});
            } else if(grid[x][y] == '1') {
                v.push_back({x, y});
                v.push_back({x + 1, y});
                v.push_back({x, y + 1});
                v.push_back({x, y});
                v.push_back({x + 1, y});
                v.push_back({x + 1, y + 1});
                v.push_back({x, y + 1});
                v.push_back({x, y});
                v.push_back({x + 1, y + 1});
            } else if(grid[x + 1][y] == '1') {
                v.push_back({x + 1, y + 1});
                v.push_back({x + 1, y});
                v.push_back({x, y});
                v.push_back({x, y});
                v.push_back({x + 1, y});
                v.push_back({x, y + 1});
                v.push_back({x, y + 1});
                v.push_back({x + 1, y});
                v.push_back({x + 1, y + 1});
            } else {
                v.push_back({x + 1, y + 1});
                v.push_back({x, y});
                v.push_back({x, y + 1});
                v.push_back({x, y});
                v.push_back({x + 1, y});
                v.push_back({x, y + 1});
                v.push_back({x, y + 1});
                v.push_back({x + 1, y});
                v.push_back({x + 1, y + 1});
            }
        }
    }

    for(ll i = x; i <= x + 1; ++i) {
        for(ll j = y; j <= y + 1; ++j) grid[i][j] = '0';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        v.clear();
        cin >> n >> m;
        for(ll i = 1; i <= n; ++i) {
            for(ll j = 1; j <= m; ++j) cin >> grid[i][j]; 
        }

        for(ll i = 1; i < n; ++i) {
            for(ll j = 1; j < m; ++j) {
                solve(i, j);
            }
        }

        /*for(ll i = 1; i <= n; ++i, cout << '\n') {
            for(ll j = 1; j <= m; ++j) cout << grid[i][j] << ' ';
        }*/

        cout << (ll)v.size()/3 << '\n';
        for(ll i = 0; i < (ll)v.size(); i += 3) cout << v[i].first << ' ' << v[i].second << ' ' << v[i + 1].first << ' ' << v[i + 1].second << ' ' << v[i + 2].first << ' ' << v[i + 2].second << '\n';
    }

    return 0;
}