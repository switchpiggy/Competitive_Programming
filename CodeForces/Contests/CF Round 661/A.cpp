#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[57], t;

int main() {
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld", &n);
        for(ll i = 0; i < n; ++i) scanf("%lld", &a[i]);
        sort(a,a + n);
        bool ok = 0;
        for(ll i = 0; i < n - 1; ++i) {
            if(a[i + 1] - a[i] > 1) {
                printf("NO\n");
                ok = 1;
                break;
            }
        }

        if(!ok) printf("YES\n");
    }

    return 0;
}