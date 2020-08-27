#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll solve(ll x, ll normal, ll final) {

    ll total = 1;
    x -= final;
    total += (x + normal - 1)/normal;

    return total;

}

int main() {

    ll q;
    scanf("%lld", &q);
    while(q--) {
        ll norm = INT_MIN, fin = INT_MIN, n, x;
        scanf("%lld %lld", &n, &x);
        for(ll i = 0; i < n; ++i) {
            ll d, h;
            scanf("%lld %lld", &d, &h);
            norm = max(norm, d - h);
            fin = max(fin, d);
        }
        if(fin >= x) printf("1\n");
        else if(norm <= 0) printf("-1\n");
        else printf("%lld\n", solve(x, norm, fin));
    }

}