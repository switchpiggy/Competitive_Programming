#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll h, w, k, row[7], col[7], ans, black;
char grid[7][7];

int main() {
    scanf("%lld %lld %lld", &h, &w, &k);
    for(ll i = 0; i < h; ++i) {
        for(ll j = 0; j < w; ++j) {
            cin >> grid[i][j];
            if(grid[i][j] == '#') {
                row[i]++;
                col[j]++;
                black++;
            }
        }
    }

    for(ll r = 0; r <= (1 << h) - 1; ++r) {
        ll sum = 0;
        for(ll i = 0; i < h; ++i) {
            if(r & (1 << i)) {
                sum += row[i];
                //cout << i << ' ';
            }
        }

        //cout << endl;

        for(ll c = 0; c <= (1 << w) - 1; ++c) {
            ll sum2 = 0;
            for(ll i = 0; i < w; ++i) {
                if(c & (1 << i)) {
                    //cout << i << ' ';
                    sum2 += col[i];
                }
            }

            //cout << endl;

           for(ll i = 0; i < w; ++i) {
                for(ll j = 0; j < h; ++j) {
                    if((r & (1 << j)) && (c & (1 << i)) && grid[j][i] == '#') sum2--;
                }
            }

            if(black - (sum + sum2) == k) ans++;
        }


    }

    printf("%lld\n", ans);
    return 0;
}