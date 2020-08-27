#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, b[200007], c[200007];
map<ll, ll> cnt;

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        ll a;
        scanf("%lld", &a);
        cnt[a]++;
    }

    scanf("%lld", &m);
    for(ll i = 0; i < m; ++i) scanf("%lld", &b[i]);
    for(ll i = 0; i < m; ++i) scanf("%lld", &c[i]);

    pair<ll, ll> ans = make_pair(0, 0);
    ll index = 0;

    for(ll i = 0; i < m; ++i) {
        if(ans < make_pair(cnt[b[i]], cnt[c[i]])) {
            ans = make_pair(cnt[b[i]], cnt[c[i]]);
            index = i;
        }
    }

    printf("%lld\n", index + 1);
    return 0;
}