#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[200005], total = 0;

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
        total += a[i];
    }

    ll sum = 0;
    for(ll i = 0; i < n; ++i) {
        sum += a[i];
        if(sum >= (total + 1)/2) {
            printf("%lld", i + 1);
            return 0;
        }
    }
}