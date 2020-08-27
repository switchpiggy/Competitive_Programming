#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m;
int main() {
    scanf("%lld %lld", &n, &m);
    ll maxs = max(n, m) - 1;

    printf("%lld %lld\n", maxs, m + n - maxs - 1);
}