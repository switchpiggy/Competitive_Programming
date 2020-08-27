#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, brand[105], nxt[105];

int main() {
    scanf("%lld", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%lld %lld", &brand[i], &nxt[i]);
    }

    ll count = 0;
    for(ll i = 1; i <= n; ++i) {

        bool flag = false;

        for(ll j = 1; j <= n; ++j) {
            if(brand[i] == nxt[j] && i != j) {
                flag = 1;
                break;
            }
        }

        if(!flag) count++;
    }
    printf("%lld", count);
}