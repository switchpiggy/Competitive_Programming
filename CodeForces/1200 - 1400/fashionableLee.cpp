#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, t;

int main() {
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld", &n);
        if(n%4) printf("NO\n");
        else printf("YES\n");
    }

    return 0;
}