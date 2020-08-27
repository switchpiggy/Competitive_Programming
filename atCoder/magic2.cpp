#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b, c, k;

int main() {
    scanf("%lld %lld %lld %lld", &a, &b, &c, &k);
    ll cnt = 0;
    while(cnt < k && b <= a) {
        b *= 2;
        cnt++;
    }

    while(cnt < k && c <= b) {
        c *= 2;
        cnt++;
    }

    if(a < b && b < c) printf("Yes\n");
    else printf("No\n");

    return 0;
}