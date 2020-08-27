#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, a, b, n, m;

int main() {
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld %lld %lld %lld", &a, &b, &n, &m);
        if(a + b >= n + m && m <= min(a, b)) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}