#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a, b, pref[1000007];

int main() {
    scanf("%lld %lld", &n, &k); 
    for(ll i = 0; i < k; ++i) {
        scanf("%lld %lld", &a, &b);
        pref[a - 1]++;
        pref[b]--;
    }
    for(ll i = 1; i < n; ++i) pref[i] += pref[i - 1];

    sort(pref, pref + n);

    printf("%lld\n", pref[(n + 1)/2 - 1]);

    return 0;
}