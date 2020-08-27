#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll  t, n, a[100007];

int main() {
    scanf("%lld", &t);
    while(t--) {
       scanf("%lld", &n);
       ll cnt = 0;
       for(ll i = 0; i < n; ++i) scanf("%lld", &a[i]);

       while(cnt < n && a[cnt] == 1) {
           cnt++;
       }

        if((cnt == n && cnt%2 == 0) || (cnt < n && cnt%2 == 1)) printf("Second\n");
        else printf("First\n");
    }

    return 0;
}