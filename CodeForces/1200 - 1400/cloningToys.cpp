#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll x, y;

int main() {
    scanf("%lld %lld", &x, &y);
    if(y - 1 > x || (abs(y - x - 1)%2 == 1) || y == 0 || (y <= 1 && x > 0)) printf("NO\n");
    else printf("YES\n");
}