#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, res[100007];

int main() {
    scanf("%lld %lld", &n, &m);
    if(m%2 == 1) {
        ll cur = m/2;
        for(ll i = 2; i <= m; i += 2) {
            res[i] = cur;
            cur--;
        }
        cur = m/2 + 1;
        for(ll i = 1; i <= m; i += 2) {
            res[i] = cur;
            cur++;
        }
    } else {
        ll cur = m/2;
        for(ll i = 1; i <= m; i += 2) {
            res[i] = cur;
            cur--;
        }
        cur = m/2 + 1;
        for(ll i = 2; i <= m; i += 2) {
            res[i] = cur;
            cur++;
        }
    }

    for(ll i = 1, j = 1; i <= n; ++i, ++j) {
    	if(j == m + 1) j = 1;
        printf("%lld\n", res[j]);
    }

    return 0;
}