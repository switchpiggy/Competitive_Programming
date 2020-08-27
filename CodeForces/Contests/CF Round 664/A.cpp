#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, r, g, b, w;

int main() {
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld %lld %lld %lld", &r, &g, &b, &w);
        ll even = 0, odd = 0;
        if(r%2) odd++;
        else even++;
        if(g%2) odd++;
        else even++;
        if(w%2) odd++;
        else even++;
        if(b%2) odd++;
        else even++;

        if(even >= 3) {
            printf("Yes\n");
            continue;
        }

        r--;
        g--;
        b--;
        w++;

        if(r < 0 || g < 0 || b < 0) {
            printf("No\n");
            continue;
        }

        odd = 0, even = 0;

        if(r%2) odd++;
        else even++;
        if(g%2) odd++;
        else even++;
        if(b%2) odd++;
        else even++;
        if(w%2) odd++;
        else even++;

        if(even >= 3) {
            printf("Yes\n");
        } else printf("No\n");
    }
}