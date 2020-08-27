#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
ll n;
 
int main() {
    scanf("%lld", &n);
 
    ll cur = 1;
    ll ans = 0;
 
    while(1) {
        if(n > 0) ans++;
        else break;
        n -= cur;
        cur *= 2;
    }
 
    printf("%lld\n", ans);
    return 0;
}