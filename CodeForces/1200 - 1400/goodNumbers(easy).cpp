#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll q, n;

int main() {
    scanf("%lld", &q);

    for(ll que = 0; que < q; ++que) {
        scanf("%lld", &n);

        while(1) {
            ll cur = n;
            bool flag = false;

            while(cur > 0) {
                if(!flag && cur%3 == 2) flag = 1;
                cur /= 3;
            }

            if(!flag) break;
            n++;
        }

        printf("%lld\n", n);
    }
}