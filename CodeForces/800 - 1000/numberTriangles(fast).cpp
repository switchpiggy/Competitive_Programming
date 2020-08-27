/*
ID: alanxia1
PROG: numtri
LANG: C++
*/



#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<ll> vi;

ll r;

ll best[1005], old[1005];

int main() {
    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w", stdout);

    scanf("%lld", &r);
    for(ll i = 1; i <= r; ++i) {
        memmove(old, best, sizeof(old));
        for(ll j = 1; j <= i; ++j) {
            ll temp;
            scanf("%lld", &temp);
            if(j == 1) best[j] = old[j] + temp;
            else best[j] = max(old[j - 1], old[j]) + temp;
        }
    }

    ll res = INT_MIN;

    for(ll i = 1; i <= r; ++i) {
        res = max(res, best[i]);
    }

    printf("%lld\n", res);
}