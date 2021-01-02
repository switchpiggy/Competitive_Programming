#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benqueue queue

ll n, t, z, zz, a[4007][4007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> t;

    benqueue<pair<ll, ll>> ben;
    a[2000][2000] = n;
    ben.push({0, 0});

    while(!ben.empty()) {
        pair<ll, ll> p = ben.front();
        ben.pop();

        ll x = p.first, y = p.second;
        //cout << x << ' ' << y << '\n';
        ll cnt = a[x + 2000][y + 2000]/4;
        if(!cnt) continue;
        
        a[x + 2000][y + 2000] -= 4 * cnt;
        a[x + 1 + 2000][y + 2000] += cnt;
        a[x - 1 + 2000][y + 2000] += cnt; 
        a[x + 2000][y + 1 + 2000] += cnt; 
        a[x + 2000][y - 1 + 2000] += cnt;
        
        ben.push({x + 1, y});
        ben.push({x - 1, y});
        ben.push({x, y - 1});
        ben.push({x, y + 1});
    }

    for(ll i = 0; i < t; ++i) {
        cin >> z >> zz;
        cout << ((z >= -2000 && z <= 2000 && zz <= 2000 && zz >= -2000) ? a[z + 2000][zz + 2000] : 0) << '\n';
    }

    return 0;
}