#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[300007];

int main() {
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld", &n);
        for(ll i = 0; i < n; ++i) scanf("%lld", &a[i]);

        if(a[0] < a[n - 1]) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}