#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, s;

void no() {
    printf("NO\n");
    exit(0);
}

int main() {
    scanf("%lld %lld", &n, &s);
    if(s/n < 2) no();

    printf("YES\n");
    for(ll i = 0; i < n - 1; ++i) printf("%lld ", s/n);
    printf("%lld\n1\n", (s/n) + s%n);

    return 0;
}