#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
ll t, n, a[1007];
 
int main() {
    scanf("%lld", &t);
 
    while(t--) {
        scanf("%lld", &n);
        for(ll i = 0; i < n; ++i) scanf("%lld", &a[i]);
 
        ll even = 0, odd = 0;
        for(ll i = 0; i < n; ++i) {
            if(i%2 == 0 && a[i]%2 == 1) even++;
            else if(i%2 == 1 && a[i]%2 == 0) odd++;
        }
 
        if(even != odd) printf("-1\n");
        else printf("%lld\n", even);
    }

    return 0;
}