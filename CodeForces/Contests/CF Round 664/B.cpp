#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, sx, sy;
bool v[107][107];

int main() {
    scanf("%lld %lld %lld %lld", &n, &m, &sx, &sy);


    ll pos = 1;
    printf("%lld %lld\n", sx, sy);
    v[sx][sy] = 1;
    if(!v[1][sy]) printf("1 %lld\n", sy);
    v[1][sy] = 1;
    if(!v[1][1]) printf("1 1\n");
    v[1][1] = 1;
    for(ll i = 1; i <= n; ++i) {
        if(pos == 1) {
            for(ll j = 1; j <= m; ++j) {
                if(!v[i][j]) printf("%lld %lld\n", i, j);
                v[i][j] = 1;
            }
        } else {
            for(ll j = m; j >= 1; --j) {
                if(!v[i][j]) printf("%lld %lld\n", i, j);
                v[i][j] = 1;
            }
        }

        pos = 1 - pos;
    }

    return 0;
}