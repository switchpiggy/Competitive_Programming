#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, grid[2007][2007];
bool visited[2007][2007];
set<pair<pair<ll, ll>, pair<ll, ll>> blocked;
string s;

void floodfill(ll r, ll c) {

}

int main() {
    scanf("%lld", &n);
    cin >> s;

    ll x = 1000, y = 1000;
    for(ll i = 0; i < n; ++i) {
        if(s[i] == 'N') {
            blocked.insert(make_pair(make_pair(x - 1, y), make_pair(x, y)));
            x++;
        } else if(s[i] == 'S') {
            blocked.insert(make_pair(make_pair()))
        }
    }
}