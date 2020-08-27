#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll dr[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
ll dc[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
vector<string> initState(8);

bool dfs(ll r, ll c, ll step) {
    if(step > 8) return 1;

    for(ll i = 0; i <= 8; ++i) {
        ll row = r + dr[i];
        ll col = c + dc[i];
        if(row < 0 || row >= 8 || col < 0 || col >= 8) continue;
        if(row >= step && initState[row - step][col] == 'S') continue;
        if(row > step && initState[row - step - 1][col] == 'S') continue;
        if(dfs(row, col, step + 1)) return 1;
    }
    
    return 0;
}

int main() {
    for(ll i = 0; i < 8; ++i) cin >> initState[i];
    if(dfs(7, 0, 0)) printf("WIN");
    else printf("LOSE");
}