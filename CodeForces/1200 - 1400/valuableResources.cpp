#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a, b, minX = INT_MAX, maxX = INT_MIN, minY = INT_MAX, maxY = INT_MIN;

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld %lld", &a, &b);
        minY = min(minY, b);
        maxY = max(maxY, b);
        minX = min(minX, a);
        maxX = max(maxX, a);
    }
    
    ll ans = max(abs(maxX - minX), abs(maxY - minY));

    printf("%lld\n", ans * ans);

    return 0;
}