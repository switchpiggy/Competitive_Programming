#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

bool check(ll k) {
    ll cur = n, res = 0;

    while(cur > 0) {
        ll diff = min(cur, k);
        cur -= diff;
        res += diff;
        cur -= cur/10;
    }

    return res * 2 >= n;
}

int main() {
    scanf("%lld", &n);

    ll l = 1, r = n, ans = n + 1;

    while(l <= r) {
        ll k = (l + r)/2;
        if(check(k)) {
            ans = k;
            r = k - 1;
        } else {
            l = k + 1;
        }
    }

    printf("%lld", ans);    
}