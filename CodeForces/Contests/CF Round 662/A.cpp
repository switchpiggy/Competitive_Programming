#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;

int main() {
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld", &n);
        printf("%lld\n", n/2 + 1);
    }

    return 0;
}