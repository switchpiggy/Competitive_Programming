#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, m;


int main() {
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld %lld", &n, &m);
        printf("%lld\n", min(min(n, m), (n + m)/3));

    }

}