#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll p, x, y, s;

int main() {
    scanf("%lld %lld %lld", &p, &x, &y);

    for(ll s = y; ; ++s) {
        if(s%50 != x%50) continue;

        ll i = (s/50)%475;
        bool flag = false;

        for(ll j = 0; j < 25; ++j) {
            i = (i * 96 + 42)%475;
            if(i + 26 == p) {
                flag = 1;
                break;
            }
        }

        if(flag) {
            printf("%lld\n", (max(0ll, s - x) + 50)/100);
            return 0;
        }
    }

    return 0;
}