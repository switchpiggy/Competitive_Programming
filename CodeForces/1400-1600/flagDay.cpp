#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a, b, c, ans[100007];

int main() {
    scanf("%lld %lld", &n, &m);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld %lld %lld", &a, &b, &c);
        bool ok[3] = {0, 0, 0};
        if(ans[a]) ok[ans[a] - 1] = 1;
        if(ans[b]) ok[ans[b] - 1] = 1;
        if(ans[c]) ok[ans[c] - 1] = 1;

        if(!ans[a]) for(ll j = 0; j < 3; ++j) {
            if(!ok[j]) {
                ans[a] = j + 1;
                ok[j] = 1;
                break;
            }
        }

        if(!ans[b]) for(ll j = 0; j < 3; ++j) {
            if(!ok[j]) {
                ans[b] = j + 1;
                ok[j] = 1;
                break;
            }
        }

        if(!ans[c]) {
            for(ll j = 0; j < 3; ++j) {
                if(!ok[j]) {
                    ans[c] = j + 1;
                    ok[j] = 1;
                    break;
                }
            }
        }
    }

    for(ll i = 1; i <= n; ++i) {
        printf("%lld ", ans[i]);
    }
    
    return 0;
}