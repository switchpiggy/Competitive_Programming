#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, k;
string s;

int main() {
    scanf("%lld", &t);

    while(t--) {
        scanf("%lld %lld", &n, &k);
        cin >> s;

        ll dist = k, ans = 0;

        for(ll i = 0; i < n; ++i) {
            if(s[i] == '1') {
                if(dist < k) ans--;
                dist = 0;
            } else {
                dist++;
                if(dist == k + 1) {
                    ans++;
                    dist = 0;
                }
            }
        }

        printf("%lld\n", ans);
    }
}