#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, ans[2000010];

int main() {
    scanf("%lld", &n);

    ll temp;
    for(ll i = 0; i < n; ++i) {
        scanf("%lld", &temp);
        ans[temp]++;
    }
    ll res = 0;
    for(ll i = 0; i <= 2000007; ++i) {
        if(!ans[i]) continue;
        ans[i + 1] += ans[i]/2;
        ans[i] %= 2;
        res += ans[i];
    }

    printf("%lld\n", res);
    return 0;
}