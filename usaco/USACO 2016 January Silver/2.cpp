#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[50007], pref[50007], last[7], ans = 0;

int main() {
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    scanf("%lld", &n);
    for(ll i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        a[i] %= 7;
    }

    memset(last, -1, sizeof(last));

    for(ll i = 1; i <= n; ++i) pref[i] = (pref[i - 1] + a[i])%7;

    for(ll i = 1; i <= n; ++i) {
        if(last[pref[i]] != -1) {
            //cout << last[pref[i]] << ' ' << i << endl;
            ans = max(ans, i - last[pref[i]]);
        } else {
            last[pref[i]] = i;
        }
    }

    printf("%lld\n", ans);
    return 0;
}