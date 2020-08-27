#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, pos, l, r;

int main() {
    scanf("%lld %lld %lld %lld", &n, &pos, &l, &r);

    if(l == 1 && r == n) {
        printf("0\n");
    } else if(l == 1) {
        printf("%lld\n", abs(r - pos) + 1);
    } else if(r == n) {
        printf("%lld\n", abs(pos - l) + 1);
    } else {
        ll ans = 0;
        ans += min(abs(r - pos), abs(pos - l));
        ans += r - l;

        printf("%lld\n", ans + 2);
    }
}