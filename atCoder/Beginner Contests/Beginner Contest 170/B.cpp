#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll x, y;

int main() {
    scanf("%lld %lld", &x, &y);
    for(ll i = 0; i <= x && i <= y/4; ++i) {
        ll cur = x - i;
        if(i * 4 + cur * 2 == y) {
            printf("Yes\n");
            return 0;
        }
    }

    printf("No\n");
    return 0;
}