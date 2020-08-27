#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, k, l;

int main() {
    cin >> n >> m >> k >> l;
    ll x = ((k + l) + m - 1)/m;
    if(x * m > n) printf("-1\n");
    else printf("%lld\n", x);

    return 0;
}