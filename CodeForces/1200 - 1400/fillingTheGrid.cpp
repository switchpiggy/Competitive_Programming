#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll w, h;
ll reserved[1007][1007];

const ll MOD = 1000000007;

void no() {
    printf("0\n");
    exit(0);
}

int main() {
    scanf("%lld %lld", &h, &w);
    for(ll i = 1; i <= h; ++i) {
    	ll r;
        scanf("%lld", &r);
        for(ll j = 1; j <= r; ++j) reserved[i][j] = 1;
        reserved[i][r + 1] = -1;
    }

    for(ll i = 1; i <= w; ++i) {
    	ll c;
        scanf("%lld", &c);
        for(ll j = 1; j <= c; ++j) {
            if(reserved[j][i] == -1) no();
            reserved[j][i] = 1;
        }
        if(reserved[c + 1][i] == 1) no();
        reserved[c + 1][i] = -1;
    }

	ll res = 1;
    for(ll i = 1; i <= h; ++i) {
        for(ll j = 1; j <= w; ++j) if(reserved[i][j] == 0) res = (res << 1)%MOD;
    }

    printf("%lld\n", res%MOD);
    return 0;
}