#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, x, p[200007];

int main() {
    scanf("%lld", &t);

    while(t--) {
        string ans = "";

        scanf("%lld", &n);
        for(ll i = 0; i < n; ++i) {
            scanf("%lld", &x);
            p[x - 1] = i;
        }

        ll l = n, r = 0;
        for(ll i = 0; i < n; ++i) {
            l = min(l, p[i]);
            r = max(r, p[i]);
            if(r - l == i) {
                ans += '1';
            } else ans += '0';
        }

        cout << ans << endl;
    }
}