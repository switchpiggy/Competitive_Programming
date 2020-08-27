#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[1007], sum;

bool cmp(ll x, ll y) {
    return a[x] < a[y];
}

int main() {
    scanf("%lld", &n);
    for(ll i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        sum += a[i];
    }

    if(sum%n != 0) {
        printf("Unrecoverable configuration.");
        return 0;
    } else sum /= n;

    vector<ll> diff;
    for(ll i = 1; i <= n; ++i) {
        if(a[i] != sum) diff.push_back(i);
    }

    if(diff.size() == 0) {
        printf("Exemplary pages.");
        return 0;
    } else if(diff.size() == 1 || diff.size() > 2) {
        printf("Unrecoverable configuration.");
        return 0;
    }

    sort(diff.begin(), diff.end(), cmp);
    printf("%lld ml. from cup #%lld to cup #%lld.", abs(a[diff[1]] - sum), diff[0], diff[1]);

    return 0;
}