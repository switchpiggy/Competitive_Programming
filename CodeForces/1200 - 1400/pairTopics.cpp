#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[200007], b[200007], res;
vector<ll> diff;

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) scanf("%lld", &a[i]);
    for(ll i = 0; i < n; ++i) scanf("%lld", &b[i]);

    for(ll i = 0; i < n; ++i) diff.push_back(a[i] - b[i]);

    sort(diff.begin(), diff.end());

    for(ll i = 0; i < n; ++i) {
        ll low = lower_bound(diff.begin(), diff.end(), -1 * (diff[i]) + 1) - diff.begin();
        if(low < i) res += i - low;
    }

    printf("%lld\n", res);
    return 0;
}