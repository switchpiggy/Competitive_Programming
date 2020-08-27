#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b, c, curA, curB, curC;

int main() {
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    scanf("%lld %lld %lld %lld %lld %lld", &a, &curA, &b, &curB, &c, &curC);

    for(ll i = 0; i < 100; ++i) {
        if(i%3 == 0) {
            ll cur = min(curA, b - curB);
            curA -= cur;
            curB += cur;
        } else if(i%3 == 1) {
            ll cur = min(curB, c - curC);
            curB -= cur;
            curC += cur;
        } else {
            ll cur = min(curC, a - curA);
            curC -= cur;
            curA += cur;
        }
    }

    printf("%lld\n%lld\n%lld\n", curA, curB, curC);
}