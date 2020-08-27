#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, x, a[1007];

int main() {
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld %lld", &n, &x);
        ll even = 0 , odd = 0;

        for(ll i = 0; i < n; ++i) {
        	scanf("%lld", &a[i]);
            if(a[i]%2) odd++;
            else even++;
        }

        if(!odd) {
            printf("NO\n");
        } else if(x%2 == 0) {
            if(odd%2 == 0) odd--;
            if(even%2 == 0) even--;
            if(even + odd >= x) printf("YES\n");
            else printf("NO\n");
        } else {
            if(odd%2 == 0) odd--;
            if(even%2 == 1) even--;
            if(even + odd >= x) printf("YES\n");
            else printf("NO\n");
        }
    }

    return 0;
}