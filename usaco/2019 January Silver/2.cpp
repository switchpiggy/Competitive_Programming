#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, grid[1007][1007];
char temp;
bool visited[1007][1007];
ll dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};

pair<ll, ll> floodfill(ll x, ll y) {
    visited[x][y] = 1;
    pair<ll, ll> ans = make_pair(0, 0);
    for(ll i = 0; i < 4; ++i) {
        if((x + dx[i] >= n || x + dx[i] < 0 || y + dy[i] >= n || y + dy[i] < 0) || !grid[x + dx[i]][y + dy[i]]) ans.second++; 
        if(x + dx[i] >= n || x + dx[i] < 0 || y + dy[i] >= n || y + dy[i] < 0 || visited[x + dx[i]][y + dy[i]] || !grid[x + dx[i]][y + dy[i]]) continue;
        pair<ll, ll> p = floodfill(x + dx[i], y + dy[i]);
        ans.first += p.first;
        ans.second += p.second;
    }    

    ans.first++;
    return ans;
}

int main() {
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);

    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            cin >> temp;
            if(temp == '#') grid[i][j] = 1;
        }
    }

    pair<ll, ll> res;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) {
            if(visited[i][j] || !grid[i][j]) continue;
            pair<ll, ll> cur = floodfill(i, j);

            if(cur.first > res.first) {
                res.first = cur.first;
                res.second = cur.second;
            } else if(cur.first == res.first) res.second = min(res.second, cur.second);
        }
    }

    printf("%lld %lld\n", res.first, res.second);
    return 0;
}