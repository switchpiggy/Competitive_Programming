#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, a, b, n;

int main() {
    scanf("%lld", &t);

    while(t--) {
        scanf("%lld %lld %lld", &a, &b, &n);
        ll count = 0;

        while(a <= n && b <= n) {
            if(a <= b) a += b;
            else b += a;

            count++;
        }

        printf("%lld\n", count);
    }
}