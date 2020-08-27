#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, s, f, t;

int main() {
    scanf("%lld %lld", &n, &m);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld %lld %lld", &s, &f, &t);

        ll cur;

        if(s == f) {
            printf("%lld\n", t);
            continue;
        } else if(s < f) cur = s - 1;
        else cur = (m - 1) + (m - s);

        while(cur < t) cur += 2 * m - 2;

        printf("%lld\n", cur + abs(s - f));
    }

    return 0;
}