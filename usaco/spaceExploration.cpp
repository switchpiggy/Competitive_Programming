#include <iostream>
using namespace std;

typedef long long int ll;
ll n, cnt = 0;
char grid[1007][1007];

ll dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};

void floodfill(ll r, ll c) {
    queue<pair<ll, ll>> q;
    q.push(make_pair(r, c));

    while(!q.empty()) {
        pair<ll, ll> f = q.front();
        q.pop();
        grid[f.first][f.second] = '.';  

        for(ll i = 0; i < 4; ++i) {
            if(f.first + dx[i] < 0 || f.second + dy[i] < 0 || f.first + dx[i] >= n || f.second + dy[i] >= n || grid[f.first + dx[i]][f.second + dy[i]] == '*') q.push(make_pair(f.first + dx[i], f.second + dy[i]));
        }
    }
}

int main() {
    scanf("%lld\n", &n);
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) cin >> grid[i][j];
    }

    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            if(grid[i][j] == '*') {
                cnt++;
                floodfill(i, j);
            }
        }
    }

    printf("%lld\n", cnt);

    return 0;
}