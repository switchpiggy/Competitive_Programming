#include <bits/stdc++.h>
using namespace std;

//Solution: instead of simulating, we calculate the time taken for each present by dividing the problem into cases.
//Case 1: lst > cur --> in this case, we add one because it is possible for cur to be moved to the top in lst operation
//Case 2: lst < cur --> in this case, we add 2 * (pos[cur] - 1) since we will have to manually take out the top pos[cur] - 1 presents and put them back.

typedef long long int ll;
ll t, n, m, a[100007], b[100007];

int main() {
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld %lld", &n, &m);
        for(ll i = 0; i < n; ++i) {
            ll temp;
            scanf("%lld", &temp);
            a[temp] = i + 1;
        }
        for(ll i = 1; i <= m; ++i) scanf("%lld", &b[i]);

        ll maxn = -1, res = m;
        for(ll i = 1; i <= m; ++i) {
            if(a[b[i]] > maxn) {
                res += 2 * (a[b[i]] - i);
                maxn = a[b[i]];
            } 
        } 
    
        printf("%lld\n", res);
    }

    return 0;
}