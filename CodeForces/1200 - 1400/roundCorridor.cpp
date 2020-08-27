#include <bits/stdc++.h>
using namespace std;

//Solution: the only way we cannot move from one square to another is if there is a dual wall between them. Dual walls exist at k * g, where g = gcd(n, m).
//These dual walls divide the circle into sectors. To check if (sx, sy) and (ex, ey) are in the same sector, we use this formula:
// if((sy - 1)/((n or m)/g) == (ey - 1)/((n or m)/g)) they are in the same sector.
//This is because each sector in the inner circle is n/g units long, and m/g in the outer circle, since they divide the total circle into lengths of g.
//So, the sector of a certain square would be  (squareNum - 1)/((n or m)/g). Note: we subtract 1 from squareNum because at each multiple of m/g and n/g, if we do not subtract 1, it will overflow into the next sector.

typedef long long int ll;
ll n, m, q, x, y, a, b, gcf;

bool sameSector(ll x, ll y, ll a, ll b) {
    y--;
    b--;
    if(x == 1) y /= n/gcf;
    else y /= m/gcf;

    if(a == 1) b /= n/gcf;
    else b /= m/gcf;

    if(y == b) return 1;
    return 0;
}

int main() {
    scanf("%lld %lld %lld", &n, &m, &q);
    gcf = __gcd(n, m);
    for(ll i = 0; i < q; ++i) {
        scanf("%lld %lld %lld %lld", &x, &y, &a, &b);
        if(sameSector(x, y, a, b)) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}