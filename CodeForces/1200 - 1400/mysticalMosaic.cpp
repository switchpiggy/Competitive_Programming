#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, grid[57][57];
char temp;

int main() {
    scanf("%lld %lld", &n, &m);
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < m; ++j) {
            scanf(" %c", &temp);
            if(temp == '#') grid[i][j] = 1;
            else grid[i][j] = 0;
        }
    }

    for(ll i = 0; i < n - 1; ++i) {
        for(ll j = i + 1; j < n; ++j) {
            bool same = 1, intersect = 0;
            for(ll k = 0; k < m; ++k) {
                if(grid[i][k] != grid[j][k]) same = 0;
                if(grid[i][k] && grid[j][k]) intersect = 1;
            }

            if(intersect && !same) {
                printf("No\n");
                return 0;
            }
        }
    }

    printf("Yes\n");

    return 0;
}