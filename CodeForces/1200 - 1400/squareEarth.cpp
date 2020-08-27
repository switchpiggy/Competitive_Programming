#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x1, y, x2, y2;

int main() {
    scanf("%lld %lld %lld %lld %lld", &n, &x1, &y, &x2, &y2);
    if(abs(x1 - x2) == n) {
        printf("%lld\n", n + min(y + y2, 2 * n - (y + y2)));
    } else if(abs(y- y2) == n) {
        printf("%lld\n", n + min(x1 + x2, 2 * n - (x1 + x2)));
    } else printf("%lld\n", abs(x1 - x2) + abs(y - y2));
}