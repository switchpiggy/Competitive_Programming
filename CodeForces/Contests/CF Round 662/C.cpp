#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[100007];
map<ll, ll> occ;

int main() {
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld", &n);
        for(ll i = 0; i < n; ++i) {
            scanf("%lld", &a[i]);
            occ[a[i]]++;
        }

        
        printf("\n");
    }
}