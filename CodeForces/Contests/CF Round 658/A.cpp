#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, m;
map<ll, bool> taken;

int main() {
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld %lld", &n, &m);
        taken.clear();
        for(ll i = 0; i < n; ++i) {
            ll temp;
            scanf("%lld", &temp);
            taken[temp] = 1;
        }

        bool ok = 0;
        for(ll i = 0; i < m; ++i) {
            ll temp;
            scanf("%lld", &temp);
            if(taken[temp] && !ok) {
                ok = 1;
                printf("YES\n1 %lld\n", temp);
            }
        }

        if(!ok) {
            printf("NO\n");
        }
    }

    return 0;
}