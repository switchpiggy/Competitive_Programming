#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll x, y;

int main() {
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);

    scanf("%lld %lld", &x, &y);

    ll cur = 1;
    ll ans = 0;

    while(x != y) {
        if((cur > 0 && x <= y && y <= x + cur) || (cur < 0 && y <= x && y >= x + cur)) {
            ans += abs(y - x);
            break;
        }
        //cout << curX << endl;
        ans += abs(cur) * 2;
        cur *= -2;
    }

    printf("%lld\n", ans);
    
    return 0;
}