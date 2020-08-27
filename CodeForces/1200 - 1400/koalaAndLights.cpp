#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[107], b[107];
string s;

int main() {
    scanf("%lld", &n);
    cin >> s;

    for(ll i = 0; i < n; ++i) scanf("%lld %lld", &a[i], &b[i]);

    ll ans = 0;
    for(ll i = 0; i < 1007; ++i) {
        ll sum = 0;
        for(ll j = 0; j < n; ++j) {
            if(i >= b[j] && (i - b[j])%a[j] == 0) {
                if(s[j] == '0') s[j] = '1';
                else s[j] = '0';
            }
            if(s[j] == '1') sum++;
        }
        ans = max(ans, sum);
    }

    printf("%lld\n", ans);


}