#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x, y, xt, yt, res;
map<pair<ll, ll>, bool> vis;

int main() {
    scanf("%lld %lld %lld", &n, &x, &y);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld %lld", &xt, &yt);
        xt -= x;
        yt -= y;
        ll gcf = __gcd(xt, yt);
        xt /= gcf, yt /= gcf;
        res += !(vis[make_pair(xt, yt)]);
        vis[make_pair(xt, yt)] = 1;
    }

    printf("%lld\n", res);
    return 0;
}