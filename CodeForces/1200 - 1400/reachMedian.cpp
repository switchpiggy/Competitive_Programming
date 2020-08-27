#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, s;

int main() {
    scanf("%lld %lld", &n, &s);
    vector<ll> a(n);

    for(ll i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }

    sort(a.begin(), a.end());

    ll pre = 0, suf = 0;

    for(ll i = 0; i < n/2; ++i) {
        if(a[i] > s) pre += a[i] - s;
    }

    for(ll i = n - 1; i > n/2; --i) {
        if(a[i] < s) suf += s - a[i];
    }

    printf("%lld\n", suf + pre + abs(a[n/2] - s));

    return 0;
}