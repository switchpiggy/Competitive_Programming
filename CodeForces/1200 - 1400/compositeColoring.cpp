#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, c[1007];
vector<ll> ans[1007];

ll findPrime(ll x) {
    for(ll i = 2; i <= sqrt(x); ++i) {
        if(x%i == 0) return i;
    }
}

int main() {
    scanf("%lld", &t);

    while(t--) {
        scanf("%lld", &n);
        for(ll i = 1; i <= 1000; ++i) ans[i].clear();
        for(ll i = 1; i <= n; ++i) {
            ll temp;
            scanf("%lld", &temp);

            ans[findPrime(temp)].push_back(i);
        }

        ll count = 0;

        for(ll i = 1; i <= 1000; ++i) {
            if(ans[i].size()) {
            	count += 1;
                for(ll j = 0; j < ans[i].size(); ++j) {
                    c[ans[i][j]] = count;
                }
                
            }
        }

        printf("%lld\n", count);
        for(ll i = 1; i <= n; ++i) printf("%lld ", c[i]);
        printf("\n");
    }
}