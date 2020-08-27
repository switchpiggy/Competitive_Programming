#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a[5005], cnt[5005], temp = 0, ans[5005];
ll maxs = 0;

int main() {
    scanf("%lld %lld", &n, &k);
    for(int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        cnt[a[i]]++;
        maxs = max(maxs, a[i]);
    }

    for(ll i = 1; i <= maxs; ++i) {
        if(cnt[i] > k) {
            printf("NO");
            return 0;
        }
        for(ll j = 1; j <= n; ++j) {
            if(a[j] == i) ans[j] = ++temp;
            if(temp >= k) temp -= k;
        }
    }

    printf("YES\n");
    for(ll i = 1; i <= n; ++i) {
        printf("%lld ", ans[i]);
    }
    
}