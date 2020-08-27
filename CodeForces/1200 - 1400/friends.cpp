#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
bool adj[7][7];

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        ll x, y;
        scanf("%lld %lld", &x, &y);
        adj[x][y] = adj[y][x] = 1;
    }

    for(ll i = 1; i <= 5; ++i) {
        for(ll j = i + 1; j <= 5; ++j) {
            for(ll k = j + 1; k <= 5; ++k) {
                if((adj[i][j] && adj[j][k] && adj[k][i]) || (!adj[i][j] && !adj[j][k] && !adj[k][i])) {
                    printf("WIN\n");
                    return 0;
                }
            }
        }
    }

    printf("FAIL\n");
    return 0;
}