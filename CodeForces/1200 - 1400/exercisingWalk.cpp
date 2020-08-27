#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    ll t, x, y, x1, y1, x2, y2, a,b, c, d;
    scanf("%lld", &t);
    
    while(t--) {
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        scanf("%lld %lld %lld %lld %lld %lld", &x, &y, &x1, &y1, &x2, &y2);

        x += b - a;
        y += d - c;

        if(a + b && x1 == x2) printf("NO\n");
        else if(c + d && y1 == y2) printf("NO\n");
        else if(x1 <= x && x <= x2 && y1 <= y && y <= y2) printf("YES\n");
        else printf("NO\n");
    }
}